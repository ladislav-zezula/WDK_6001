#ifndef _DEBUG_H_
#define _DEBUG_H_

#ifdef __cplusplus
extern "C" 
{
#endif


extern BOOL BreakOnAssert;


#if DBG
#define DBG_BREAK if (BreakOnAssert) {DebugBreak();};
#else
#define DBG_BREAK / ## /
#endif 

#ifdef __cplusplus
}
#endif

#endif  // _DEBUG_H_

