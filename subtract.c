#include "dll.h"



void subtract_function(Node **head, Node **tail,  Node **head2, Node **tail2  , Node **headR , Node **tailR )
{
    Node *temp1 = *tail;
    Node *temp2 = *tail2;

    *headR  = NULL;
    *tailR =  NULL;

    int borrow = 0;
    int diff;

    while (temp1 || temp2)
    {
        int d1 = temp1 ? temp1->data : 0;
        int d2 = temp2 ? temp2->data : 0;

        d1 = d1 - borrow;

        if (d1 < d2)
        {
            d1 += 10;
            borrow = 1;
        }
        else
            borrow = 0;

        diff = d1 - d2;
        insert_first( headR, tailR , diff);

        if (temp1) temp1 = temp1->prev;
        if (temp2) temp2 = temp2->prev;
    }

   
    if (flag == 1)
    {
        insert_first (headR , tailR , -1);
    }

   
}