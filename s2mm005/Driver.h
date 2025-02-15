/*++

Module Name:

	driver.h

Abstract:

	This file contains the driver definitions.

Environment:

	Kernel-mode Driver Framework

--*/

#pragma once

#include <ntddk.h>
#include <wdf.h>
#include <initguid.h>

#include "device.h"
#include "trace.h"

//
// WDFDRIVER Events
//

DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD s2mm005EvtDeviceAdd;
EVT_WDF_OBJECT_CONTEXT_CLEANUP s2mm005EvtDriverContextCleanup;
EVT_WDF_DEVICE_PREPARE_HARDWARE s2mm005DevicePrepareHardware;
EVT_WDF_DRIVER_UNLOAD s2mm005EvtDriverUnload;

VOID s2mm005DeviceUnPrepareHardware(
	WDFDEVICE Device);