#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct stack
{
    int arr[SIZE];
    int top;
}stack;

void init_stack(stack *ps);
int stack_empty(stack *ps);
int stack_full(stack *ps);
int peek(stack *ps);
void pop(stack *ps);
void push(int data, stack *ps);
 int main()
{
    stack S;
    init_stack(&S);

    int choice;

    do{
        printf("0.Exit\n1.Push\n2.Pop\n3.Peek :\n");
    printf("enter the choice :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0:
                exit(0);
        case 1:
                if(stack_full(&S))
                {
                    printf("Stack Full !\n");
                }
                else
                {
                    int data;
                    printf("enter the data :");
                    scanf("%d",&data);
                    push(data,&S);
                    printf("Data Entered = %d\n",data);
                }
                break;
        case 2: // Pop
                if(stack_empty(&S))
                {
                    printf("Stack empty !\n");
                }
                else
                {
                    int element = peek(&S);
                    pop(&S);
                    printf("data Popped = %d\n",element);
                }
                break;
        case 3: // Peek
                if(stack_empty(&S))
                {
                    printf("Satck Empty !\n");
                }
                else
                {
                    int ele = peek(&S);
                    printf("TopMost element = %d\n",ele);
                }
                break;
        default :
                printf("Invalid Choice !\n");
    }
}while(choice != 0);
    return 0;
}

void init_stack(stack *ps)
{
    ps->top = -1;
}

void push(int data, stack *ps)
{
    // increment the top
    ps->top++;
    // insert the data at the top index
    ps->arr[ps->top] = data;
}

void pop(stack *ps)
{
    ps->arr[ps->top] = 0;

    ps->top--;
}


int peek(stack *ps)
{
    return ps->arr[ps->top];
}


int stack_full(stack *ps)
{
    return ps->top == SIZE-1;
}

int stack_empty(stack *ps)
{
    return ps->top == -1;
}
 
