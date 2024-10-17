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
void addLast(int);
int countNode();
void addAtSpecificPos(int, int);
struct node *search(int key);

struct node *createNode();

int main()
{
    addFirst(10);
    addFirst(20);
    display();
    addLast(30);
    addLast(40);
    display();
    addAtSpecificPos(90, 3);
    display();

    struct node *result;
    result = search(20);
    if (result == NULL)
        printf("Key not found \n");
    else
        printf("Key found !\n");

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

void addLast(int data)
{
    struct node *ptr = createNode();
    ptr->data = data;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        struct node *trav = head;

        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = ptr;
    }
}

void addAtSpecificPos(int data, int pos)
{
    if (head == NULL)
    {
        if (pos == 1)
        {
            addFirst(data);
        }
        else
        {
            printf("Invalid\n");
        }
    }
    else if (pos == 1)
        addFirst(data);
    else if (pos == countNode() + 1)
        addLast(data);
    else if (pos < 1 || pos > countNode() + 1)
    {
        printf("Invalid\n");
    }
    else
    {
        struct node *ptr = createNode();
        ptr->data = data;

        struct node *trav = head;
        for (int i = 1; i < pos - 1; i++)
        {
            trav = trav->next;
        }

        ptr->next = trav->next;
        trav->next = ptr;
    }
}

int countNode()
{
    int count = 0;
    if (head == NULL)
        printf("list is empty\n");
    else
    {
        struct node *trav = head;
        while (trav != NULL)
        {
            count++;
            trav = trav->next;
        }
    }
    return count;
}

struct node *search(int key)
{
    struct node *trav = head;
    while (trav != NULL)
    {
        if (trav->data == key)
            return trav;
        trav = trav->next;
    }
    return NULL; // key not found.
}