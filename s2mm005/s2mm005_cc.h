#pragma once

#include <ntddk.h>
#include <wdf.h>

NTSTATUS
S2mm005_Get_TypeC_Status(
	PDEVICE_CONTEXT deviceContext,
	PULONG TypeC_Status
);