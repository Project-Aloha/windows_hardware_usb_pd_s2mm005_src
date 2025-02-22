#pragma once

#include <ntddk.h>
#include <wdf.h>

#define State_PE_Initial_detach					 0

// source Port
#define State_PE_SRC_Startup					 1
#define State_PE_SRC_Discovery					 2
#define State_PE_SRC_Send_Capabilities			 3
#define State_PE_SRC_Negotiate_Capability		 4
#define State_PE_SRC_Transition_Supply			 5
#define State_PE_SRC_Ready						 6
#define State_PE_SRC_Disabled					 7
#define State_PE_SRC_Capability_Response		 8
#define State_PE_SRC_Hard_Rest					 9
#define State_PE_SRC_Hard_Rest_Received			 10
#define State_PE_SRC_Transition_to_default		 11
#define State_PE_SRC_Give_Source_Cap			 12
#define State_PE_SRC_Get_Sink_Cap				 13
#define State_PE_SRC_Wait_New_Capabilities		 14

// Sink Port
#define State_PE_SNK_Startup					 15
#define State_PE_SNK_Discovery					 16
#define State_PE_SNK_Wait_for_Capabilities		 17
#define State_PE_SNK_Evaluate_Capability		 18
#define State_PE_SNK_Select_Capability			 19
#define State_PE_SNK_Transition_Sink			 20
#define State_PE_SNK_Ready						 21
#define State_PE_SNK_Hard_Reset					 22
#define State_PE_SNK_Transition_to_default		 23
#define State_PE_SNK_Give_Sink_Cap				 24
#define State_PE_SNK_Get_Source_Cap				 25

// Source Startup Structured VDM Discover Indentity
#define State_PE_SRC_CABLE_VDM_Identity_Request	 26
#define State_PE_SRC_CABLE_VDM_Identity_ACKed	 27
#define State_PE_SRC_CABLE_VDM_Identity_NAKed	 28

// Type-C referenced states
#define State_ErrorRecovery						 29
#define State_PE_PRS_SRC_SNK_Transition_to_off	 52
#define State_PE_PRS_SNK_SRC_Source_on			 64

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
