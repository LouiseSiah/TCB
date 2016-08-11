#ifndef __TCB_H__
#define __TCB_H__

#include <stdint.h>

#define TASK_STACK_SIZE	1024

typedef struct Tcb Tcb;

struct Tcb
{
	char			*name;									// Task name	
	uint32_t 	sp;								// Stack pointer (R13)
	uint8_t		virtualStack[TASK_STACK_SIZE];
	Tcb				*next;
};

typedef struct
{
	uint32_t R4;
	uint32_t R5;
	uint32_t R6;
	uint32_t R7;
	uint32_t R8;
	uint32_t R9;
	uint32_t R10;
	uint32_t R11;
	uint32_t R0;
	uint32_t R1;
	uint32_t R2;
	uint32_t R3;
	uint32_t R12;
	uint32_t LR;
	uint32_t PC;
	uint32_t xPSR;
}CpuContext;


extern Tcb mainTcb;
extern Tcb task1Tcb;
extern Tcb task2Tcb;
extern Tcb task3Tcb;
extern Tcb taskCPU;

void task1(void);

void task2(void);

void task3(void);

void initTcb(void);


#endif	// __TCB_H__
