#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/oss_sample_util.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _filePath(""),
    _fileFullPath(""),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QByteArray MainWindow::readFile(QString path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray b=file.read(file.bytesAvailable());
    return b;
}

//上传文件为自己文件，读取到内存后上传
void MainWindow::yee_upload_project()
{
    _isUpload = false;
    int is_cname = 0;
    aos_pool_t *p;
    oss_request_options_t *options;
    aos_status_t *s;
    aos_table_t *headers;
    aos_table_t *resp_headers;
//        char *bucket_name = "<您的bucket名字>";
//        char *object_name = "<您的object名字>";
    aos_string_t bucket;
    aos_string_t object;

//        char *data = "object content";
//    QString sMyfilename = "object content";//文件内容
//    QByteArray byteArray_filename = sMyfilename.toLatin1();

    QByteArray byteArray_filename = readFile(_fileFullPath);
    char* data = new char[byteArray_filename.size() + 1];
    strcpy(data, byteArray_filename.data());

    aos_list_t buffer;
    aos_buf_t *content;
    aos_pool_create(&p, NULL);
    /* 创建并初始化options */
    options = oss_request_options_create(p);
    init_sample_request_options(options, is_cname);

//        init_options(options);
    /* 初始化参数 */
    const char *pOBJECT_NAME = _fileName.toStdString().data();

    aos_str_set(&object, pOBJECT_NAME);// OBJECT_NAME
    aos_str_set(&bucket, BUCKET_NAME);
    headers = aos_table_make(p, 0);
    /* 将char*类型的数据转换为oss_put_object_from_buffer接口需要的aos_list_t类型的 */
    aos_list_init(&buffer);
    content = aos_buf_pack(options->pool, data, strlen(data));
    aos_list_add_tail(&content->node, &buffer);
    /* 上传文件 */
    s = oss_put_object_from_buffer(options, &bucket, &object, &buffer, headers, &resp_headers);
    /* 判断请求是否成功 */
    if (aos_status_is_ok(s)) {
        _isUpload = true;
        qDebug()<< "put file succeeded\n";
    } else {
        _isUpload = false;
        qDebug()<< "put file failed\n";
    }
    /* 释放资源 */
    aos_pool_destroy(p);
}

void MainWindow::init_sample_request_options(oss_request_options_t *options, int is_cname)
{
    options->config = oss_config_create(options->pool);
    aos_str_set(&options->config->endpoint, OSS_ENDPOINT);
    aos_str_set(&options->config->access_key_id, ACCESS_KEY_ID);
    aos_str_set(&options->config->access_key_secret, ACCESS_KEY_SECRET);
    options->config->is_cname = is_cname;

    options->ctl = aos_http_controller_create(options->pool, 0);
}

void MainWindow::put_object_from_buffer()
{
    aos_pool_t *p = NULL;
    aos_string_t bucket;
    aos_string_t object;
    int is_cname = 0;
    aos_table_t *headers = NULL;
    aos_table_t *resp_headers = NULL;
    oss_request_options_t *options = NULL;
    aos_list_t buffer;
    aos_buf_t *content = NULL;
//    char *str = "test oss c sdk";

    QString sMyfilename = "test oss c sdk";
    QByteArray byteArray_filename = sMyfilename.toLatin1();
    char* str = new char[byteArray_filename.size() + 1];
    strcpy(str, byteArray_filename.data());


    aos_status_t *s = NULL;

    aos_pool_create(&p, NULL);
    options = oss_request_options_create(p);
    init_sample_request_options(options, is_cname);
    headers = aos_table_make(p, 1);
    apr_table_set(headers, "x-oss-meta-author", "oss");
    aos_str_set(&bucket, BUCKET_NAME);
    aos_str_set(&object, OBJECT_NAME);

    aos_list_init(&buffer);
    content = aos_buf_pack(options->pool, str, strlen(str));
    aos_list_add_tail(&content->node, &buffer);

    s = oss_put_object_from_buffer(options, &bucket, &object,
                   &buffer, headers, &resp_headers);

    if (aos_status_is_ok(s)) {
        qDebug()<<"put object from buffer succeeded\n";
//        printf("put object from buffer succeeded\n");
    } else {
        qDebug()<<"put object from buffer failed\n";
//        printf("put object from buffer failed\n");
    }

    aos_pool_destroy(p);
}

