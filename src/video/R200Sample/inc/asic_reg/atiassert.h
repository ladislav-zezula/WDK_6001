#ifndef _ATIASSERT_
#define _ATIASSERT_

extern BOOLEAN BreakOnAssert;

#if DBG
    #undef ASSERT

    #ifdef _PREFAST_
        __declspec(noreturn) void  die(__in  char* pDbgMsg);  // noreturn function

        #define ASSERT( exp )                                                        \
            {                                                                        \
	        ((BreakOnAssert) ?                                                       \
                (ASSERTMSG("Break on assertion enabled.\n", exp)) :                  \
                ((!(exp)) ? (KdPrint(("*******ASSERTION BREAK*******\n")), die("no return")) : TRUE)); \
            }
    #else
        #define ASSERT( exp )                                                        \
            {                                                                        \
	        ((BreakOnAssert) ?                                                       \
                (ASSERTMSG("Break on assertion enabled.\n", exp)) :                  \
                ((!(exp)) ? (KdPrint(("*******ASSERTION BREAK*******\n"))) : TRUE)); \
            }
    #endif

#endif

#endif

