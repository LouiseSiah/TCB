#include "unity.h"
#include "TCB.h"

void setUp(void)
{
}

void tearDown(void)
{
}






void test_getTopAddressOfStack_(void){
  CpuContext* context;
  context = getTopAddressOfStack(&task1Tcb.virtualStack[TASK_STACK_SIZE],sizeof(CpuContext));
  TEST_ASSERT_EQUAL_PTR(&task1Tcb.virtualStack[TASK_STACK_SIZE-64],context);  
  TEST_ASSERT_EQUAL_PTR(&task1Tcb.virtualStack[TASK_STACK_SIZE-4],& context->xPSR);
}
  
void test_initTask1Tcb_(void){
  CpuContext* context;
  context = getTopAddressOfStack(&task1Tcb.virtualStack[TASK_STACK_SIZE] , sizeof(CpuContext) );
  
  initTask1Tcb(taskOne);  
  TEST_ASSERT_EQUAL_STRING("task_1",task1Tcb.name);
  TEST_ASSERT_NULL(task1Tcb.next);
  TEST_ASSERT_EQUAL_PTR((uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE-64],task1Tcb.sp);    
  TEST_ASSERT_EQUAL_PTR(taskOne,context->PC);
  
  
  TEST_ASSERT_EQUAL(0xff,(uint32_t)task1Tcb.virtualStack[TASK_STACK_SIZE-4]);
  TEST_ASSERT_EQUAL(0xff,(uint32_t)task1Tcb.virtualStack[TASK_STACK_SIZE-3]);
  TEST_ASSERT_EQUAL(0xff,(uint32_t)task1Tcb.virtualStack[TASK_STACK_SIZE-2]);
  TEST_ASSERT_EQUAL(0xff,(uint32_t)task1Tcb.virtualStack[TASK_STACK_SIZE-1]);
  TEST_ASSERT_NOT_EQUAL(0xff,(uint32_t)task1Tcb.virtualStack[TASK_STACK_SIZE]);
}
 
 
void test_initTask2Tcb_(void){
  CpuContext* context;
  context = getTopAddressOfStack(&task1Tcb.virtualStack[TASK_STACK_SIZE] , sizeof(CpuContext) );
  
  initTask2Tcb(taskTwo);  
  TEST_ASSERT_EQUAL_STRING("task_2",task1Tcb.name);
  TEST_ASSERT_NULL(task2Tcb.next);
  TEST_ASSERT_EQUAL_PTR((uint32_t)&task2Tcb.virtualStack[TASK_STACK_SIZE-64],task1Tcb.sp);    
  TEST_ASSERT_EQUAL_PTR(taskTwo,context->PC);
  
  TEST_ASSERT_EQUAL(0xaa,(uint32_t)task2Tcb.virtualStack[TASK_STACK_SIZE-4]);
  TEST_ASSERT_EQUAL(0xaa,(uint32_t)task2Tcb.virtualStack[TASK_STACK_SIZE-3]);
  TEST_ASSERT_EQUAL(0xaa,(uint32_t)task2Tcb.virtualStack[TASK_STACK_SIZE-2]);
  TEST_ASSERT_EQUAL(0xaa,(uint32_t)task2Tcb.virtualStack[TASK_STACK_SIZE-1]);
  TEST_ASSERT_NOT_EQUAL(0xff,(uint32_t)task2Tcb.virtualStack[TASK_STACK_SIZE]);
} 

/*

  printf("&virtualStack[1024] = 0x%x\n",(uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE]);
  printf("&virtualStack[1023] = 0x%x\n",(uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE-1]);
  printf("&virtualStack[1022] = 0x%x\n",(uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE-2]);
  printf("&virtualStack[1021] = 0x%x\n",(uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE-3]);
  task1Tcb.virtualStack[TASK_STACK_SIZE] = 14;
  printf("task1Tcb.virtualStack[TASK_STACK_SIZE] = %d\n",task1Tcb.virtualStack[TASK_STACK_SIZE]);
  printf("sizeof(CpuContext) = %d",sizeof(CpuContext) );


*/ 
  