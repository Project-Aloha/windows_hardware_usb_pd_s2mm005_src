#include "Driver.h"
#include "s2mm005.h"
#include "s2mm005_cc.h"
#include "s2mm005.tmh"

BOOLEAN
OnInterruptIsr(
    IN WDFINTERRUPT Interrupt,
    IN ULONG MessageID
)
{
    NTSTATUS status = STATUS_SUCCESS;
    ULONG            TypeC_Status;
    PDEVICE_CONTEXT devContext = DeviceGetContext(WdfInterruptGetDevice(Interrupt));

    UNREFERENCED_PARAMETER(MessageID);

    TraceEvents(
        TRACE_LEVEL_INFORMATION,
        TRACE_DRIVER,
        "%!FUNC! Entry");

    S2mm005_Get_TypeC_Status(devContext, &TypeC_Status);

    TraceEvents(
        TRACE_LEVEL_INFORMATION,
        TRACE_DRIVER,
        "%!FUNC! Exit");

    return TRUE;
}