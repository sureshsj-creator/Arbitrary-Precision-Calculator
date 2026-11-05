#include "head.h"

void print_list(Calc *head)
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

		    /* Traversing in forward direction */
		    head = head -> next;
	    }
    	printf("\n");
    }
}