#include "head.h"

Status multiplication(Calc **head1,Calc **head2,Calc **tail1,Calc **tail2)
{
    Calc *temp1= *tail1;
    Calc *temp2= *tail2;
   
    Calc *headR1=NULL, *tailR1=NULL;
    Calc *headR2=NULL, *tailR2=NULL;

    int carry,count=0;
    int dataR,data;

    while(temp2 != NULL)
    {
        temp1 = *tail1;
        carry = 0;

        while(temp1 != NULL)
        {
            data = (temp1->data * temp2->data) + carry;

            dataR = data % 10;
            carry = data / 10;

            insert_first(&headR2, &tailR2, dataR);

            temp1 = temp1->prev;
        }

        if(carry != 0)
        {
            insert_first(&headR2, &tailR2, carry);
        }

        for(int i = 0; i < count; i++)
        {
            insert_last(&headR2, &tailR2, 0);
        }

        if(headR1 == NULL)
        {
            headR1 = headR2;
            tailR1 = tailR2;

            headR2 = NULL;
            tailR2 = NULL;
        }
        else
        {
            add_lists(&headR1, &tailR1,&headR2, &tailR2);

            delete_list(&headR2, &tailR2);
        }

        count++;
        temp2 = temp2->prev;
    }

    delete_list(head1, tail1);

    print_list(headR1);
    return e_success;
}


Status delete_list(Calc **head, Calc **tail)
{
    if(*head==NULL)
    {
        return e_failure;
    }
    
    while((*head)->next!=NULL)
    {
        *head=(*head)->next;
        free((*head)->prev);
        (*head)->prev=NULL;
    }
    if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
        *head=NULL;
        return e_success;
    }
    return e_success;
}

Status add_lists(Calc **headR1, Calc **tailR1, Calc **headR2, Calc **tailR2)
{
    Calc *temp1 = *tailR1;
    Calc *temp2 = *tailR2;

    Calc *headR = NULL;
    Calc *tailR = NULL;

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

        insert_first(&headR, &tailR, dataR);
    }

    if(carry)
    {
        insert_first(&headR, &tailR, carry);
    }

    delete_list(headR1, tailR1);

    *headR1 = headR;
    *tailR1 = tailR;

    return e_success;
}