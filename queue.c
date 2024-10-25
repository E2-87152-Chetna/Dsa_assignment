#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct queue
{
    int arr[SIZE];
    int front;
    int rear;
};

void init(struct queue *q)
{
    q->rear = -1;
    q->front = -1;
}

void en(int data,struct queue *q){
    q->rear++;
    q->arr[q->rear] = data;

    if(q->front==-1)
    q->front = 0;
}

void de(struct queue *q)
{
    q->arr[q->front]=0;
    q->front++;

}

int peek(struct queue *q)
{
    return q->arr[q->front];
}

int full(struct queue *q)
{
    if(q->rear == SIZE-1)
    return 1;
    else
    return 0; 
}

int empty(struct queue *q)
{
    if(q->rear == -1 || q->front > q->rear)
    return 1;
    else
    return 0;
}

int main()
{
    struct queue Q;

    init(&Q);

    int choice;

    do
    {
        printf("enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: exit(0);
            case 1: if(full(&Q))
            {
                printf("full\n");
            }
            else{
                int data;
                printf("enter data ");
                scanf("%d",&data);
                en(data,&Q);
                printf("data = %d\n",data);
            }
            break;
        case 3:
        if(empty(&Q))
        {
            printf("empty\n");
        }
        else
        {
            int element = peek(&Q);
            de(&Q);
            printf("data deleted: %d\n",element);
        }
        break;
        case 4:
        

        }
    } while (choice!=0);
    
}