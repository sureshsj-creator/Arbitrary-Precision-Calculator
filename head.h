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

/* Create List for Operand */
Status create_list(Dlist *list, char str[]);

/* Check Operation type */
OperationType check_operation_type(char opt);

/* Insert at last in the list */
Status insert_last(Dlist *list, int data);

/* Insert at first in the list */
Status insert_first(Dlist *list, int data);

/* Print the list(Result) */
void print_list(Calc *head);

/* Extern keyword for Sign */
extern int result_negative;

/* Addition Operation */
Status addition(Dlist *list1, Dlist *list2);

/* Subtraction Operation */
Status subtraction(Dlist *list1, Dlist *list2, int data);

/* Remove leading Zeros */
void remove_leading_zeroes(Dlist* list);

/* Compare Lists , First Operand digits count greater than second */
int list_compare(Dlist *list1, Dlist *list2);

/* Compare the data which is greater */
int data_compare(Calc *head1, Calc *head2);

/* Swap the lists */
void swap_list(Dlist *list1, Dlist *list2);

/* Multiplication Operation */
Status multiplication(Dlist *list1, Dlist *list2);

/* Delete list*/
Status delete_list(Dlist *list);

/* add lists */
Status add_lists(Dlist *list1, Dlist *list2);

/* Division Operation */
Status division(Dlist *list1, Dlist *list2, Dlist *result);

/* Clear list */
void clear_list(Dlist* list);

#endif