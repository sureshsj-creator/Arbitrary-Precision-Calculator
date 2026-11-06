#include "head.h"

Status multiplication(Dlist *list1, Dlist *list2)
{
    Calc *temp1 = list1->tail;
    Calc *temp2 = list2->tail;
   
    Dlist result = {NULL, NULL};
    Dlist partial = {NULL, NULL};

    int carry,count=0;
    int dataR,data;

    while(temp2 != NULL)
    {
        temp1 = list1->tail;
        carry = 0;

        while(temp1 != NULL)
        {
            data = (temp1->data * temp2->data) + carry;

            dataR = data % 10;
            carry = data / 10;

            insert_first(&partial, dataR);

            temp1 = temp1->prev;
        }

        if(carry != 0)
        {
            insert_first(&partial, carry);
        }

        for(int i = 0; i < count; i++)
        {
            insert_last(&partial, 0);
        }

        if(result.head == NULL)
        {
            result = partial;
            partial.head = NULL;
            partial.tail = NULL;
        }
        else
        {
            add_lists(&result, &partial);
            delete_list(&partial);
        }

        count++;
        temp2 = temp2->prev;
    }
    remove_leading_zeroes(&result);
    print_list(result.head);
    return e_success;
}


Status delete_list(Dlist *list)
{
    if(list->head==NULL)
    {
        return e_failure;
    }
    
    while(list->head->next!=NULL)
    {
        list->head= list->head->next;
        free(list->head->prev);
        list->head->prev=NULL;
    }
    if(list->head->next==NULL)
    {
        free(list->head);
        list->head= NULL;
        list->tail= NULL;
        return e_success;
    }
    return e_success;
}

Status add_lists(Dlist *list1, Dlist *list2)
{
    Calc *temp1 = list1->tail;
    Calc *temp2 = list2->tail;

    Dlist result = {NULL, NULL};

    int data, dataR;
    int carry = 0;

    while(temp1 != NULL || temp2 != NULL)
    {
        data = carry;

        if(temp1 != NULL)
        {
            data = data + temp1->data;
            temp1 = temp1->prev;
        }

        if(temp2 != NULL)
        {
            data = data + temp2->data;
            temp2 = temp2->prev;
        }

        dataR = data % 10;
        carry = data / 10;

        insert_first(&result, dataR);
    }

    if(carry)
    {
        insert_first(&result, carry);
    }

    delete_list(list1);

    *list1 = result;

    return e_success;
}