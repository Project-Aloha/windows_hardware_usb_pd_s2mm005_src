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

    switch (TypeC_Status) {
    case State_PE_SRC_Startup:
    case State_PE_SRC_Send_Capabilities:
    case State_PE_SRC_Negotiate_Capability:
    case State_PE_SRC_Transition_Supply:
    case State_PE_SRC_Ready:
    case State_PE_SRC_Disabled:
        /* USBHOST */
        break;
    case State_PE_SNK_Wait_for_Capabilities:
    case State_PE_SNK_Evaluate_Capability:
    case State_PE_SNK_Ready:
    case State_ErrorRecovery:
        /* USBFN */
        break;
    default:
        break;
    }

    TraceEvents(
        TRACE_LEVEL_INFORMATION,
        TRACE_DRIVER,
        "%!FUNC! Exit");

    return TRUE;
}