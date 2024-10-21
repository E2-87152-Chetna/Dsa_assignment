#include<stdio.h>

void makeHeapMin(int arr[]);
int deleteMin(int arr[]);
int display(int arr[]);
void heapSort(int arr[]);

int size =10;

int main()
{
    int arr[11] = {0,20,12,35,15,10,80,30,17,2,1};
    display(arr);
    makeHeapMin(arr);
    heapSort(arr);
    display(arr);
    return 0;
}

void makeHeapMin(int arr[])
{
    for(int i = size/2; i>=1; i--)
    {
        int ci = i*2;

        while(ci <= size)
        {
            int pi = ci/2;
            if((ci+1) <= size && arr[ci+1] > arr[ci]);
                ci = ci+1;

            if(arr[pi] < arr[ci])
                break;

            int temp = arr[ci];
            arr[ci] = arr[pi];
            arr[pi] = temp;

            ci = ci*2;
        }
    }
}

int deleteMin(int arr[])
{
    int min = arr[1];
    arr[1] = arr[size];
    arr[size] = min;
    size--;

    int ci = 1*2;

    while(ci <= size)
    {
        int pi = ci/2;
        if((ci+1) <= size && arr[ci+1] < arr[ci])
             ci = ci+1;

        if(arr[pi] < arr[ci])
        break;

        int temp = arr[ci];
        arr[ci] = arr[pi];
        arr[pi] = temp;

        ci = ci*2;
    }
    return min;
}

int display(int arr[])
{
    for(int i=1; i<11; i++)
    {
        printf("%4d",arr[i]);
    }
    printf("\n");
}

void heapSort(int arr[])
{
    makeHeapMin(arr);

    for(int i=1; i< 11; i++)
    {
        deleteMin(arr);
    }
    printf("\n");
}