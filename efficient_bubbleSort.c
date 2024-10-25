#include <stdio.h>
#define SIZE 6
#define SWAP(a,b) int temp=a; a=b; b=temp;

void efficientBubbleSort(int arr[SIZE]);
void display(int arr[SIZE]);

int main()
{
    int arr[SIZE]={1,2,3,4,5,6};

    printf("before swap\n");
    display(arr);
    efficientBubbleSort(arr);
    printf("after swap\n");
    display(arr);
    return 0;
}

void efficientBubbleSort(int arr[SIZE])
{
    int ite,pos,flag;
    int iteration=0,comparison=0;

    for(ite=0;ite<SIZE-1;ite++)
    {
        flag=0;
        iteration++;
        for(pos=0;pos<SIZE-1-ite;pos++)
        {
            comparison++;
            if(arr[pos]>arr[pos+1])
            {
                SWAP(arr[pos],arr[pos+1]);
                flag=1;
            }
        }
        if(flag==0)
        break;
    }
    printf("iteration=%d,comparison=%d\n",iteration,comparison);
}

void display(int arr[SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
}