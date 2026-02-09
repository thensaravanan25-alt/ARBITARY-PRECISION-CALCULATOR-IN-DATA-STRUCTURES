#ifndef DLL_H
#define DLL_L

#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 1
#define FAILURE -2
#define LIST1 3
#define LIST2 4
#define EQUAL 5

typedef struct Double_list
{
    int data;
    struct Double_list *prev;
    struct Double_list *next;
}Node;

extern int flag ;
int add_function      ( Node **head, Node **tail , Node **head2 , Node **tail2  , Node **headR , Node **tailR);
void subtract_function( Node **head, Node **tail , Node **head2 , Node **tail2  , Node **headR , Node **tailR );

int multiply_function( Node **head, Node **tail , Node **head2 , Node **tail2 , Node **headR , Node **tailR);
int division_function( Node **head, Node **tail , Node **head2 , Node **tail2 , Node **headR , Node **tailR);

int compare_list_fun  (Node *head, Node *tail , Node *head2 , Node *tail2  );

int is_zero_list (Node *head);

int insert_first     (Node **headR , Node **tailR , int num);

int print_node(Node *headR);

int delete_list(Node **headR2 , Node **tailR2);

int insertend(Node **headR , Node **tailR , int num);

void remove_zero(Node **head, Node **tail);

#endif