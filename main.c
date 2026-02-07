#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

    if(cla_validation(argc, argv)==0)
		return 0;

    // Create 2 lists of operands
	create_list(argv[1],&head1, &tail1);
	create_list(argv[3],&head2, &tail2);
	remove_pre_zeros(&head1);
	remove_pre_zeros(&head2);


	char oper = argv[2][0];

	int pos_flag1=0, pos_flag2=0, neg_flag1=0, neg_flag2=0, negative = 0;
    if(argv[1][0] == '-')
		neg_flag1 = 1;
	else if(argv[1][0] == '+')
		pos_flag1 = 1;
	if(argv[3][0] == '-')
		neg_flag2 = 1;
	else if(argv[3][0] == '+')
		pos_flag2 = 1;

	int ret;
    switch(oper)
    {
	case '+':
		if(neg_flag1 && neg_flag2)
		{
			addition(tail1, tail2, &headR, &tailR);
			negative = 1;
			break;

		}
		if(neg_flag1)
		{
			if(compare_list(head1, head2) == OPERAND1)
			{
				subtraction(tail1, tail2, &headR, &tailR);
				negative = 1;
			}
			else if(compare_list(head1, head2) == OPERAND2)
				subtraction(tail2, tail1, &headR, &tailR);
			else
				insert_first(&headR, &tailR, 0);
		}
		if(neg_flag2)
		{
			if(compare_list(head1, head2) == OPERAND1)
				subtraction(tail1, tail2, &headR, &tailR);
			else if(compare_list(head1, head2) == OPERAND2)
			{
				subtraction(tail2, tail1, &headR, &tailR);
				negative = 1;
			}
			else
				insert_first(&headR, &tailR, 0);
		}
		else
			addition(tail1, tail2, &headR, &tailR);
		
	    break;

	case '-':
		ret = compare_list(head1, head2);
		if(neg_flag1 && neg_flag2)
		{
			if(ret == OPERAND1)
			{
				subtraction(tail1, tail2, &headR, &tailR);
				negative = 1;
			}
			else if (ret == OPERAND2)
				subtraction(tail2, tail1, &headR, &tailR);
			else
				insert_first(&headR, &tailR, 0);
			
			break;
		}
		if(neg_flag1)
		{
			addition(tail1, tail2, &headR, &tailR);
			negative = 1;
			break;
		}
		if(neg_flag2)
		{
			addition(tail1, tail2, &headR, &tailR);
			break;
		}
		else 
		{
			if(ret == OPERAND1)
			subtraction(tail1,tail2, &headR, &tailR);
			else if(ret == OPERAND2)
			{
				subtraction(tail2, tail1, &headR, &tailR);
				printf("-");
			}
			else
				insert_first(&headR, &tailR, 0);
		}
	    break;

	case 'x':
	case 'X':
		if(neg_flag1 && neg_flag2)
			negative = 0;
		else if(neg_flag1 || neg_flag2)
			negative = 1;
		multiplication(tail1,tail2, &headR, &tailR);
	    break;

	case '/':
		if(head2->data == 0)
		{
			printf("ERROR: Number cannot be divided by 0\n");
			return 0;
		}
		if(neg_flag1 && neg_flag2)
			negative = 0;
		else if(compare_list(head1,head2) !=OPERAND2 && neg_flag1 || compare_list(head1,head2) !=OPERAND2 && neg_flag2)
			negative = 1;
		division(head1, head2, tail2, &headR, &tailR);
	    break;

	default:
	    printf("Invalid operator\n");
    }
	printf("==============================================================\n");
	printf("                      APC Calculator                        \n");
	printf("==============================================================\n");
	printf("Operand 1	:	%s\n",argv[1]);
	printf("Operation	:	%s\n",argv[2]);
	printf("Operand 2	:	%s\n",argv[3]);
	printf("--------------------------------------------------------------\n");
	printf("Result		:	");
	if(negative)
		printf("-");
	print_list(headR);
	printf("--------------------------------------------------------------\n");

}

