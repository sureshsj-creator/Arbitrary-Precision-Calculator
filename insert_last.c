#include "head.h"

Status insert_last(Calc **head,Calc **tail,int data)
{
    Calc *newNode = malloc(sizeof(Calc));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return e_failure;
    }
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;

    if(*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
        return e_success;
    }
    newNode->prev = *tail;
    (*tail)->next = newNode;
    *tail = newNode;
    return e_success;
}