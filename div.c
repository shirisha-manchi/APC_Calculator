#include "apc.h"

void division(node *headL1, node *head_opr2, node *tail_opr2 ,node **headR, node **tailR)
{
    node * head_opr1 = NULL, *tail_opr1 = NULL, *L1_temp = headL1;
    node * head_SR = NULL, *tail_SR = NULL;
    int sub_count = 0;
    insert_last(&head_opr1, &tail_opr1, L1_temp->data);
    while(compare_list(head_opr1, head_opr2) == OPERAND2)
    {
        L1_temp = L1_temp->next;
        if(L1_temp == NULL)
        {
            insert_last(headR, tailR, 0);
            return;
        }
        insert_last(&head_opr1, &tail_opr1, L1_temp->data);             
    }
    while(L1_temp)
    {
        remove_pre_zeros(&head_opr1);
        sub_count = 0;
        while(compare_list(head_opr1, head_opr2) == OPERAND1  || compare_list(head_opr1, head_opr2) == SAME)
        {
            subtraction(tail_opr1, tail_opr2, &head_SR, &tail_SR);
            delete_list(&head_opr1, &tail_opr1);
            head_opr1 = head_SR;
            tail_opr1 = tail_SR;
            head_SR = tail_SR = NULL;
            sub_count++;
        }
        insert_last(headR, tailR, sub_count);
        L1_temp = L1_temp->next;
        if(L1_temp == NULL)
            break;
        else
            insert_last(&head_opr1, &tail_opr1, L1_temp->data);
    }

}
