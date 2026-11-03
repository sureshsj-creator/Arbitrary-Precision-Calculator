#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>
#include<stdlib.h>

#define SWAP 1
#define NOSWAP 0

typedef enum
{
    e_success,
    e_failure
} Status;

typedef enum
{
    e_addition,
    e_subtraction,
    e_multiplication,
    e_division,
    e_unsupported
}OperationType;

typedef struct calc
{
    int data;
    struct calc *prev;
    struct calc *next;

}Calc;

OperationType check_operation_type(char opt);

Status insert_last(Calc **head, Calc **tail,int data);

Status insert_first(Calc **head, Calc **tail,int data);

void print_list(Calc *head);

Status addition(Calc **head1,Calc **head2,Calc **tail1,Calc **tail2);

Status subtraction(Calc **head1,Calc **head2,Calc **tail1,Calc **tail2);

int list_compare(Calc *head1,Calc *head2);

int data_compare(Calc *head1,Calc *head2);

void swap_list(Calc **head1,Calc **head2,Calc **list1,Calc **list2);

Status multiplication(Calc **head1,Calc **head2,Calc **tail1,Calc **tail2);

Status delete_list(Calc **head, Calc **tail);

Status add_lists(Calc **headR1, Calc **tailR1, Calc **headR2, Calc **tailR2);

#endif