#include "apc.h"

/*  VALIDATION  */
int cla_validation(int argc, char *argv[])
{
    // Validation
	if(argc != 4)
	{
		printf("======================================================================\n");
		printf("                    INVALID CLA ARGUMENTS                   \n");
		printf("======================================================================\n");
		printf("Addition			:	./a.out  operand1  +  operand2\n");
		printf("Subtraction			:	./a.out  operand1  -  operand2\n");
		printf("Multiplication   	        :	./a.out  operand1  x  operand2\n");
		printf("Division			:	./a.out  operand1  /  operand2\n");
		printf("======================================================================\n");

		return 0;
	}
	//validating operand1
	int i=0;
	if(argv[1][i] == '-' || argv[1][i] == '+')
		i++;
	while(argv[1][i])
	{
		if(argv[1][i] < '0' || argv[1][i]>'9')
		{
			printf("==============================================================\n");
			printf("Invalid operand = > %s\n",argv[1]);
			printf("==============================================================\n");
			return 0;
		}
		i++;
	}
	//validating operand2
	int j=0;
	if(argv[3][j] == '-' || argv[3][j] == '+')
		j++;
	while(argv[3][j])
	{
		if(argv[3][j] < '0' || argv[3][j]>'9')
		{
			printf("==============================================================\n");
			printf("Invalid operand = > %s\n",argv[3]);
			printf("==============================================================\n");
			return 0;
		}
		j++;
	}

    return 1;
}
// Function definitions
/* CREATE LIST */
void create_list(char *opr, node **head, node **tail)
{
    int i=0;
	if(opr[i] == '-' || opr[i] == '+')
		i++;
    while(opr[i])
    {
        int data = opr[i] - '0';
        insert_last(head, tail, data);
        i++;
    }
		
}

/* INSERT FIRST*/
int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    
    if(*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        new->next = (*head);
        (*head)->prev = new;
        (*head) = new;
    }
    return SUCCESS;

}
/*INSERT LAST */
int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    
    if(*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        (*tail)->next = new;
        new->prev = (*tail);
        (*tail) = new;
    }
    
    return SUCCESS;

}


/* PRINTING LIST*/
void print_list(node *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
		printf("\n");
    }
}
/* DELETE LIST */
int delete_list(node **head, node **tail)
{
	if(*head == NULL)
        return FAILURE;
    
    node *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *tail = NULL; 
    return SUCCESS;
}

/* COMPARE 2 LISTS */
int compare_list(node *head1, node *head2)
{
	int len1 = list_len(head1);
	int len2 = list_len(head2);

	node * temp1 = head1;
	node * temp2 = head2;

	if(len1>len2)
		return OPERAND1;
	else if(len2>len1)
		return OPERAND2;
	else
	{
		while(temp1 || temp2)
		{
			if(temp1->data > temp2->data)
				return OPERAND1;
			else if(temp1->data < temp2->data)
				return OPERAND2;
			else
			{
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
		}
		return SAME;
	}

}

/* LIST LENGTH*/
int list_len(node *head)
{
	int len = 0;
	while(head)
	{
		len ++;
		head = head->next;
	}
	return len;
}

/* REMOVING PRE-ZEROS IN LIST*/
void remove_pre_zeros(node **head)
{
	
	while((*head)->data == 0)
	{
		if((*head)->next == NULL)
			return;

		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
}
	