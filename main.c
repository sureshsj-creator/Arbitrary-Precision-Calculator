#include <stdio.h>
#include "head.h"

int main(int argc,char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
        return 1;
    }
    Dlist list1 = {NULL, NULL};
    Dlist list2 = {NULL, NULL};    

    if(create_list(&list1, argv[1])== e_failure)
    {
        printf("Error: Unable to create list1.\n");
        return 1;
    }

    if(create_list(&list2, argv[3])== e_failure)
    {
        printf("Error: Unable to create list2.\n");
        return 1;
    }
   

    OperationType op = check_operation_type(argv[2][0]);
    
    if(op== e_addition)
    {
        if(addition(&list1, &list2)== e_failure)
        return 1;
    }
    else if(op== e_subtraction)
    {
        if(subtraction(&list1, &list2)== e_failure)
        return 1;
    }
    else if(op== e_multiplication)
    {
        if(multiplication(&list1, &list2)== e_failure)
        return 1;
    }
    else if(op== e_division)
    {
        if(division(&list1, &list2)== e_failure)
        return 1;
    }

}

Status create_list(Dlist *list, char str[])
{    
    int data, i=0;
    while(str[i]!='\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            printf("Error: Invalid number, Only digits 0-9 are allowed.\n");
            return e_failure;
        }


        data = str[i]-'0';
        if(insert_last(list, data)==e_failure)
        {
            printf("Data not inserted properly in list 1\n");
            return e_failure;
        }
        i++;
    }
    return e_success;
}
OperationType check_operation_type(char opt)
{
    if(opt == '+')
        return e_addition;
    else if(opt == '-')
        return e_subtraction;
    else if(opt == 'x')
        return e_multiplication;
    else if(opt == '/')
        return e_division;
    else
    {
        printf("Invalid operator %c\n",opt);
        printf("Operator should be + , - , x , /\n");
        return e_unsupported;
    }
}

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