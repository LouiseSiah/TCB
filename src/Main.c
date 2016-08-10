/**
 * Study the code by stepping through using debugger. Take note
 * of the stack memory, registers, variables declared in 'Main.c'
 * and 'AssemblyModule.s'.
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "AssemblyModule.h"
#include "SaveRegisters.h"
//#include "Linklist.h"
#include "TCB.h"
//#include "stm32f4xx_hal.h"

extern int fourBytes;						// Import from AssemblyModule.s
extern uint16_t twoBytes;				// Import from AssemblyModule.s
//extern int taskSp;							// Import from SaveRegisters.s
//extern int curSp;

uint32_t taskFunc;
uint32_t variableInC = 0xdeaf;
uint32_t nextSP;
uint32_t currentSP;
Tcb *currentTask;

//All tasks =====================================================
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


//============================================
int main() {	
	int i = 0;
//	fourBytes = 0xdeadbeef;
//	taskSp	= 0xace0face;
//	noArgFunc();
	initTcb();
	currentTask = &mainTcb;
	loadCurrentSP();
	mainTcb.sp = currentSP;
	nextSP = currentTask->next->sp;
	
	
	initSysTick();

	
	while(1) {
		i++;
	}

//	return 0;				// Verify that 'variableInC' now contains 0xB19FACE
}

int cFunc()
{
	return 0xc00000 + twoBytes;		//
}
