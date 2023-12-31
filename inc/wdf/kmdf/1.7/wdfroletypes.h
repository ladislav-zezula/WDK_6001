#ifndef _WDFROLETYPES_H_
#define _WDFROLETYPES_H_

#define SAL_WDF_DEVICE_CONTEXT_CLEANUP              __drv_dispatchType(SAL_WDF_DEVICE_CONTEXT_CLEANUP)
#define SAL_WDF_DEVICE_CONTEXT_DESTROY              __drv_dispatchType(SAL_WDF_DEVICE_CONTEXT_DESTROY)
#define SAL_WDF_IO_QUEUE_CONTEXT_CLEANUP_CALLBACK   __drv_dispatchType(SAL_WDF_IO_QUEUE_CONTEXT_CLEANUP_CALLBACK)
#define SAL_WDF_IO_QUEUE_CONTEXT_DESTROY_CALLBACK   __drv_dispatchType(SAL_WDF_IO_QUEUE_CONTEXT_DESTROY_CALLBACK)
#define SAL_WDF_FILE_CONTEXT_CLEANUP_CALLBACK       __drv_dispatchType(SAL_WDF_FILE_CONTEXT_CLEANUP_CALLBACK)
#define SAL_WDF_FILE_CONTEXT_DESTROY_CALLBACK       __drv_dispatchType(SAL_WDF_FILE_CONTEXT_DESTROY_CALLBACK)

typedef SAL_WDF_DEVICE_CONTEXT_CLEANUP              EVT_WDF_OBJECT_CONTEXT_CLEANUP EVT_WDF_DEVICE_CONTEXT_CLEANUP;
typedef SAL_WDF_DEVICE_CONTEXT_DESTROY              EVT_WDF_OBJECT_CONTEXT_DESTROY EVT_WDF_DEVICE_CONTEXT_DESTROY;
typedef SAL_WDF_IO_QUEUE_CONTEXT_CLEANUP_CALLBACK   EVT_WDF_OBJECT_CONTEXT_CLEANUP EVT_WDF_IO_QUEUE_CONTEXT_CLEANUP_CALLBACK;
typedef SAL_WDF_IO_QUEUE_CONTEXT_DESTROY_CALLBACK   EVT_WDF_OBJECT_CONTEXT_DESTROY EVT_WDF_IO_QUEUE_CONTEXT_DESTROY_CALLBACK;
typedef SAL_WDF_FILE_CONTEXT_CLEANUP_CALLBACK       EVT_WDF_OBJECT_CONTEXT_CLEANUP EVT_WDF_FILE_CONTEXT_CLEANUP_CALLBACK;
typedef SAL_WDF_FILE_CONTEXT_DESTROY_CALLBACK       EVT_WDF_OBJECT_CONTEXT_DESTROY EVT_WDF_FILE_CONTEXT_DESTROY_CALLBACK;

#endif // _WDFROLETYPES_H_

