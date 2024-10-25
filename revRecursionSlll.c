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
struct node* revRecursion(struct node*);
//int countNode();

struct node* createNode();

int main()
{
    addFirst(50);
    addFirst(40);
    addFirst(30);
    addFirst(20);
    addFirst(10);
    display();
    printf("after reverse\n");
    //int result = revRecursion();
    struct node* result = revRecursion(head);
    display();
    return 0;
}

struct node* createNode()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data = 0;
    ptr->next = NULL;

    return ptr;
};

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

struct node* revRecursion(struct node* head) 
{
    
    struct node *n1 = head;
    struct node *n2 = head->next;

    if(head == NULL || head->next == NULL )
          return head;
    

    struct node* result = revRecursion(head->next);
    
    head->next->next = head;
    head->next = NULL;

    return result;
    
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


