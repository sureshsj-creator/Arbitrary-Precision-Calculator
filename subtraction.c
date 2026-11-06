#include "head.h"

Status subtraction(Dlist *list1, Dlist *list2, int print)
{
    int ret = list_compare(list1, list2);
    int sign = 1;

    Dlist *big = list1;
    Dlist *small = list2;

    if (ret == SWAP)
    {
        sign = -1;
        big = list2;
        small = list1;
    }
    int data, dataR, borrow = 0;

    Calc *temp1 = big->tail;
    Calc *temp2 = small->tail;

    Dlist result = {NULL, NULL};

    // Perform subtraction from right to left
    while (temp1 != NULL)
    {
        if (temp2 != NULL)
        {
            data = temp1->data - borrow;

            if (data < temp2->data)
            {
                borrow = 1;
                data = data + 10;
            }
            else
            {
                borrow = 0;
            }

            dataR = data - temp2->data;
            temp2 = temp2->prev;
        }
        else
        {
            data = temp1->data - borrow;

            if (data < 0)
            {
                borrow = 1;
                dataR = data + 10;
            }
            else
            {
                borrow = 0;
                dataR = data;
            }
        }

        if (insert_first(&result, dataR) == e_failure)
        {
            printf("Error: Failed to insert digit during subtraction\n");
            clear_list(&result);
            return e_failure;
        }

        temp1 = temp1->prev;
    }
    // Remove leading zeroes
    remove_leading_zeroes(&result);

    // Apply negative sign to first digit
    if (result.head != NULL)
    {
        result.head->data = result.head->data * sign;
    }

    // Replace list1 with subtraction result

    list1->head = result.head;
    list1->tail = result.tail;

    if(print)
    print_list(result.head);

    // Transfer ownership
    result.head = NULL;
    result.tail = NULL;

    return e_success;
}


int list_compare(Dlist *list1, Dlist *list2)
{
    Calc *head1 = list1->head;
    Calc *head2 = list2->head;

    int list1_count = 0, list2_count = 0;

    Calc *temp1 = head1;
    Calc *temp2 = head2;

    while (temp1)
    {
        list1_count++;
        temp1 = temp1->next;
    }

    while (temp2)
    {
        list2_count++;
        temp2 = temp2->next;
    }

    if (list1_count > list2_count)
        return NOSWAP;

    else if (list1_count < list2_count)
        return SWAP;

    else
        return data_compare(head1, head2);
}

int data_compare(Calc *head1, Calc *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data > head2->data)
            return NOSWAP;

        else if (head1->data < head2->data)
            return SWAP;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NOSWAP;
}

void remove_leading_zeroes(Dlist* list)
{
    while(list->head && list->head != list->tail && list->head->data == 0)
    {
        Calc * temp = list->head;

        list->head = list->head->next;
        list->head->prev = NULL;

        free(temp);
    }
}