void MainWindow::put_object_from_file()
{
    aos_pool_t *p = NULL;
    aos_string_t bucket;
    aos_string_t object;
    aos_table_t *headers = NULL;
    aos_table_t *resp_headers = NULL;
    oss_request_options_t *options = NULL;

//    char *filename = __FILE__;
    QString sMyfilename = "__FILE__";
    QByteArray byteArray_filename = sMyfilename.toLatin1();
    char* filename = new char[byteArray_filename.size() + 1];
    strcpy(filename, byteArray_filename.data());

    aos_status_t *s = NULL;
    aos_string_t file;
    aos_pool_create(&p, NULL);
    /* 创建并初始化options */
    options = oss_request_options_create(p);
    init_sample_request_options(options, 0);
//    init_options(options);
    /* 初始化参数 */
    headers = aos_table_make(options->pool, 1);
//    apr_table_set(headers, OSS_CONTENT_TYPE, "image/jpeg");

    apr_table_set(headers, "x-oss-meta-author", "oss");

    aos_str_set(&bucket, BUCKET_NAME);
    aos_str_set(&object, OBJECT_NAME);
//    aos_str_set(&bucket, "<您的bucket名字>");
//    aos_str_set(&object, "<您的object名字>");
    aos_str_set(&file, filename);
    /* 上传文件 */
    s = oss_put_object_from_file(options, &bucket, &object, &file,
                                 headers, &resp_headers);
    /* 判断是否上传成功 */
    if (aos_status_is_ok(s)) {
        qDebug()<<"put object from file succeeded\n";
//        printf("put object from file succeeded\n");
    } else {
        qDebug()<<"put object from file succeeded\n";
//        printf("put object from file failed\n");
    }
    /* 释放资源*/
    aos_pool_destroy(p);
}

void MainWindow::get_object_to_buffer()
{
    aos_pool_t *p = NULL;
    aos_string_t bucket;
    aos_string_t object;
    int is_cname = 0;
    oss_request_options_t *options = NULL;
    aos_table_t *headers = NULL;
    aos_table_t *params = NULL;
    aos_table_t *resp_headers = NULL;
    aos_status_t *s = NULL;
    aos_list_t buffer;
    aos_buf_t *content = NULL;
//    char *buf = NULL;

    QString sMyfilename = NULL;
    QByteArray byteArray_filename = sMyfilename.toLatin1();
    char* buf = new char[byteArray_filename.size() + 1];
    strcpy(buf, byteArray_filename.data());

    int64_t len = 0;
    int64_t size = 0;
    int64_t pos = 0;

    aos_pool_create(&p, NULL);
    options = oss_request_options_create(p);
    init_sample_request_options(options, is_cname);
    aos_str_set(&bucket, BUCKET_NAME);
    aos_str_set(&object, OBJECT_NAME);
    aos_list_init(&buffer);

    s = oss_get_object_to_buffer(options, &bucket, &object,
                                 headers, params, &buffer, &resp_headers);

    if (aos_status_is_ok(s)) {
        qDebug()<< "get object to buffer succeeded\n";
//        printf("get object to buffer succeeded\n");
    }
    else {
        qDebug()<< "get object to buffer failed\n";
//        printf("get object to buffer failed\n");
    }

    //get buffer len
    aos_list_for_each_entry(aos_buf_t, content, &buffer, node) {
        len += aos_buf_size(content);
    }

//    buf = aos_pcalloc(p, (apr_size_t)(len + 1));
//    buf[len] = '\0';

    //copy buffer content to memory
    aos_list_for_each_entry(aos_buf_t, content, &buffer, node) {
        size = aos_buf_size(content);
        memcpy(buf + pos, content->pos, (size_t)size);
        pos += size;
    }

    aos_pool_destroy(p);
}

