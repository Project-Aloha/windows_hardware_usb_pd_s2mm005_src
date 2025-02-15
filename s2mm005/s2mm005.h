#pragma once

#include <ntddk.h>
#include <wdf.h>

/*
 * Rob Green, a member of the NTDEV list, provides the
 * following set of macros that'll keep you from having
 * to scratch your head and count zeros ever again.
 * Using these defintions, all you'll have to do is write:
 *
 * interval.QuadPart = RELATIVE(SECONDS(5));
 */

#ifndef ABSOLUTE
#define ABSOLUTE(wait) (wait)
#endif

#ifndef RELATIVE
#define RELATIVE(wait) (-(wait))
#endif

#ifndef NANOSECONDS
#define NANOSECONDS(nanos) \
	(((signed __int64)(nanos)) / 100L)
#endif

#ifndef MICROSECONDS
#define MICROSECONDS(micros) \
	(((signed __int64)(micros)) * NANOSECONDS(1000L))
#endif

#ifndef MILLISECONDS
#define MILLISECONDS(milli) \
	(((signed __int64)(milli)) * MICROSECONDS(1000L))
#endif

#ifndef SECONDS
#define SECONDS(seconds) \
	(((signed __int64)(seconds)) * MILLISECONDS(1000L))
#endif

EVT_WDF_INTERRUPT_ISR OnInterruptIsr;

NTSTATUS
S2mm005_Get_TypeC_Status(
	WDFDEVICE Device,
	PULONG TypeC_Status
);