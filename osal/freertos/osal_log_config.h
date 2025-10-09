#ifndef __OSAL_LOG_CONFIG__
#define __OSAL_LOG_CONFIG__

#ifndef LIBRARY_LOG_LEVEL
    #define LIBRARY_LOG_LEVEL LOG_ERROR
#endif

#define LIBRARY_LOG_NAME "AGLX5"
//#define SdkLog(message) printf message
#define SdkLog(message) do { \
            printf message; \
    }while(0)

#endif // __OSAL_LOG_CONFIG__
