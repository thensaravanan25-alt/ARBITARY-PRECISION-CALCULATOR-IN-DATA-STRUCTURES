#include "dll.h"

void free_list(Node **head, Node **tail)
{
    Node *temp;
    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *tail = NULL;
}

void trim_leading_zeros(Node **head, Node **tail)
{
    Node *temp;
    while (*head && (*head)->data == 0 && (*head)->next)
    {
        temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

int division_function(Node **head, Node **tail, Node **head2, Node **tail2, Node **headR, Node **tailR)
{
    Node *tempH = NULL, *tempT = NULL;
    Node *qH = NULL, *qT = NULL;

    // quotient = 0
    *headR = NULL;
    *tailR = NULL;
    insert_first(headR, tailR, 0);

    // constant 1
    Node *oneH = NULL, *oneT = NULL;
    insert_first(&oneH, &oneT, 1);

    if (compare_list_fun(*head, *tail, *head2, *tail2) < 0)
        return SUCCESS;

    while (compare_list_fun(*head, *tail, *head2, *tail2) >= 0)
    {
        tempH = tempT = NULL;

        subtract_function(head, tail, head2, tail2, &tempH, &tempT);
        trim_leading_zeros(&tempH, &tempT);

        free_list(head, tail);
        *head = tempH;
        *tail = tempT;

        // quotient = quotient + 1 (CORRECT WAY)
        qH = qT = NULL;
        add_function(headR, tailR, &oneH, &oneT, &qH, &qT);

        free_list(headR, tailR);
        *headR = qH;
        *tailR = qT;
    }

    trim_leading_zeros(headR, tailR);
    return SUCCESS;
}