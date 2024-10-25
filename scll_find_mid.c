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
node *find_mid();


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
    node *mid = find_mid();
    printf("mid = %d\n",mid->data);

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
node *find_mid()
{
    node *slow = head;
    node *fast = head;
    do{
    slow = slow->next;
    fast = fast->next->next;
    if(fast == head) // for even no. of nodes
        break;
    }while(fast->next != head); // for odd no. of nodes

    return slow;
}

