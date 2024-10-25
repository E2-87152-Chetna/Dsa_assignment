#define SIZE 20

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