#include "apc.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    node * temp1 = tail1;
    node * temp2 = tail2;
    int borrow = 0, num1, num2;
    while(temp1)
    {
        if(temp1)
        {
            num1 = temp1->data;
            temp1=temp1->prev;
        }

        if(temp2)
        {
            num2 = temp2->data;
            temp2=temp2->prev;
        }
        else
            num2 = 0;
        
        if(borrow)
        {
            num1 -= 1;
            borrow = 0;
        }
        if(num1 < num2)
        {
            num1 += 10;
            borrow = 1;
        }
        insert_first(headR, tailR, (num1-num2));
    }
    remove_pre_zeros(headR);

}
