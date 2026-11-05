#include "head.h"

Status subtraction(Dlist *list1, Dlist *list2)
{
    int ret = list_compare(list1, list2);
    int sign = 1;
    if(ret)
    {
        sign = -1;
        swap_list(list1, list2);
    }
    int data,dataR,borrow= 0;
    Calc *temp1 = list1->tail;
    Calc *temp2 = list2->tail;

    Dlist result = {NULL, NULL};
    while(temp1 != NULL)
    {
        
        if(temp2!= NULL)
        {
            data= temp1->data-borrow;
            if(data < temp2->data)
            {
                borrow= 1;
                data= data+10;
            }
            else
            {
                borrow= 0;
            }
            dataR= data - temp2->data;
            temp2= temp2->prev;
        }
        else
        {
            data = temp1->data - borrow;

            if(data< 0)
            {
                borrow= 1;
                dataR= data+10;
            }
            else
            {
                borrow= 0;
                dataR =data;
            }
        }
        if(insert_first(&result, dataR)== e_failure)
        {
            printf("Error: Failed to insert digit during subtraction\n");
        }
        temp1= temp1->prev;
    }
    result.head->data = result.head->data * sign;
    print_list(result.head);
}

int list_compare(Dlist *list1, Dlist *list2)
{
    Calc *head1 = list1->head;
    Calc *head2 = list2->head;

    int list1_count=0,list2_count=0;
    Calc *temp1= head1;
    Calc *temp2= head2;
    while(temp1)
    {
        list1_count++;
        temp1= temp1->next;
    }
    while(temp2)
    {
        list2_count++;
        temp2= temp2->next;
    }
    if(list1_count > list2_count)
    return NOSWAP;
    else if(list1_count < list2_count)
    return SWAP;
    else if(list1_count == list2_count)
    {
       return data_compare(head1,head2);
    }
}

int data_compare(Calc *head1,Calc *head2)
{
    while(head1)
    {
        if(head1->data > head2->data)
        return NOSWAP;
        else if(head1->data < head2->data)
        return SWAP;
        else
        {
            head1= head1->next;
            head2= head2->next;
        }
    }
    return NOSWAP;
}

void swap_list(Dlist *list1, Dlist *list2)
{
    Dlist temp = *list1;
    *list1 = *list2;
    *list2 = temp;
}