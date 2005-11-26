/* $Id$
 *
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS kernel
 * FILE:            ntoskrnl/io/adapter.c
 * PURPOSE:         DMA handling
 *
 * PROGRAMMERS:     David Welch (welch@mcmail.com)
 */

/* INCLUDES *****************************************************************/

#include <ntoskrnl.h>
#define NDEBUG
#include <internal/debug.h>

/* DATA **********************************************************************/

POBJECT_TYPE IoAdapterObjectType = NULL;	/* FIXME */
POBJECT_TYPE IoDeviceHandlerObjectType = NULL;	/* FIXME */
ULONG        IoDeviceHandlerObjectSize = 0;    /* FIXME */

/* FUNCTIONS *****************************************************************/

/*
 * @implemented
 */
NTSTATUS STDCALL
IoAllocateAdapterChannel (PADAPTER_OBJECT	AdapterObject,
			  PDEVICE_OBJECT	DeviceObject,
			  ULONG		NumberOfMapRegisters,
			  PDRIVER_CONTROL	ExecutionRoutine,
			  PVOID		Context)
{
  DeviceObject->Queue.Wcb.DeviceObject = DeviceObject;
  DeviceObject->Queue.Wcb.DeviceContext = Context;
  DeviceObject->Queue.Wcb.CurrentIrp = DeviceObject->CurrentIrp;

  return HalAllocateAdapterChannel( AdapterObject,
				    &DeviceObject->Queue.Wcb,
				    NumberOfMapRegisters,
				    ExecutionRoutine);
}


/* NOTE: Missing IoXXXAdapter finctions in HAL.DLL */


/* EOF */
