#ifndef _DX_QS_EMU_H_
#define _DX_QS_EMU_H_

#if defined(RADEON_EMULATOR)

#define _DEFAULT_SLEEP
#define QS_EMU
//#include "QsEmu.h"

////////////////////////////////////////////////////////////////////////
// DxQsEmuCheckCaps()
////////////////////////////////////////////////////////////////////////
__inline BOOL DxQsEmuCheckCaps(DWORD dwCaps)
{
    if (dwCaps & QS_CAPS_QSEMU)
    { return TRUE; }
    else
    { return FALSE; }
}

////////////////////////////////////////////////////////////////////////
// DxQsEmuRegisterClient()
////////////////////////////////////////////////////////////////////////
__inline BOOL DxQsEmuRegisterClient(QS_HCLIENT hClient, QS_FUNC *pQS_APIFunc)
{
    QS_DEBUG qsDebug;
    QS_RETURNCODE a;

    qsDebug.dwSize     = sizeof(QS_DEBUG);
    qsDebug.hClient    = hClient;
    qsDebug.dwDebug    = QS_DEBUG_QSEMU_REGISTER_CLIENT;
    qsDebug.dwQSEMU_Version = QSEMU_REV_CHAPLIN;
    a = pQS_APIFunc->QSDebug(&qsDebug);
    if (QS_OK == a)//pQS_APIFunc->QSDebug(&qsDebug))
    { return TRUE; }
    else
    { return FALSE; }

}


#else // if defined (RADEON_EMULATOR)

#define DxQsEmuCheckCaps(dwCaps) TRUE
#define DxQsEmuRegisterClient(hClient, pQS_APIFunc)  TRUE

#endif // if defined (RADEON_EMULATOR)

#endif // _DX_QS_EMU_H_
