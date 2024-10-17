#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void addFirst(int);
void display();
void reverse();

struct node *createNode();

int main()
{
    addFirst(10);
    addFirst(20);
    addFirst(30);
    addFirst(40);
    addFirst(50);
    display();
    printf("Reverse\n");
    reverse();
    display();
    return 0;
}

struct node *createNode()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = 0;
    ptr->next = NULL;

    return ptr;
}

void addFirst(int data)
{
    struct node *ptr = createNode();
    ptr->data = data;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
}

void reverse()
{
    struct node *n1 = head;
    struct node *n2 = head->next;
    while (n2 != NULL)
    {
        struct node *n3 = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = n3;
    }
    head->next = NULL;
    head = n1;
}

void display()
{
    if (head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        struct node *trav = head;
        printf("Head");
        while (trav != NULL)
        {
            printf("->%d", trav->data);
            trav = trav->next;
        }
    }
    printf("\n");
}
