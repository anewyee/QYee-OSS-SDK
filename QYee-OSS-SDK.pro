#-------------------------------------------------
#
# Project created by QtCreator 2018-02-11T17:09:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QYee-OSS-SDK
TEMPLATE = app


LIBS += -lWS2_32 \
        $$PWD/oss-c-sdk/lib/Release/oss_c_sdk.lib

INCLUDEPATH += oss-c-sdk/include \
        oss-c-sdk/include/apr \
        oss-c-sdk/include/mxml \
        oss-c-sdk/include/aprutil \
        oss-c-sdk/include/sdk

SOURCES += main.cpp\
        mainwindow.cpp \
    src/oss_put_object_sample.c \
    src/oss_config.c \
    src/oss_sample_util.c

HEADERS  += mainwindow.h \
    oss-c-sdk/include/apr/arch/aix/apr_arch_dso.h \
    oss-c-sdk/include/apr/arch/beos/apr_arch_dso.h \
    oss-c-sdk/include/apr/arch/beos/apr_arch_proc_mutex.h \
    oss-c-sdk/include/apr/arch/beos/apr_arch_thread_cond.h \
    oss-c-sdk/include/apr/arch/beos/apr_arch_thread_mutex.h \
    oss-c-sdk/include/apr/arch/beos/apr_arch_thread_rwlock.h \
    oss-c-sdk/include/apr/arch/beos/apr_arch_threadproc.h \
    oss-c-sdk/include/apr/arch/netware/apr_arch_dso.h \
    oss-c-sdk/include/apr/arch/netware/apr_arch_file_io.h \
    oss-c-sdk/include/apr/arch/netware/apr_arch_global_mutex.h \
    oss-c-sdk/include/apr/arch/netware/apr_arch_internal_time.h \
    oss-c-sdk/include/apr/arch/netware/apr_arch_networkio.h \
    oss-c-sdk/include/apr/arch/netware/apr_arch_pre_nw.h \
    oss-c-sdk/include/apr/arch/netware/apr_arch_proc_mutex.h \
    oss-c-sdk/include/apr/arch/netware/apr_arch_thread_cond.h \
    oss-c-sdk/include/apr/arch/netware/apr_arch_thread_mutex.h \
    oss-c-sdk/include/apr/arch/netware/apr_arch_thread_rwlock.h \
    oss-c-sdk/include/apr/arch/netware/apr_arch_threadproc.h \
    oss-c-sdk/include/apr/arch/netware/apr_private.h \
    oss-c-sdk/include/apr/arch/os2/apr_arch_dso.h \
    oss-c-sdk/include/apr/arch/os2/apr_arch_file_io.h \
    oss-c-sdk/include/apr/arch/os2/apr_arch_inherit.h \
    oss-c-sdk/include/apr/arch/os2/apr_arch_networkio.h \
    oss-c-sdk/include/apr/arch/os2/apr_arch_os2calls.h \
    oss-c-sdk/include/apr/arch/os2/apr_arch_proc_mutex.h \
    oss-c-sdk/include/apr/arch/os2/apr_arch_thread_cond.h \
    oss-c-sdk/include/apr/arch/os2/apr_arch_thread_mutex.h \
    oss-c-sdk/include/apr/arch/os2/apr_arch_thread_rwlock.h \
    oss-c-sdk/include/apr/arch/os2/apr_arch_threadproc.h \
    oss-c-sdk/include/apr/arch/os390/apr_arch_dso.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_atomic.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_dso.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_file_io.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_global_mutex.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_inherit.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_internal_time.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_misc.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_networkio.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_poll_private.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_proc_mutex.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_shm.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_thread_cond.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_thread_mutex.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_thread_rwlock.h \
    oss-c-sdk/include/apr/arch/unix/apr_arch_threadproc.h \
    oss-c-sdk/include/apr/arch/win32/apr_arch_atime.h \
    oss-c-sdk/include/apr/arch/win32/apr_arch_dso.h \
    oss-c-sdk/include/apr/arch/win32/apr_arch_file_io.h \
    oss-c-sdk/include/apr/arch/win32/apr_arch_inherit.h \
    oss-c-sdk/include/apr/arch/win32/apr_arch_misc.h \
    oss-c-sdk/include/apr/arch/win32/apr_arch_networkio.h \
    oss-c-sdk/include/apr/arch/win32/apr_arch_proc_mutex.h \
    oss-c-sdk/include/apr/arch/win32/apr_arch_thread_cond.h \
    oss-c-sdk/include/apr/arch/win32/apr_arch_thread_mutex.h \
    oss-c-sdk/include/apr/arch/win32/apr_arch_thread_rwlock.h \
    oss-c-sdk/include/apr/arch/win32/apr_arch_threadproc.h \
    oss-c-sdk/include/apr/arch/win32/apr_arch_utf8.h \
    oss-c-sdk/include/apr/arch/win32/apr_dbg_win32_handles.h \
    oss-c-sdk/include/apr/arch/win32/apr_private.h \
    oss-c-sdk/include/apr/arch/apr_private_common.h \
    oss-c-sdk/include/apr/apr.h \
    oss-c-sdk/include/apr/apr_allocator.h \
    oss-c-sdk/include/apr/apr_atomic.h \
    oss-c-sdk/include/apr/apr_dso.h \
    oss-c-sdk/include/apr/apr_env.h \
    oss-c-sdk/include/apr/apr_errno.h \
    oss-c-sdk/include/apr/apr_escape.h \
    oss-c-sdk/include/apr/apr_escape_test_char.h \
    oss-c-sdk/include/apr/apr_file_info.h \
    oss-c-sdk/include/apr/apr_file_io.h \
    oss-c-sdk/include/apr/apr_fnmatch.h \
    oss-c-sdk/include/apr/apr_general.h \
    oss-c-sdk/include/apr/apr_getopt.h \
    oss-c-sdk/include/apr/apr_global_mutex.h \
    oss-c-sdk/include/apr/apr_hash.h \
    oss-c-sdk/include/apr/apr_inherit.h \
    oss-c-sdk/include/apr/apr_lib.h \
    oss-c-sdk/include/apr/apr_mmap.h \
    oss-c-sdk/include/apr/apr_network_io.h \
    oss-c-sdk/include/apr/apr_poll.h \
    oss-c-sdk/include/apr/apr_pools.h \
    oss-c-sdk/include/apr/apr_portable.h \
    oss-c-sdk/include/apr/apr_proc_mutex.h \
    oss-c-sdk/include/apr/apr_random.h \
    oss-c-sdk/include/apr/apr_ring.h \
    oss-c-sdk/include/apr/apr_shm.h \
    oss-c-sdk/include/apr/apr_signal.h \
    oss-c-sdk/include/apr/apr_skiplist.h \
    oss-c-sdk/include/apr/apr_strings.h \
    oss-c-sdk/include/apr/apr_support.h \
    oss-c-sdk/include/apr/apr_tables.h \
    oss-c-sdk/include/apr/apr_thread_cond.h \
    oss-c-sdk/include/apr/apr_thread_mutex.h \
    oss-c-sdk/include/apr/apr_thread_proc.h \
    oss-c-sdk/include/apr/apr_thread_rwlock.h \
    oss-c-sdk/include/apr/apr_time.h \
    oss-c-sdk/include/apr/apr_user.h \
    oss-c-sdk/include/apr/apr_version.h \
    oss-c-sdk/include/apr/apr_want.h \
    oss-c-sdk/include/aprutil/private/apr_crypto_internal.h \
    oss-c-sdk/include/aprutil/private/apr_dbd_internal.h \
    oss-c-sdk/include/aprutil/private/apr_dbd_odbc_v2.h \
    oss-c-sdk/include/aprutil/private/apr_dbm_private.h \
    oss-c-sdk/include/aprutil/private/apu_config.h \
    oss-c-sdk/include/aprutil/private/apu_internal.h \
    oss-c-sdk/include/aprutil/private/apu_select_dbm.h \
    oss-c-sdk/include/aprutil/apr_anylock.h \
    oss-c-sdk/include/aprutil/apr_base64.h \
    oss-c-sdk/include/aprutil/apr_buckets.h \
    oss-c-sdk/include/aprutil/apr_crypto.h \
    oss-c-sdk/include/aprutil/apr_date.h \
    oss-c-sdk/include/aprutil/apr_dbd.h \
    oss-c-sdk/include/aprutil/apr_dbm.h \
    oss-c-sdk/include/aprutil/apr_hooks.h \
    oss-c-sdk/include/aprutil/apr_ldap.h \
    oss-c-sdk/include/aprutil/apr_ldap_init.h \
    oss-c-sdk/include/aprutil/apr_ldap_option.h \
    oss-c-sdk/include/aprutil/apr_ldap_rebind.h \
    oss-c-sdk/include/aprutil/apr_ldap_url.h \
    oss-c-sdk/include/aprutil/apr_md4.h \
    oss-c-sdk/include/aprutil/apr_md5.h \
    oss-c-sdk/include/aprutil/apr_memcache.h \
    oss-c-sdk/include/aprutil/apr_optional.h \
    oss-c-sdk/include/aprutil/apr_optional_hooks.h \
    oss-c-sdk/include/aprutil/apr_queue.h \
    oss-c-sdk/include/aprutil/apr_reslist.h \
    oss-c-sdk/include/aprutil/apr_rmm.h \
    oss-c-sdk/include/aprutil/apr_sdbm.h \
    oss-c-sdk/include/aprutil/apr_sha1.h \
    oss-c-sdk/include/aprutil/apr_strmatch.h \
    oss-c-sdk/include/aprutil/apr_thread_pool.h \
    oss-c-sdk/include/aprutil/apr_uri.h \
    oss-c-sdk/include/aprutil/apr_uuid.h \
    oss-c-sdk/include/aprutil/apr_xlate.h \
    oss-c-sdk/include/aprutil/apr_xml.h \
    oss-c-sdk/include/aprutil/apu.h \
    oss-c-sdk/include/aprutil/apu_errno.h \
    oss-c-sdk/include/aprutil/apu_version.h \
    oss-c-sdk/include/aprutil/apu_want.h \
    oss-c-sdk/include/curl/config-win32.h \
    oss-c-sdk/include/curl/curl.h \
    oss-c-sdk/include/curl/curlbuild.h \
    oss-c-sdk/include/curl/curlrules.h \
    oss-c-sdk/include/curl/curlver.h \
    oss-c-sdk/include/curl/easy.h \
    oss-c-sdk/include/curl/mprintf.h \
    oss-c-sdk/include/curl/multi.h \
    oss-c-sdk/include/curl/stdcheaders.h \
    oss-c-sdk/include/curl/typecheck-gcc.h \
    oss-c-sdk/include/mxml/config.h \
    oss-c-sdk/include/mxml/mxml.h \
    oss-c-sdk/include/sdk/aos_buf.h \
    oss-c-sdk/include/sdk/aos_crc64.h \
    oss-c-sdk/include/sdk/aos_define.h \
    oss-c-sdk/include/sdk/aos_fstack.h \
    oss-c-sdk/include/sdk/aos_http_io.h \
    oss-c-sdk/include/sdk/aos_list.h \
    oss-c-sdk/include/sdk/aos_log.h \
    oss-c-sdk/include/sdk/aos_status.h \
    oss-c-sdk/include/sdk/aos_string.h \
    oss-c-sdk/include/sdk/aos_transport.h \
    oss-c-sdk/include/sdk/aos_util.h \
    oss-c-sdk/include/sdk/oss_api.h \
    oss-c-sdk/include/sdk/oss_auth.h \
    oss-c-sdk/include/sdk/oss_define.h \
    oss-c-sdk/include/sdk/oss_resumable.h \
    oss-c-sdk/include/sdk/oss_util.h \
    oss-c-sdk/include/sdk/oss_xml.h \
    src/oss_config.h \
    src/oss_sample_util.h

FORMS    += mainwindow.ui
