#include "Linklist.h"
#include "TCB.h"
#include "unity.h"


void setUp(void)

{

  initTask1Tcb(taskOne);

  initTask2Tcb(taskTwo);

  initTaskCPU();

  tcbRootInit();

}



void tearDown(void)

{





}





void test_tcbRootInit_(void){



  tcbRootInit();

  if ((((tcbRoot.head)) == ((void *)0))) {} else {UnityFail( (((" Expected NULL"))), (_U_UINT)((_U_UINT)((_U_UINT)(23))));};

  if ((((tcbRoot.tail)) == ((void *)0))) {} else {UnityFail( (((" Expected NULL"))), (_U_UINT)((_U_UINT)((_U_UINT)(24))));};



}



void test_addList_add_task1Tcb_into_linked_list_the_head_of_list_should_point_to_task1Tcb(void){

  LinkedlistTcb* root = &tcbRoot;

  initTask1Tcb(taskOne);

  initTask2Tcb(taskTwo);

  initTaskCPU();

  tcbRootInit();

  addList(root,&task1Tcb);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&task1Tcb)), (_U_SINT)(_UP)((root->head)), (((void *)0)), (_U_UINT)(35), UNITY_DISPLAY_STYLE_HEX32);

}



void test_addList_add_task1Tcb_and_task2Tcb_into_linked_list_The_list_should_contain_two_element(void){

  LinkedlistTcb* root = &tcbRoot;

  initTask1Tcb(taskOne);

  initTask2Tcb(taskTwo);

  initTaskCPU();

  tcbRootInit();

  addList(root,&task1Tcb);

  addList(root,&task2Tcb);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&task1Tcb)), (_U_SINT)(_UP)((root->head)), (((void *)0)), (_U_UINT)(46), UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&task2Tcb)), (_U_SINT)(_UP)((root->head->next)), (((void *)0)), (_U_UINT)(47), UNITY_DISPLAY_STYLE_HEX32);

}



void test_addList_add_task1Tcb_task2Tcb_and_taskCPU_into_linked_list_The_list_should_contain_three_element(void){

  LinkedlistTcb* root = &tcbRoot;

  initTask1Tcb(taskOne);

  initTask2Tcb(taskTwo);

  initTaskCPU();

  tcbRootInit();

  addList(root,&task1Tcb);

  addList(root,&task2Tcb);

  addList(root,&taskCPU);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&task1Tcb)), (_U_SINT)(_UP)((root->head)), (((void *)0)), (_U_UINT)(59), UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&task2Tcb)), (_U_SINT)(_UP)((root->head->next)), (((void *)0)), (_U_UINT)(60), UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&taskCPU)), (_U_SINT)(_UP)((root->head->next->next)), (((void *)0)), (_U_UINT)(61), UNITY_DISPLAY_STYLE_HEX32);

}





void test_linkListHeadRemove_the_element_of_head_was_removed_and_the_head_point_the_next_of_head(void){

  Tcb* temp;

  LinkedlistTcb* root = &tcbRoot;



  addList(root,&task1Tcb);

  addList(root,&task2Tcb);

  addList(root,&taskCPU);



  temp = linkListHeadRemove(root);



  UnityAssertEqualNumber((_U_SINT)(_UP)((&task2Tcb)), (_U_SINT)(_UP)((root->head)), (((void *)0)), (_U_UINT)(75), UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&task1Tcb)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)(76), UNITY_DISPLAY_STYLE_HEX32);

  if ((((temp->next)) == ((void *)0))) {} else {UnityFail( (((" Expected NULL"))), (_U_UINT)((_U_UINT)((_U_UINT)(77))));};

}



void test_linkListHeadRemove_the_element_of_head_was_removed_and_the_head_point_NUll(void){

  Tcb* temp;

  LinkedlistTcb* root = &tcbRoot;

  if ((((root->head)) == ((void *)0))) {} else {UnityFail( (((" Expected NULL"))), (_U_UINT)((_U_UINT)((_U_UINT)(83))));};



  addList(root,&task1Tcb);

  addList(root,&task2Tcb);



  temp = linkListHeadRemove(root);



  UnityAssertEqualNumber((_U_SINT)(_UP)((root->head)), (_U_SINT)(_UP)((&task2Tcb)), (((void *)0)), (_U_UINT)(90), UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&task1Tcb)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)(91), UNITY_DISPLAY_STYLE_HEX32);

  if ((((temp->next)) == ((void *)0))) {} else {UnityFail( (((" Expected NULL"))), (_U_UINT)((_U_UINT)((_U_UINT)(92))));};



  temp = linkListHeadRemove(root);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&task2Tcb)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)(95), UNITY_DISPLAY_STYLE_HEX32);

  if ((((temp->next)) == ((void *)0))) {} else {UnityFail( (((" Expected NULL"))), (_U_UINT)((_U_UINT)((_U_UINT)(96))));};

  if ((((root->head)) == ((void *)0))) {} else {UnityFail( (((" Expected NULL"))), (_U_UINT)((_U_UINT)((_U_UINT)(97))));};



}
