#include "head.h"

Status addition(Calc **head1, Calc **head2, Calc **tail1, Calc **tail2)
{
    Calc *headR = NULL;
    Calc *tailR = NULL;

    Calc *temp1 = *tail1;
    Calc *temp2 = *tail2;

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

    print_list(headR);

    return e_success;
}

Status insert_first(Calc **head, Calc **tail, int data)
{
    Calc *newNode = malloc(sizeof(Calc));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return e_failure;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(*head == NULL)
    {
        *head= newNode;
        *tail= newNode;
        return e_success;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
    return e_success;

}