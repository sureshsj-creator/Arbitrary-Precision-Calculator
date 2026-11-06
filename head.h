#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

typedef struct
{
    Calc *head;
    Calc *tail;
} Dlist;

Status create_list(Dlist *list, char str[]);

OperationType check_operation_type(char opt);

Status insert_last(Dlist *list, int data);

Status insert_first(Dlist *list, int data);

void print_list(Calc *head);

Status addition(Dlist *list1, Dlist *list2);

Status subtraction(Dlist *list1, Dlist *list2, int data);

void remove_leading_zeroes(Dlist* list);

int list_compare(Dlist *list1, Dlist *list2);

int data_compare(Calc *head1, Calc *head2);

void swap_list(Dlist *list1, Dlist *list2);

Status multiplication(Dlist *list1, Dlist *list2);

Status delete_list(Dlist *list);

Status add_lists(Dlist *list1, Dlist *list2);

Status division(Dlist *list1, Dlist *list2, Dlist *result);

void clear_list(Dlist* list);

#endif