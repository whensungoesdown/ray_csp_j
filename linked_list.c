//
//  Enter the number of data items n: 5
//  Enter 5 integers:
//  10 20 30 40 50
//  Linked list contents: 10 20 30 40 50
//

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main(void)
{
    int n;
    struct node *head = NULL;
    struct node *tail = NULL;

    printf("Enter the number of data items n: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);

        struct node *p = (struct node *)malloc(sizeof(struct node));

        if (p == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        p->data = value;
        p->next = NULL;

        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }

    printf("Linked list contents: ");

    for (struct node *p = head; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }

    printf("\n");

    struct node *p = head;

    while (p != NULL)
    {
        struct node *tmp = p->next;
        free(p);
        p = tmp;
    }

    return 0;
}
