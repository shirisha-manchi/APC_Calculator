#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR1, node **tailR1)
{

    node * temp1 = tail1;
    node * temp2 = tail2;

    node * headR2 = NULL;
    node * tailR2 = NULL;
    //Addition result
    node * head_AR = NULL;
    node * tail_AR = NULL;
    int num1, num2, mul, data,j;
    int i = 0;
    while(temp2)
    {
        int carry = 0;
        j = i;
        while(j)
        {
            insert_first(&headR2,&tailR2, 0);
            j--;
        }
        while(temp1)
        {
            num1 = temp1->data;
            num2 = temp2->data;

            mul = (num1 * num2)+carry;
            data = mul%10;
            carry = mul/10;
            if(i==0)
                insert_first(headR1, tailR1, data);
            else if(i>0)
                insert_first(&headR2, &tailR2, data);

            temp1 = temp1->prev;
        }
        if (carry)
        {
            //for first row carry
            if (i == 0)
                insert_first(headR1, tailR1, carry);

            //for next row carry's
            else
                insert_first(&headR2, &tailR2, carry);
        }

        if(i>=1)
        {
            addition(*tailR1, tailR2, &head_AR, &tail_AR);
            delete_list(headR1, tailR1);
            delete_list(&headR2, &tailR2);

            *headR1 = head_AR;
            *tailR1 = tail_AR;

            head_AR = tail_AR = NULL;
        }
        i++;
        temp2 = temp2->prev;
        temp1 = tail1;
    }
    remove_pre_zeros(headR1);
}
