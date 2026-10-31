#include "head.h"

Status subtraction(Calc **head1, Calc **head2, Calc **tail1, Calc **tail2)
{
    int ret = list_compare(*head1,*head2);
    int sign = 1;
    if(ret)
    {
        sign = -1;
        swap_list(head1,head2,tail1,tail2);
    }
    int data,dataR,borrow= 0;
    Calc *temp1= *tail1;
    Calc *temp2= *tail2;

    Calc *headR= NULL;
    Calc *tailR= NULL;
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
        insert_first(&headR,&tailR,dataR);
        temp1= temp1->prev;
    }
    headR->data= headR->data*sign;
    print_list(headR);
}

int list_compare(Calc *head1, Calc *head2)
{
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
    return 0;
    else if(list1_count < list2_count)
    return 1;
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
        return 0;
        else if(head1->data < head2->data)
        return 1;
        else
        {
            head1= head1->next;
            head2= head2->next;
        }
    }
    return 0;
}

void swap_list(Calc **head1,Calc **head2,Calc **tail1,Calc **tail2)
{
    
    Calc *temp1= *head1;
    *head1 = *head2;
    *head2 = temp1;

    Calc *temp2= *tail1;
    *tail1 = *tail2;
    *tail2 = temp2;
}