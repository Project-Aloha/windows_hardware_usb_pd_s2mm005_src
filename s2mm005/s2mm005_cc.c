/*++

Module Name:

	s2mm005_cc.c

--*/

//--------------------------------------------------------------------- Includes
#include "Driver.h"
#include "Spb.h"
#include "s2mm005.h"
#include "s2mm005_cc.h"
#include "s2mm005_cc.tmh"

BYTE s2mm005_Read_Status[2] = { 0x00,0x20 };

NTSTATUS
S2mm005_Get_TypeC_Status(
    PDEVICE_CONTEXT deviceContext,
    PULONG TypeC_Status
)
{
    NTSTATUS Status = STATUS_SUCCESS;
    int USB_CC_Status = 0;

    Status = SpbReadDataSynchronouslyFromAnyAddr(&deviceContext->I2CContext, s2mm005_Read_Status, &USB_CC_Status, sizeof(s2mm005_Read_Status), 1);
    if (!NT_SUCCESS(Status))
    {
        TraceEvents(TRACE_LEVEL_ERROR, TRACE_DRIVER, "SpbReadDataSynchronously failed with Status = 0x%08lX\n", Status);
        goto Exit;
    }

    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "S2mm005: Read USB_CC_Status: %d \n", USB_CC_Status);

    *TypeC_Status = USB_CC_Status;

Exit:
    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER,
        "Leaving %!FUNC!: Status = 0x%08lX\n",
        Status);
    return Status;
}