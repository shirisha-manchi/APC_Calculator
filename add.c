#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
  
    node * temp1 = tail1;
    node * temp2 = tail2;
    int carry = 0, num1, num2, data, sum = 0;
    while(temp1 || temp2)
    {
        if(temp1)
        {
            num1 = temp1->data;
            temp1 = temp1->prev;
        }
        else
            num1 = 0;
        
        if(temp2 )
        {
            num2 = temp2->data;
            temp2 = temp2->prev;
        }
        else
            num2 = 0;
        
        sum = num1+num2+carry;
        data = sum%10;
        carry = sum/10;
        insert_first(headR, tailR, data);
    }
    if(carry)
    {
        insert_first(headR, tailR, 1);
    }

}
