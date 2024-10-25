#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void addFirst(int);
void display();
void deleteLast();


struct node* createNode();

int main()
{
    addFirst(10);
    addFirst(20);
    addFirst(30);
    display();
    deleteLast();
    display();
}

struct node* createNode()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data = 0;
    ptr->next = NULL;

    return ptr;
}

void addFirst(int data)
{
    struct node *ptr = createNode();
    ptr->data = data;

    if(head == NULL)
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
    if(head == NULL)
    {
        printf("list is empty\n");

    }
    else
    {
        struct node *trav = head;
        printf("Head");
        while(trav!= NULL)
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }
    }
    printf("\n");
}

void deleteLast()
{
    if(head == NULL)
    {
        printf("list is empty\n");
    }
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else{
        struct node *trav=head;

        while(trav->next->next!= NULL)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = NULL;
    }
}