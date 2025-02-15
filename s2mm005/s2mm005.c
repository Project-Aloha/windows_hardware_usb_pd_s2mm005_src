#include "s2mm005.h"
#include "Driver.h"
#include "s2mm005.tmh"

BOOLEAN
OnInterruptIsr(
    IN WDFINTERRUPT Interrupt,
    IN ULONG MessageID
)
{
    BOOLEAN status = TRUE;

    UNREFERENCED_PARAMETER(Interrupt);
    UNREFERENCED_PARAMETER(MessageID);

    return status;
}