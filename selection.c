#include<stdio.h>
#define SIZE 6
#define SWAP(a,b) int temp=a; a=b; b=temp;

void selection(int arr[SIZE]);
void display(int arr[SIZE]);

int main()
{
    int arr[SIZE] = {11,22,33,4 ,25,67};
    display(arr);
    selection(arr);
    printf("after dort\n");
    display(arr);

    return 0;
}

void selection(int arr[SIZE])
{
    int selPos,pos;

    for(selPos=0;selPos<SIZE-1;selPos++)
    {
        for(pos=selPos+1;pos<SIZE;pos++)
        {
            if(arr[selPos]>arr[pos])
            {
                SWAP(arr[selPos],arr[pos]);
            }
        }
    }
}

void display(int arr[SIZE])
{
    for(int i=0;i<SIZE;i++)
    printf("%4d",arr[i]);
}