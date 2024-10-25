#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head = NULL;
node* createNode();
void addFirst(int);
void display();
void addLast(int);
void addAtSpecificPos(int,int);
int countNode();
void deleteFirst();
void deleteLast();
void deleteAtSpecificPos(int);

int main()
{
    addFirst(10);
    addFirst(20);
    display();
    addLast(30);
    addLast(40);
    display();
    addAtSpecificPos(90,3);
    display();
    deleteFirst();
    display();
    deleteLast();
    display();
    deleteAtSpecificPos(3);
    display();

    return 0;
}

node* createNode()
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = 0;
    newNode->next = NULL;
    return newNode;
}

void addFirst(int data)
{
    node* newNode = createNode();
    newNode->data = data;

    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else 
    {
        node *trav = head;

        while(trav->next != head)
        {
            trav = trav->next;
        }
        newNode->next = head;
        head = newNode;

        trav->next = head;
    }
}

void display()
{
    if(head == NULL)
        printf("list is empty\n");
    else
    {
        node *trav = head;
        printf("Head");

        do{
            printf("->%d",trav->data);
            trav = trav->next;
        }while(trav != head);
    }
    printf("\n");
}

void addLast(int data)
{
    node* newNode = createNode();
    newNode->data = data;

    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        node* trav = head;

        while(trav->next != head)
        {
            trav = trav->next;
        }
        trav->next = newNode;
        newNode->next = head;
    }
}


void addAtSpecificPos(int data,int pos)
{
    if(head == NULL)
    {
        if(pos==1)
        {
            addFirst(data);
        }
        else{
            printf("Invalid\n");
        }
    }
    else if(pos==1)
        addFirst(data);
    else if(pos==countNode()+1)
        addLast(data);
    else if(pos<1 || pos>countNode()+1)
        {
            printf("Invalid\n");
        }
        else{
            struct node *ptr = createNode();
            ptr->data = data;

            struct node *trav = head;
            for(int i=1; i<pos-1; i++)
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
    if(head == NULL)
        printf("list is empty\n");
    else{
        struct node *trav = head;
        do
        {
            count++;
            trav = trav->next;
        } while(trav!=head);
    }
    return count;
}

void deleteFirst()
{
    if(head == NULL)
        printf("list is empty\n");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *trav = head;
        while(trav->next != head)
        {
            trav = trav->next;
        }
        node *temp = head;

        head = temp->next;

        trav->next = head;

        free(temp);
        temp = NULL;
    }
}

void deleteLast()
{
    if(head == NULL)
        printf("list is empty\n");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *trav = head;

        while(trav->next->next != head)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = head;
    }
}

void deleteAtSpecificPos(int pos)
{
    if(head == NULL)
        printf("list is empty\n");
    else if(pos == 1)
        deleteFirst();
    else if(pos == countNode())
    {
        deleteLast();
    }
    else if(pos<1 || pos>countNode())
        printf("Invalid\n");
    else
    {
        struct node *trav = head;
        for(int i=1; i< pos-1; i++)
        {
            trav = trav->next;
        }

        struct node *temp = trav->next;

        trav->next = temp->next;

        free(temp);
        temp =NULL;
    }
}
