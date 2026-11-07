#include "head.h"

int result_negative = 0;
Status addition(Dlist *list1, Dlist *list2)
{
    Dlist result = {NULL, NULL};

    Calc *temp1 = list1->tail;
    Calc *temp2 = list2->tail;

    int data, dataR;
    int carry = 0;          //set carry to 0

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

        dataR = data % 10;              //extract last digit
        carry = data / 10;              //Taking Carry

        if(insert_first(&result, dataR)== e_failure)
        {
            printf("Error: Failed to insert digit during addition\n");
            return e_failure;
        }
    }

    if(carry)
    {
        insert_first(&result, carry);
    }

    if(result_negative== 1)
        printf("-");

    print_list(result.head);

    return e_success;
}

Status insert_first(Dlist *list, int data)
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

    if(list->head == NULL)
    {
        list->head= newNode;
        list->tail= newNode;
        return e_success;
    }

    newNode->next = list->head;
    list->head->prev = newNode;
    list->head= newNode;
    return e_success;

}