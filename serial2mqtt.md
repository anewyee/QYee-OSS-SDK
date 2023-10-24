# 协议 Protocol
Example : [1,"mytopic","3.141592653"]
```
[<COMMAND>,<TOPIC>,<MESSAGE>,<QOS>,<RETAIN>,<CRC>] 
* QOS ,RETAIN, CRC 三项保留可选
<CRC> : can be checked or not, is calculated on the total JSON string based on the message containing "0000" as temporary CRC. When calculated is in HEX format.
* COMMAND 0:SUBSCRIBE,1:PUBLISH,2:MQTT-CONN,3:MQTT-DISC
* publish : [1,"dst/topic1","message1",0,0]
* subscribe : [0,"dst/myTopic/#"]
* QOS : 0,1,2 : for QOS, default 0
* RETAIN : 0 or 1 for true or false, default 0
```
- 发布示例 publish : [1,"myTopicPi","3.141592653"]
- 订阅示例 subscribe : [0,"myTopics/#"]

## 工作流程
```mermaid
sequenceDiagram
participant EmbeddedSystem
participant serial2mqtt
participant MQTT Broker

activate serial2mqtt
serial2mqtt-->>EmbeddedSystem: open serial port tty
serial2mqtt-->>MQTT Broker: connect(broker,port)
serial2mqtt-->>EmbeddedSystem: [1,"SOMETHING","SOMETHING",2]   replaying saved local persistence messages even before the MQTT connection establishment
MQTT Broker -->> serial2mqtt: connAck 判定是否连接成功
serial2mqtt-->>EmbeddedSystem: [2,"DEVICE",""]
EmbeddedSystem->> serial2mqtt: [0,"uapx/device_sn/mav"]
EmbeddedSystem->> serial2mqtt : [1,"uapx/device_sn/replay_mav"]
deactivate serial2mqtt

activate serial2mqtt
serial2mqtt-->>MQTT Broker: subscribe("uapx/device_sn/replay_mav")
serial2mqtt-->>MQTT Broker: publish("uapx/device_sn/mav","true")
MQTT Broker-->>serial2mqtt: publish("uapx/device_sn/replay_mav","true")
serial2mqtt-->>EmbeddedSystem : [1,"dst/DEVICE/system/loopback","true"]
deactivate serial2mqtt

activate serial2mqtt
EmbeddedSystem->> serial2mqtt : [1,"dst/DEVICE/system/loopback","true"]
serial2mqtt-->>MQTT Broker: publish("dst/DEVICE/system/loopback","true")
MQTT Broker-->>serial2mqtt: publish("dst/DEVICE/system/loopback","true")
serial2mqtt-->>EmbeddedSystem : [1,"dst/DEVICE/system/loopback","true"]
deactivate serial2mqtt

Note right of Embedded: no more messages after 5 sec, 
Note right of Embedded: serial2mqtt disconnects serial port and tries to reconnect. MQTT connection always open.
serial2mqtt-->>EmbeddedSystem: close serial port tty
serial2mqtt-->>EmbeddedSystem: open serial port

Note right of Embedded: when serial2mqtt gets diconnected from the MQTT broker:
MQTT Broker-->>serial2mqtt: disconnects
serial2mqtt-->>EmbeddedSystem: [3,"",""]
serial2mqtt-->>MQTT Broker: connect(broker,port)
MQTT Broker -->> serial2mqtt: connAck
serial2mqtt-->>EmbeddedSystem: [2,"DEVICE",""]
```

# Programming through serial2mqtt
A command line utility will send a single mqtt request to the serial2mqtt gateway to program the microcontroller.
```mermaid
sequenceDiagram
participant µC
participant serial2mqtt
participant MQTT Broker
participant programmer CLI
programmer CLI -x MQTT Broker: PUBLISH("dst/drive/serial2mqtt/flash",flash image binary)
MQTT Broker ->> serial2mqtt : PUBLISH
activate serial2mqtt
serial2mqtt ->> µC : program flash image
serial2mqtt ->> MQTT Broker : PUBLISH(logs)
MQTT Broker ->> programmer CLI : logs
µC ->> serial2mqtt : startup logs
serial2mqtt ->> MQTT Broker : logs
MQTT Broker ->> programmer CLI : logs
µC ->> serial2mqtt : MQTT Pub
deactivate serial2mqtt
```
