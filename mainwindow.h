#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QFileDialog>

#include "aos_log.h"
#include "aos_util.h"
#include "aos_string.h"
#include "aos_status.h"
#include "oss_auth.h"
#include "oss_util.h"
#include "oss_api.h"

/*
const char OSS_ENDPOINT[] = "<your endpoint>";
const char ACCESS_KEY_ID[] = "<your access key id>";
const char ACCESS_KEY_SECRET[] = "<your access key secret>";
const char BUCKET_NAME[] = "<your bucket name>";
const char OBJECT_NAME[] = "<your object key>";
*/

const char OSS_ENDPOINT[] = "oss-cn-shenzhen.aliyuncs.com";
const char ACCESS_KEY_ID[] = "LTAIFmi3ZKuGxRhw";
const char ACCESS_KEY_SECRET[] = "h40ul1ExbpS2rkWnfsxgY0Kbvot1L4";
const char BUCKET_NAME[] = "nofly";
const char OBJECT_NAME[] = "indexb.html";

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_selectBtn_clicked();
    void on_loadBtn_clicked();

private:
    Ui::MainWindow *ui;

    bool _isUpload;

    void init();

    QByteArray readFile(QString path);

    void yee_upload_project();
    void init_sample_request_options(oss_request_options_t *options, int is_cname);
    void put_object_from_buffer();
    void put_object_from_file();
    void get_object_to_buffer();
    void get_object_to_file();
    void delete_object();

    QString _fileFullPath;// F:/Yee.zip
    QString _filePath;    // F:/
    QString _fileName;    // Yee.zip
};

#endif // MAINWINDOW_H
