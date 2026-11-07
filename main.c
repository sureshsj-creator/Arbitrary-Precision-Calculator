#include "head.h"

int main(int argc,char *argv[])
{
    int sign1 = 1; //Positive
    int sign2 = 1; //Positive
    if (argc != 4)
    {
        printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
        return 1;
    }

    if(argv[1][0]== '-')
    sign1 = -1;
    if(argv[3][0]== '-')
    sign2 = -1;

    Dlist list1 = {NULL, NULL};
    Dlist list2 = {NULL, NULL};    
    Dlist result = {NULL, NULL};

    if(create_list(&list1, argv[1])== e_failure)        //Create list for Operand 1
    {
        printf("Error: Unable to create list1.\n");
        return 1;
    }

    if(create_list(&list2, argv[3])== e_failure)        //Create list for Operand 2
    {
        printf("Error: Unable to create list2.\n");
        return 1;
    }
   

    OperationType op = check_operation_type(argv[2][0]);     //Check Operator

    if(op == e_addition || op == e_subtraction)
    {
        if(op == e_subtraction)
            sign2 = -sign2;

        if(sign1 == sign2)
        {
            result_negative = (sign1 == -1);

            if(addition(&list1, &list2) == e_failure)
                return 1;

            result_negative = 0;
        }
        else
        {
            int cmp = list_compare(&list1, &list2);

            if(cmp == NOSWAP)
            {
                if(subtraction(&list1, &list2, 0) == e_failure)
                    return 1;

                if(sign1 == -1 && !(list1.head->data == 0 && list1.head == list1.tail))
                    printf("-");

                print_list(list1.head);
            }
            else if(cmp == SWAP)
            {
                if(subtraction(&list2, &list1, 0) == e_failure)
                    return 1;

                if(sign2 == -1 && !(list2.head->data == 0 && list2.head == list2.tail))
                    printf("-");

                    print_list(list2.head);
            }
        }
    }
    else if(op == e_multiplication)
    {
        int zero1 = 1, zero2 = 1;

        Calc *temp = list1.head;

        while(temp)
        {
            if(temp->data != 0)
                zero1 = 0;

            temp = temp->next;
        }

        temp = list2.head;

        while(temp)
        {
            if(temp->data != 0)
                zero2 = 0;

            temp = temp->next;
        }

        if(sign1 != sign2 && !zero1 && !zero2)
            printf("-");

        if(multiplication(&list1, &list2) == e_failure)
            return 1;
    }
    else if(op == e_division)
    {
        int zero1 = 1, zero2 = 1;

        Calc *temp = list1.head;

        while(temp)
        {
            if(temp->data != 0)
                zero1 = 0;

            temp = temp->next;
        }

        temp = list2.head;

        while(temp)
        {
            if(temp->data != 0)
                zero2 = 0;

            temp = temp->next;
        }

        if(sign1 != sign2 && !zero1 && !zero2)
            printf("-");

        if(division(&list1, &list2, &result) == e_failure)
            return 1;
    }
    else
    {
        return 1;
    }
    return 0;
}

Status create_list(Dlist *list, char str[])
{    
    int data, i=0;

    if(str[i]== '+' || str[i]== '-')  //check first character is sign
    i++;

    if(str[i]== '\0')               //if empty return failure
    return e_failure;

    while(str[i]!='\0')
    {
        if(str[i] < '0' || str[i] > '9')            //check if Operands contains any other characters
        {
            printf("Error: Invalid number, Only digits 0-9 are allowed.\n");
            return e_failure;
        }


        data = str[i]-'0';                          //a to i
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
        printf("Operator should be + , - , x , /.\n");
        return e_unsupported;
    }
}

Status insert_last(Dlist *list, int data)
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

    if(list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        return e_success;
    }
    newNode->prev = list->tail;
    list->tail->next = newNode;
    list->tail = newNode;
    return e_success;
}