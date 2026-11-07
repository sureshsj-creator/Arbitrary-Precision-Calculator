#include "head.h"

Status division(Dlist *list1, Dlist *list2, Dlist *result)
{
    Dlist current = {NULL, NULL};

    Calc *temp1 = list1->head;
    Calc *temp2 = list2->head;

    int count = 0;
    int integer_digits = 0;

    /* Validate division by zero */
    while (temp2 && temp2->data == 0)
        temp2 = temp2->next;

    if (temp2 == NULL)
    {
        printf("Error: Division by zero is not allowed\n");
        return e_failure;
    }

    /* Calculate integer part */
    while (temp1)
    {
        if (insert_last(&current, temp1->data) == e_failure)
        {
            clear_list(&current);
            return e_failure;
        }

        remove_leading_zeroes(&current);

        count = 0;

        /* Repeated subtraction */
        while (list_compare(&current, list2) == NOSWAP)
        {
            if (subtraction(&current, list2, 0) == e_failure)
            {
                clear_list(&current);
                return e_failure;
            }

            count++;
        }

        /* Store integer quotient digit */
        if (insert_last(result, count) == e_failure)
        {
            clear_list(&current);
            return e_failure;
        }

        temp1 = temp1->next;
    }

    remove_leading_zeroes(result);

    Calc *temp = result->head;

    while (temp)
    {
        integer_digits++;
        temp = temp->next;
    }

    /* Calculate two decimal places */
    for (int i = 0; i < 2; i++)
    {
        /* Multiply remainder by 10 */
        if (insert_last(&current, 0) == e_failure)
        {
            clear_list(&current);
            return e_failure;
        }

        remove_leading_zeroes(&current);

        count = 0;

        while (list_compare(&current, list2) == NOSWAP)
        {
            if (subtraction(&current, list2, 0) == e_failure)
            {
                clear_list(&current);
                return e_failure;
            }

            count++;
        }

        /* Store decimal digit */
        if (insert_last(result, count) == e_failure)
        {
            clear_list(&current);
            return e_failure;
        }
    }

    temp = result->head;

    int i = 0;

    while (temp)
    {
        if (i == integer_digits)
            printf(".");

        printf("%d", temp->data);

        temp = temp->next;
        i++;
    }

    printf("\n");

    clear_list(&current);

    return e_success;
}

void clear_list(Dlist* list)
{
    /* Deleting all nodes of list */
    while(list->head)
    {
        Calc *temp = list->head;

        list->head = list->head->next;

        free(temp);
    }

    list->tail = NULL;
}