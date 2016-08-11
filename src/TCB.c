#include "TCB.h"
#include <stdlib.h>

Tcb mainTcb;
Tcb task1Tcb;
Tcb task2Tcb;
Tcb task3Tcb;

void task1()
{
	while(1)
	{}
}

void task2()
{
	while(1){}
}

void task3()
{
	while(1){}
}

/**
 * Must call this function first
 */
void initTcb()
{
	CpuContext *context;
	mainTcb.name	= "Main";
	mainTcb.sp		= 0;
	mainTcb.next = &task1Tcb;
	task1Tcb.name = "task_1";
	task1Tcb.sp = (uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE];
	context = (CpuContext *) &task1Tcb.virtualStack[TASK_STACK_SIZE] ;
  context->R4 = 0x11111104;
	context->R5 = 0x11111105;
	context->R6 = 0x11111106;
	context->R7 = 0x11111107;
	context->R8 = 0x11111108;
	context->R9 = 0x11111109;
	context->R10 = 0x11111010;
	context->R11 = 0x11111011;
	context->R0 = 0x11111100;
  context->R1 = 0x11111101;
  context->R2 = 0x11111102;
  context->R3 = 0x11111103;  
  context->R12 = 0x11111012;
	task1Tcb.next = &task2Tcb;
	task2Tcb.name = "task_2";
	task2Tcb.sp	  = (uint32_t)&task2Tcb.virtualStack[TASK_STACK_SIZE];
	task2Tcb.next = &task3Tcb;
	task3Tcb.name = "task_3";
	task3Tcb.sp	  = (uint32_t)&task3Tcb.virtualStack[TASK_STACK_SIZE];
	task3Tcb.next = &mainTcb;
}


// Study the code in AsssemblyModule.s and take note of what
// how each instruction performs its job. You need that knowledge
// to do the following:
//
// 1) Create a new assembly file called 'SaveRegisters.s'.
// 2) Write a code in assembly [in (1)] to:
//    - load SP with the value in 'task1Tcb.sp'
//    - push all registers, except R13 to the stack
// 3) Name that function as 'saveRegs'
// 4) From main() call: 
//    - initTcb()
//    - saveRegs()
// 5) Verify that the registers are in 'task1Tcb.virtualStack'
// 6) Submit your work by pushing it to GitHub
