#ifndef __SAVE_REGISTERS_H__
#define __SAVE_REGISTERS_H__
#include "TCB.h"

void loadCurrentSP(void);

void saveRegs(void);

void popSpToTcb(void);

#endif	// __SAVE_REGISTERS_H__
