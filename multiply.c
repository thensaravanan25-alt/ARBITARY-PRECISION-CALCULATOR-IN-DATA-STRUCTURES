#include "dll.h"

int delete_list(Node **head, Node **tail)
{
    Node *temp;

    if (*head == NULL)
        return SUCCESS;

    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *tail = NULL;
    return SUCCESS;
}

int multiply_function(Node **head, Node **tail, Node **head2, Node **tail2, Node **headR, Node **tailR)
{
    Node *temp1, *temp2;
    Node *headR1 = NULL, *tailR1 = NULL;
    Node *headR2 = NULL, *tailR2 = NULL;

    int res, carry, count = 0;

    *headR = NULL;
    *tailR = NULL;

    temp2 = *tail2;

    while (temp2)
    {
        temp1 = *tail;
        carry = 0;

        /* Add zeros for shifting */
        for (int i = 0; i < count; i++)
            insert_first(&headR2, &tailR2, 0);

        while (temp1)
        {
            res = (temp2->data * temp1->data) + carry;
            carry = res / 10;
            res   = res % 10;

            insert_first(&headR2, &tailR2, res);

            temp1 = temp1->prev;
        }

        if (carry)
            insert_first(&headR2, &tailR2, carry);

        if (count == 0)
        {
            headR1 = headR2;
            tailR1 = tailR2;
        }
        else
        {
            add_function(&headR1, &tailR1, &headR2, &tailR2, headR, tailR);

            delete_list(&headR1, &tailR1);
            delete_list(&headR2, &tailR2);

            headR1 = *headR;
            tailR1 = *tailR;
        }

        headR2 = tailR2 = NULL;
        count++;
        temp2 = temp2->prev;
    }

    *headR = headR1;
    *tailR = tailR1;

    return SUCCESS;
}