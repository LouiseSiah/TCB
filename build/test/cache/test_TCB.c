#include "TCB.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}













void test_getTopAddressOfStack_(void){

  CpuContext* context;

  context = ((CpuContext*)(&task1Tcb.virtualStack[1024] - sizeof(CpuContext)));

  UnityAssertEqualNumber((_U_SINT)(_UP)((&task1Tcb.virtualStack[1024 -64])), (_U_SINT)(_UP)((context)), (((void *)0)), (_U_UINT)(20), UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&task1Tcb.virtualStack[1024 -4])), (_U_SINT)(_UP)((& context->xPSR)), (((void *)0)), (_U_UINT)(21), UNITY_DISPLAY_STYLE_HEX32);

}



void test_initTask1Tcb_(void){

  CpuContext* context;

  context = ((CpuContext*)(&task1Tcb.virtualStack[1024] - sizeof(CpuContext)));



  initTask1Tcb(taskOne);

  UnityAssertEqualString((const char*)(("task_1")), (const char*)((task1Tcb.name)), (((void *)0)), (_U_UINT)(29));

  if ((((task1Tcb.next)) == ((void *)0))) {} else {UnityFail( (((" Expected NULL"))), (_U_UINT)((_U_UINT)((_U_UINT)(30))));};

  UnityAssertEqualNumber((_U_SINT)(_UP)(((uint32_t)&task1Tcb.virtualStack[1024 -64])), (_U_SINT)(_UP)((task1Tcb.sp)), (((void *)0)), (_U_UINT)(31), UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((taskOne)), (_U_SINT)(_UP)((context->PC)), (((void *)0)), (_U_UINT)(32), UNITY_DISPLAY_STYLE_HEX32);





  UnityAssertEqualNumber((_U_SINT)((0xff)), (_U_SINT)(((uint32_t)task1Tcb.virtualStack[1024 -4])), (((void *)0)), (_U_UINT)(35), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xff)), (_U_SINT)(((uint32_t)task1Tcb.virtualStack[1024 -3])), (((void *)0)), (_U_UINT)(36), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xff)), (_U_SINT)(((uint32_t)task1Tcb.virtualStack[1024 -2])), (((void *)0)), (_U_UINT)(37), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xff)), (_U_SINT)(((uint32_t)task1Tcb.virtualStack[1024 -1])), (((void *)0)), (_U_UINT)(38), UNITY_DISPLAY_STYLE_INT);

  if (((0xff) != ((uint32_t)task1Tcb.virtualStack[1024]))) {} else {UnityFail( ((" Expected Not-Equal")), (_U_UINT)((_U_UINT)(39)));};

}





void test_initTask2Tcb_(void){

  CpuContext* context;

  context = ((CpuContext*)(&task1Tcb.virtualStack[1024] - sizeof(CpuContext)));



  initTask2Tcb(taskTwo);

  UnityAssertEqualString((const char*)(("task_2")), (const char*)((task1Tcb.name)), (((void *)0)), (_U_UINT)(48));

  if ((((task1Tcb.next)) == ((void *)0))) {} else {UnityFail( (((" Expected NULL"))), (_U_UINT)((_U_UINT)((_U_UINT)(49))));};

  UnityAssertEqualNumber((_U_SINT)(_UP)(((uint32_t)&task1Tcb.virtualStack[1024 -64])), (_U_SINT)(_UP)((task1Tcb.sp)), (((void *)0)), (_U_UINT)(50), UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((taskTwo)), (_U_SINT)(_UP)((context->PC)), (((void *)0)), (_U_UINT)(51), UNITY_DISPLAY_STYLE_HEX32);



  UnityAssertEqualNumber((_U_SINT)((0xaa)), (_U_SINT)(((uint32_t)task1Tcb.virtualStack[1024 -4])), (((void *)0)), (_U_UINT)(53), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaa)), (_U_SINT)(((uint32_t)task1Tcb.virtualStack[1024 -3])), (((void *)0)), (_U_UINT)(54), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaa)), (_U_SINT)(((uint32_t)task1Tcb.virtualStack[1024 -2])), (((void *)0)), (_U_UINT)(55), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaa)), (_U_SINT)(((uint32_t)task1Tcb.virtualStack[1024 -1])), (((void *)0)), (_U_UINT)(56), UNITY_DISPLAY_STYLE_INT);

  if (((0xff) != ((uint32_t)task1Tcb.virtualStack[1024]))) {} else {UnityFail( ((" Expected Not-Equal")), (_U_UINT)((_U_UINT)(57)));};

}
