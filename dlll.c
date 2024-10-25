#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node* next;
}node;

node *head = NULL;
node *tail = NULL;

node* createNode();
void addFirst(int data);
void forwardDisplay();
void backwardDisplay();
void addLast(int data);
void addAtSpecificPos(int ,int);
int countNode();
void deleteFirst();
void deleteLast();
void deleteAtSpecificPos(int);

int main()
{   
    addFirst(40);
    addFirst(35);
    addFirst(20);
    addLast(95);
    addLast(50);
    addFirst(60);
    forwardDisplay();
    backwardDisplay();
 
    addAtSpecificPos(80,4);
    forwardDisplay();
    backwardDisplay();

    deleteFirst();
    forwardDisplay();
    backwardDisplay();

    deleteLast();
    forwardDisplay();
    backwardDisplay();

    deleteAtSpecificPos(3);
    forwardDisplay();
    backwardDisplay();
    return 0;
}

node* createNode()
{
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL)
    {
        printf("malloc failed\n");
    }
    else
    {
        newNode->data = 0;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    return newNode;
}

void addFirst(int data)
{
    struct node* newNode = createNode();
    newNode->data = data;

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void forwardDisplay()
{
    if(head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        struct node* trav = head;

        printf("head");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }
    }
    printf("\n");
}

void backwardDisplay()
{
    if(head == NULL)
    {
        printf("list is empty\n");
    }
    else 
    {
        struct node *trav = tail;

        printf("tail");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->prev;
        }
    }
    printf("\n");
}

void addLast(int data)
{
    node *newNode = createNode();
    newNode->data = data;

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void addAtSpecificPos(int data ,int pos)
{
    if(head == NULL)
    {
        if(pos == 1)
            addFirst(data);
        else
            printf("Invalid\n");
    }else if(pos ==1)
        addFirst(data);
    else if(pos == countNode()+1)
        addLast(data);
    else if(pos < 1 || pos> countNode()+1)
        printf("Invalid\n");
    else
    {
        struct node *newnode = createNode();
        newnode->data = data;

        node *trav = head;
        for(int i=1; i<pos-1;i++)
        {
            trav = trav->next;
        }
        newnode->prev = trav;
        newnode->next = trav->next;
        trav->next = newnode;
        newnode->next->prev = newnode;
    }
}

int countNode()
{
    int count =0;
    if(head == NULL)
        printf("list is empty\n");
    else
    {
        struct node *trav = head;
        
        while(trav != NULL)
        {
            count++;
            trav = trav->next;
        }
    }
    return count;
}

void deleteFirst()
{
    if(head == NULL)
        printf("list is empty\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *temp = head;
        head = head->next;

        head->prev = NULL;

        free(temp);
        temp = NULL;
    }
}

void deleteLast()
{
    if(head == NULL)
        printf("list is empty\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *temp = tail;
        tail = temp->prev;
        tail->next = NULL;

        free(temp);
        temp = NULL;
    }
}

void deleteAtSpecificPos(int pos)
{
    if(head == NULL)
        printf("list is empty\n");
    else if(pos == 1)
        deleteFirst();
    else if(pos == countNode())
        deleteLast();
    else if(pos<1 || pos>countNode())
        printf("Invalid\n");
    else
    {
        node *trav = head;
        for(int i=1; i<pos; i++)
        {
            trav = trav->next;
        }
        trav->prev->next = trav->next;
        trav->next->prev = trav->prev;

        free(trav);
        trav = NULL;
    }
}