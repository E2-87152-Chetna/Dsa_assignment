#include <stdio.h>
#define SIZE 6
#define SWAP(a,b) int temp=a; a=b; b=temp;

void selectionSort(int arr[SIZE]);
void display(int arr[SIZE]);

int main()
{
    int arr[SIZE]={12,34,54,78,23,2};
    printf("before sorting\n");
    display(arr);
    selectionSort(arr);
    printf("after sorting\n");
    display(arr);
return 0;
}

void selectionSort(int arr[SIZE])
{
    int selPos,pos;
    int itreation=0,comparison=0;

    for(selPos=0;selPos<SIZE-1;selPos++)
    {
        itreation++;
        for(pos=selPos+1;pos<SIZE;pos++)
        {
            comparison++;
            if(arr[selPos]>arr[pos])
            {
                SWAP(arr[selPos],arr[pos]);
            }
        }
    }
    printf("\n itreation=%d , comparison=%d\n",itreation,comparison);
}

void display(int arr[SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
}
