#include <stdio.h>
#include "head.h"

int main(int argc,char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
        return 1;
    }
    Calc *head1 = NULL;
    Calc *head2 = NULL;
    Calc *tail1 = NULL;
    Calc *tail2 = NULL;

    char *str1 = argv[1];
    char *str2 = argv[3];

    int data,i=0;
    

    while(str1[i]!='\0')
    {

        data = str1[i]-'0';
        if(insert_last(&head1,&tail1,data)==e_failure)
        {
            printf("Data not inserted properly in list 1\n");
            return 1;
        }
        i++;
    }
    i=0;
    while(str2[i]!='\0')
    {
        data = str2[i]-'0';
        if(insert_last(&head2,&tail2,data)==e_failure)
        {
            printf("Data not inserted properly in list 2\n");
            return 1;
        }
        i++;
    }

    OperationType op = check_operation_type(argv[2][0]);
    
    if(op== e_addition)
    {
        if(addition(&head1,&head2,&tail1,&tail2)== e_failure)
        return 1;
    }
    else if(op== e_subtraction)
    {
        if(subtraction(&head1,&head2,&tail1,&tail2)== e_failure)
        return 1;
    }

}


OperationType check_operation_type(char opt)
{
    if(opt == '+')
        return e_addition;
    else if(opt == '-')
        return e_subtraction;
    else if(opt == '*')
        return e_multiplication;
    else if(opt == '/')
        return e_division;
    else
    {
        printf("Invalid operator\n");
        printf("Operator should be + , - , * , /\n");
        return e_unsupported;
    }
}