#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

struct linearQueue
{
    int arr[SIZE];
    int rear;
    int front;
};

void initQueue(struct linearQueue *q);
void enqueue(int data,struct linearQueue *q);
void dequeue(struct linearQueue *q);
int peek(struct linearQueue *q);
int queueFull(struct linearQueue *q);
int queueEmpty(struct linearQueue *q);

int main()
{
    struct linearQueue Q;
    initQueue(&Q);
    int choice;

    do{
        printf("0. Exit\n1. Insert data\n2. Delete data\n3. Peek data\n");
        printf("Enter your choice =  ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
                    exit(0);
            
            case 1:
                    if (queueFull(&Q))
                    {
                        printf("Queue is full\n");
                    }
                    else{
                        int data;
                        printf("Enter the number = ");
                        scanf("%d",&data);
                        enqueue(data,&Q);
                        printf("data insert = %d\n",data);
                    }
                    break;

            case 2:
                    if (queueEmpty(&Q))
                    {
                        printf("Queue is empty\n");
                    }
                    else
                    {
                      int element = peek(&Q);
                      dequeue(&Q);
                      printf("data delete = %d\n",element);
                    }
                    break;

            case 3:
                    if(queueEmpty(&Q))
                        printf("queue is empty\n");
                    else
                    {
                        int element = peek(&Q);
                        printf("front most element =%d \n",element);
                    }
                    break;

            default :
                    printf("invalid choice\n");
        }
    }while(choice!=0);
        return 0;
}
void initQueue(struct linearQueue *q)
{
    q-> rear = -1;
    q-> front = -1;
}

void enqueue(int data,struct linearQueue *q)
{
    q-> rear++;
    q-> arr[q->rear] = data;

    if(q-> front == -1);
        q-> front = 0;
}

void dequeue(struct linearQueue *q)
{
    //optional
    q->arr[q->front] = 0;
    q->front++;
}

int peek(struct linearQueue *q)
{
    return q->arr[q->front];

}

int queueFull(struct linearQueue *q)
{
    if(q->rear == SIZE-1)
        return 1;
    else
        return 0;
}

int queueEmpty(struct linearQueue *q)
{
    if(q->rear == -1 || q->front > q->rear)
        return 1;
    else
        return 0;
}