#include "s2mm005.h"
#include "Driver.h"
#include "s2mm005.tmh"

BOOLEAN
OnInterruptIsr(
    IN WDFINTERRUPT Interrupt,
    IN ULONG MessageID
)
{
    UNREFERENCED_PARAMETER(MessageID);
    NTSTATUS status = STATUS_SUCCESS;

    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");

    return status;
}