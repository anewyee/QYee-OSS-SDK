# Qt客户端阿里云服上传文件

整体原理：

阿里云提供了c程序上传文件到阿里云服务器的sdk工具包，将这个工具包继承在自己的客户端，调用接口即可实现上传文件。

前期准备：

1、阿里云c程序客户端的sdk，下载地址：https://help.aliyun.com/document_detail/32131.html?spm=5176.doc32139.6.768.JIh6Dh （如果地址不对，可以在阿里云的帮助文档中找）

2、安装vs2010或以上版本，目的是为了编译生成oss_c_sdk.lib静态链接库

 

操作步骤：

1、将下载的文件解压并用vs2010打开，编译生成oss_c_sdk.lib文件（帮助文档有详细方法） 

[aliyun-oss-c-sdk-sample.zip](http://docs-aliyun.cn-hangzhou.oss.aliyun-inc.com/assets/attach/32132/cn_zh/1487730523734/aliyun-oss-c-sdk-sample.zip?spm=a2c4g.11186623.2.16.urDWjs&file=aliyun-oss-c-sdk-sample.zip)

2、将oss_c_sdk目录下的头文件（.h）放在自己工程的源代码目录下，并在工程中添加这些源文件 

3、在pro文件中添加库文件

```
LIBS += -lWS2_32 \
        $$PWD/third_party/lib/Release/oss_c_sdk.lib
```
其中，

ws2_32是vs库中的文件，（我是win32下的程序，如果不是win32的程序，不用加）

oss_c_sdk可以自己放在合适的目录下，在pro中添加路径即可 

4、将所下载文件的third_party/include下的头文件放在源代码目录下，并在pro文件中引用相应目录

```
INCLUDEPATH += third_party/include \
        third_party/include/apr \
        third_party/include/mxml \
        third_party/include/aprutil
```
这些文件是oss_c_sdk目录下的头文件需要引用的

**重要一条：**
5、将third_party\lib\Release下的**dll放在项目的bin目录下**，即exe所在目录，否则不能运行

出现：Qt 程序debug时提示：The CDB process terminated

6、参照所下载示例中的代码，即可完成文件上传，示例代码如下：


```
int main(int argc, char *argv[])
{
    if (aos_http_io_initialize(NULL, 0) != AOSE_OK) {
        exit(1);
    }

    put_object_sample();
    append_object_sample();
    get_object_sample();
    head_object_sample();
    multipart_object_sample();
    delete_object_sample();
    aos_http_io_deinitialize();
    system("pause");

    return 0;
}
```
 

注意事项：

1、win32一定要加上-lWS2_32否则编译不通过

2、注意要调用aos_http_io_initialize与aos_http_io_deinitialize函数，否则联网不成功

3、对于QString转换为char*的解决代码如下：

```
QString sMyfilename = "c:\test.c";
QByteArray byteArray_filename = sMyfilename.toLatin1();
char* pchar_filename = new char[byteArray_filename.size() + 1];
strcpy(pchar_filename, byteArray_filename.data());
```

4、第三方库要用release目录下的dll，否则会有问题，debug目录下的反正没用过。

 

总结：

可以仔细阅读下阿里云的帮助文档，其中有很多源码和解决方案，很详细。

# 阿里云c-SDK解析

- 参考文献：[Visual Studio示例工程](https://help.aliyun.com/document_detail/32132.html?spm=a2c4g.11186623.6.794.YiaJQl)

- 示例工程 : [aliyun-oss-c-sdk-sample.zip](http://docs-aliyun.cn-hangzhou.oss.aliyun-inc.com/assets/attach/32132/cn_zh/1487730523734/aliyun-oss-c-sdk-sample.zip?spm=a2c4g.11186623.2.16.urDWjs&file=aliyun-oss-c-sdk-sample.zip)

- GitHub地址：[GitHub](https://github.com/baiyubin/aliyun-oss-c-sdk-sample?spm=a2c4g.11186623.2.17.urDWjs)

## 揭秘Sample工程

OSS C SDK Sample工程是怎么做出来的呢？VS2008、VS2010、VS2012、VS2013、VS2015的做法基本相同，下面以VS2012为例说明。

准备库和头文件。准备SDK库/头文件，第三方库/头文件。合并SDK库/头文件、第三方库/头文件，结果为oss-c-sdk-sampleoss-c-sdk目录。oss-c-sdk目录直接放在工程目录下。

配置头文件路径。在路径 Solution Explorer -> oss-c-sdk-sample -> Property -> Configuration Properties -> VC++ Directories -> Include Directories，添加如下配置：

```
..\oss-c-sdk\include
..\oss-c-sdk\include\apr
..\oss-c-sdk\include\aprutil
..\oss-c-sdk\include\curl
..\oss-c-sdk\include\mxml
..\oss-c-sdk\include\sdk
```

配置库路径。在路径 oss-c-sdk-sample -> Property -> Configuration Properties -> Linker -> General -> Additional Library Directories，添加 

```
..\oss-c-sdk\lib\Release
```

配置库。在路径 oss-c-sdk-sample -> Property -> Configuration Properties -> Linker -> Input -> Additional Dependencies，添加如下配置：

```
libapr-1.lib
libaprutil-1.lib
curl.lib
mxml1.lib
oss_c_sdk.lib
ws2_32.lib
```

如果您想从一个空工程开始编写自己的程序，或者在已有的工程中使用OSS C SDK，请参考Sample工程的配置方法。