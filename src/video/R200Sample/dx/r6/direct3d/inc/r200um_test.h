#pragma once

struct TESTDRIVERREGISTRY {
    BOOL bDisableRenderCB;
    BOOL bDisableFlushInLock;
    BOOL bEnableDuplicateDeviceHandle;
    BOOL bEnableFPUCorruption;
    BOOL bIgnoreRenderCallbackHR;
    BOOL bIgnorePresentCallbackHR;
    BOOL bIgnoreLockCallbackHR;
    BOOL bIgnoreUnlockCallbackHR;
    BOOL bIgnoreAllocateCallbackHR;
    BOOL bIgnoreDeallocateCallbackHR;
    BOOL bLeakMemoryOnDestroyResource;
    BOOL bEnableDoubleUnlock;
    BOOL bAlterD3DDDIARG_LOCK;
    BOOL bAlterD3DDDIARG_CREATERESOURCE;
    BOOL bWritePastD3DDDIARG;
    BOOL bReturnNonUniqueHandle;
};
