/* INCLUDE HEADERS */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* CONSTANT DEFINITIONS */
#define _RISC_RAM_BYTES 65536
#define _RISC_MENU_WELCOME "MyEduRISC Alpha \nCopyright (C) 2018 Michael Fitzgerald \n\n\tThis program comes with ABSOLUTELY NO WARRANTY. \n\tThis is free software, and you are welcome to redistribute it \n\tunder certain conditions. Type `edurisc --license' for details."
#define _RISC_MENU_LICENSE "MyEduRISC - a virtual machine for the educational programming environment EduRISC \nCopyright (C) 2018 Michael Fitzgerald \n\nThis program is free software: you can redistribute it and/or modify \nit under the terms of the GNU General Public License as published by \nthe Free Software Foundation, either version 3 of the License, or \n(at your option) any later version. \n\nThis program is distributed in the hope that it will be useful, \nbut WITHOUT ANY WARRANTY; without even the implied warranty of \nMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the \nGNU General Public License for more details. \n\nYou should have received a copy of the GNU General Public License \nalong with this program.  If not, see <https://www.gnu.org/licenses/>."
#define _RISC_MENU_USAGE "USAGE: \tedurisc path_to_rom_file [-opts] \nor \tedurisc [--override] \nType 'edurisc --help' for more documentation."
#define _RISC_MENU_VERSION "0.01 (Pre-Alpha) 1812A"

#define _RISC_IPS 500000

/* REGISTERS */
typedef uint8_t RISC_REG8;
typedef uint16_t RISC_REG16;
//extern RISC_REG16 A, X, Y; // General purpose (hybrid)
//extern RISC_REG16 DI, SI, BP, IP, SP, CF; // Pointers and flags (16-bit)
//extern RISC_REG8 CSEG, DSEG, SSEG; // Segment pointers (8-bit)

/* GLOBAL DATA DECLARATIONS */
//extern uint8_t RISC_RAM[_RISC_RAM_SIZE];

/* ENGINE PROPERTIES */

//extern uint32_t RISC_GLOBAL_FLAGS;
typedef struct
{
    // 8-bit/16-bit hybrid
    uint16_t A; // accumulator
    uint16_t X; // general-purpose
    uint16_t Y; // general-purpose

    // 16-bit (pointers and flags)
    uint16_t DI; // destination index (general-purpose pointer)
    uint16_t SI; // source index (general-purpose pointer)
    uint16_t IP; // instruction pointer
    uint16_t BP; // base pointer (stack base)
    uint16_t SP; // stack pointer (current stack position)
    uint16_t CF; // CPU flags

    // 8-bit (memory segmentation)
    uint8_t CSEG; // code segment
    uint8_t DSEG; // data segment
    uint8_t SSEG; // stack segment
} RISC_MachineRegs;

typedef void (*RISC_FunctionPointer)(void *);

typedef struct
{
    uint8_t *mem;
    unsigned int mem_size; //kb

    RISC_MachineRegs regs;
    RISC_FunctionPointer *ops;

    uint32_t options;
} RISC_Machine; // RISC_Machine struct/pointer/etc.

extern RISC_Machine *RISC_Init(unsigned int memory_size);
extern void RISC_Quit(RISC_Machine *machine);
extern int RISC_LoadBinMem(FILE *fp, RISC_Machine *machine, uint16_t memory_addr, uint16_t count);
extern void RISC_ResetOps(RISC_Machine *machine);
extern void RISC_MachineStart(RISC_Machine *machine);
extern void RISC_MachineIter(RISC_Machine *machine);
extern void RISC_MachineStop(RISC_Machine *machine);

//extern int RISC_CPU();

//extern void RISC_OP_NOP();
//extern void RISC_OP_HLT();
//extern void RISC_OP_AND_X8();
//extern void RISC_OP_AND_Y8();
//extern void RISC_OP_AND_imm8();
//extern void RISC_OP_AND_X16();
//extern void RISC_OP_AND_Y16();
//extern void RISC_OP_AND_imm16();
//extern void RISC_OP_ADD_X8();
//extern void RISC_OP_ADD_Y8();
//extern void RISC_OP_ADD_imm8();
//extern void RISC_OP_ADD_X16();
//extern void RISC_OP_ADD_Y16();
//extern void RISC_OP_ADD_imm16();
