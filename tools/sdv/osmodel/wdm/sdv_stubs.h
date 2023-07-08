/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

#ifndef SDV_STUBS_H
#define SDV_STUBS_H

void sdv_do_assert_check(int exp);
void sdv_do_paged_code_check(); 
void sdv_stub_driver_init();
void sdv_stub_completion_begin(PIRP pirp);
void sdv_stub_completion_end(PIRP pirp);
void sdv_stub_PowerQuery();
void sdv_stub_PowerUpOrDown();
void sdv_stub_dpc_begin();
void sdv_stub_dpc_end();
void sdv_stub_isr_begin();
void sdv_stub_isr_end();
void sdv_stub_startio_begin();
void sdv_stub_startio_end();
void sdv_stub_dispatch_begin();
void sdv_stub_dispatch_end(NTSTATUS s, PIRP pirp);
void sdv_stub_cancel_begin();
void sdv_stub_cancel_end();
void sdv_stub_add_begin();
void sdv_stub_add_end();
void sdv_stub_unload_begin();
void sdv_stub_unload_end();
void sdv_stub_MoreProcessingRequired(PIRP pirp);
void sdv_stub_WmiIrpProcessed(PIRP pirp);
void sdv_stub_WmiIrpNotCompleted(PIRP pirp);
void sdv_stub_WmiIrpForward(PIRP pirp);
void sdv_stub_PnpIrpNotProcessed();
char* malloc(int i);

#endif