void MainWindow::get_object_to_file()
{
    aos_pool_t *p = NULL;
    aos_string_t bucket;
//    char *download_filename = "SouthIsland_NewZealand_New.jpg";

    QString sMyfilename = "SouthIsland_NewZealand_New.jpg";
    QByteArray byteArray_filename = sMyfilename.toLatin1();
    char* download_filename = new char[byteArray_filename.size() + 1];
    strcpy(download_filename, byteArray_filename.data());

    aos_string_t object;
    int is_cname = 0;
    oss_request_options_t *options = NULL;
    aos_table_t *headers = NULL;
    aos_table_t *params = NULL;
    aos_table_t *resp_headers = NULL;
    aos_status_t *s = NULL;
    aos_string_t file;

    aos_pool_create(&p, NULL);
    options = oss_request_options_create(p);
    init_sample_request_options(options, is_cname);
    aos_str_set(&bucket, BUCKET_NAME);
    aos_str_set(&object, OBJECT_NAME);
    headers = aos_table_make(p, 0);
    aos_str_set(&file, download_filename);

    s = oss_get_object_to_file(options, &bucket, &object, headers,
                               params, &file, &resp_headers);

    if (aos_status_is_ok(s)) {
        qDebug()<<"get object to local file succeeded\n";
        printf("get object to local file succeeded\n");
    } else {
        qDebug()<<"get object to local file failed\n";
        printf("get object to local file failed\n");
    }

    aos_pool_destroy(p);
}

void MainWindow::delete_object()
{
    aos_pool_t *p = NULL;
    aos_string_t bucket;
    aos_string_t object;
    int is_cname = 0;
    oss_request_options_t *options = NULL;
    aos_table_t *resp_headers = NULL;
    aos_status_t *s = NULL;

    aos_pool_create(&p, NULL);
    options = oss_request_options_create(p);
    init_sample_request_options(options, is_cname);
    aos_str_set(&bucket, BUCKET_NAME);
    aos_str_set(&object, OBJECT_NAME);

    s = oss_delete_object(options, &bucket, &object, &resp_headers);

    if (aos_status_is_ok(s)) {
        qDebug()<< "delete object succeed\n";
        printf("delete object succeed\n");
    } else {
        qDebug()<< "delete object failed\n";

        printf("delete object failed\n");
    }

    aos_pool_destroy(p);
}

void MainWindow::on_selectBtn_clicked()
{

    QFileInfo fi;
    _fileFullPath = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Any files (*)"));
    fi = QFileInfo(_fileFullPath);
    _fileName = fi.fileName();
    _filePath = fi.absolutePath();

    ui->lineEdit->setText(_fileFullPath);
    qDebug()<< _fileFullPath << _filePath << _fileName;
}

void MainWindow::init()
{
    apr_file_t *output = NULL;
    aos_pool_t *pool = NULL;
    apr_status_t ret;

    // initialize http io system, call it olny once
    if (aos_http_io_initialize(NULL, 0) != AOSE_OK) {
        exit(1);
    }

    aos_pool_create(&pool, NULL);

    // open log file
    ret = apr_file_open(&output, "oss-c-sdk-sample.log", APR_FOPEN_CREATE | APR_FOPEN_WRITE | APR_FOPEN_APPEND, APR_OS_DEFAULT, pool);
    if (APR_SUCCESS != ret) {
        exit(1);
    }

    // set log file
    aos_log_set_output(output);
    // set log level
    aos_log_set_level(AOS_LOG_INFO);

    aos_info_log("start");

    // run samples
//    put_object_from_buffer();
//    put_object_from_file();
//    get_object_to_buffer();
//    get_object_to_file();
//    delete_object();
    yee_upload_project();

    // close log file
    apr_file_close(output);

    aos_pool_destroy(pool);

    // deinitialize http io system, call it olny once
    aos_http_io_deinitialize();

//    system("pause");
}

void MainWindow::on_loadBtn_clicked()
{
    init();
}
