#include "unity.h"
#include "TCB.h"
#include "Linklist.h"

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
  TEST_ASSERT_NULL(tcbRoot.head);
  TEST_ASSERT_NULL(tcbRoot.tail);
  
}
 
void test_addList_add_task1Tcb_into_linked_list_the_head_of_list_should_point_to_task1Tcb(void){
  LinkedlistTcb* root = &tcbRoot;
  initTask1Tcb(taskOne);  
  initTask2Tcb(taskTwo);  
  initTaskCPU();
  tcbRootInit();
  addList(root,&task1Tcb);
  TEST_ASSERT_EQUAL_PTR(&task1Tcb,root->head);
}

void test_addList_add_task1Tcb_and_task2Tcb_into_linked_list_The_list_should_contain_two_element(void){
  LinkedlistTcb* root = &tcbRoot;
  initTask1Tcb(taskOne);  
  initTask2Tcb(taskTwo);  
  initTaskCPU();
  tcbRootInit();
  addList(root,&task1Tcb);
  addList(root,&task2Tcb);
  TEST_ASSERT_EQUAL_PTR(&task1Tcb,root->head);
  TEST_ASSERT_EQUAL_PTR(&task2Tcb,root->head->next);
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
  TEST_ASSERT_EQUAL_PTR(&task1Tcb,root->head);
  TEST_ASSERT_EQUAL_PTR(&task2Tcb,root->head->next);
  TEST_ASSERT_EQUAL_PTR(&taskCPU,root->head->next->next);
}


void test_linkListHeadRemove_the_element_of_head_was_removed_and_the_head_point_the_next_of_head(void){
  Tcb* temp;
  LinkedlistTcb* root = &tcbRoot;

  addList(root,&task1Tcb);
  addList(root,&task2Tcb);
  addList(root,&taskCPU);
  
  temp = linkListHeadRemove(root);
  
  TEST_ASSERT_EQUAL_PTR(&task2Tcb,root->head);
  TEST_ASSERT_EQUAL_PTR(&task1Tcb,temp);
  TEST_ASSERT_NULL(temp->next);
}

void test_linkListHeadRemove_the_element_of_head_was_removed_and_the_head_point_NUll(void){
  Tcb* temp;
  LinkedlistTcb* root = &tcbRoot;
  TEST_ASSERT_NULL(root->head);
  
  addList(root,&task1Tcb);
  addList(root,&task2Tcb);
  
  temp = linkListHeadRemove(root);
  
  TEST_ASSERT_EQUAL_PTR(root->head,&task2Tcb);
  TEST_ASSERT_EQUAL_PTR(&task1Tcb,temp);
  TEST_ASSERT_NULL(temp->next);
  
  temp = linkListHeadRemove(root);
  TEST_ASSERT_EQUAL_PTR(&task2Tcb,temp);
  TEST_ASSERT_NULL(temp->next);
  TEST_ASSERT_NULL(root->head);

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
  