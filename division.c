#include "head.h"

Status division(Dlist *list1, Dlist *list2, Dlist *result)
{
    Dlist current = {NULL, NULL};

    Calc *temp1 = list1->head;
    Calc *temp2 = list2->head;

    int count = 0;

    // Validate division by zero
    while (temp2 && temp2->data == 0)
        temp2 = temp2->next;

    if (temp2 == NULL)
    {
        printf("Error: Division by zero is not allowed\n");
        return e_failure;
    }

    // Take dividend digits one by one
    while (temp1)
    {
        if (insert_last(&current, temp1->data) == e_failure)
        {
            clear_list(&current);
            return e_failure;
        }

        remove_leading_zeroes(&current);

        count = 0;

        // Repeated subtraction
        while (list_compare(&current, list2) == NOSWAP)
        {
            if (subtraction(&current, list2,0) == e_failure)
            {
                clear_list(&current);
                return e_failure;
            }

            remove_leading_zeroes(&current);

            count++;
        }

        // Store quotient digit
        if (insert_last(result, count) == e_failure)
        {
            clear_list(&current);
            return e_failure;
        }

        temp1 = temp1->next;
    }

    remove_leading_zeroes(result);

    print_list((*result).head);

    clear_list(&current);

    return e_success;
}


void clear_list(Dlist* list)
{
    // Deleting all nodes of list
    while(list->head)
    {
        Calc *temp = list->head;

        list->head = list->head->next;

        free(temp);
    }

    list->tail = NULL;
}