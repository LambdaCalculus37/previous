/*
	DSP M56001 emulation
	Dummy emulation, Hatari glue

	(C) 2001-2008 ARAnyM developer team
	Adaption to Hatari (C) 2008 by Thomas Huth

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software Foundation,
	51 Franklin Street, Fifth Floor, Boston, MA 02110-1335 USA
*/

#ifndef DSP_H
#define DSP_H

#define ENABLE_DSP_EMU 1

#if ENABLE_DSP_EMU
# include "dsp_core.h"
#endif

#define DSP_FREQ	(CPU_FREQ*4)

extern bool bDspEnabled;
extern bool bDspHostInterruptPending;

/* Dsp commands */
extern bool DSP_ProcessIRQ(void);
extern void DSP_Init(void);
extern void DSP_UnInit(void);
extern void DSP_Reset(void);
extern void DSP_Start(Uint8 mode);
extern void DSP_Run(int nHostCycles);

/* Save Dsp state to snapshot */
extern void DSP_MemorySnapShot_Capture(bool bSave);

/* Dsp Debugger commands */
extern void DSP_SetDebugging(bool enabled);
extern Uint16 DSP_GetPC(void);
extern Uint16 DSP_GetNextPC(Uint16 pc);
extern Uint16 DSP_GetInstrCycles(void);
extern Uint32 DSP_ReadMemory(Uint16 addr, char space, const char **mem_str);
extern Uint16 DSP_DisasmMemory(FILE *fp, Uint16 dsp_memdump_addr, Uint16 dsp_memdump_upper, char space);
extern Uint16 DSP_DisasmAddress(FILE *out, Uint16 lowerAdr, Uint16 UpperAdr);
extern void DSP_Info(FILE *fp, Uint32 dummy);
extern void DSP_DisasmRegisters(FILE *fp);
extern int DSP_GetRegisterAddress(const char *arg, Uint32 **addr, Uint32 *mask);
extern bool DSP_Disasm_SetRegister(const char *arg, Uint32 value);

/* Dsp SSI commands */
extern Uint32 DSP_SsiReadTxValue(void);
extern void DSP_SsiWriteRxValue(Uint32 value);
extern void DSP_SsiReceive_SC0(void);
extern void DSP_SsiReceive_SC1(Uint32 value);
extern void DSP_SsiReceive_SC2(Uint32 value);
extern void DSP_SsiReceive_SCK(void);
extern void DSP_SsiTransmit_SC0(void);
extern void DSP_SsiTransmit_SC1(void);
extern void DSP_SsiTransmit_SC2(Uint32 frame);
extern void DSP_SsiTransmit_SCK(void);

/* Dsp SCI functions */
extern void DSP_HandleTXD(int set);

/* Dsp Host interface commands */
extern void DSP_HandleReadAccess(void);
extern void DSP_HandleWriteAccess(void);
extern Uint16 DSP_Get_HREQ(void);

void DSP_ICR_Read(void);
void DSP_ICR_Write(void);
void DSP_CVR_Read(void);
void DSP_CVR_Write(void);
void DSP_ISR_Read(void);
void DSP_ISR_Write(void);
void DSP_IVR_Read(void);
void DSP_IVR_Write(void);

void DSP_Data0_Read(void);
void DSP_Data0_Write(void);
void DSP_Data1_Read(void);
void DSP_Data1_Write(void);
void DSP_Data2_Read(void);
void DSP_Data2_Write(void);
void DSP_Data3_Read(void);
void DSP_Data3_Write(void);

extern Uint8 dsp_intr_at_block_end;
extern Uint8 dsp_dma_unpacked;
void DSP_SetIRQB(void);

#endif /* DSP_H */
