#include<stdio.h>
#define SIZE 9

void quickSort(int arr[SIZE],int left,int right);
void display(int arr[SIZE]);
int main()
{
    int arr[SIZE] = {66,33,99,11,77,22,55,44,88};
    printf("before sort \n");
    display(arr);
    quickSort(arr,0,SIZE-1);
    printf("\n after sort: \n");
    display(arr);
    return 0;
}

void quickSort(int arr[SIZE],int left,int right)
{
    if(left >= right)
        return;

    int pivot = arr[left];
    int i = left;
    int j = right;

    while(i < j)
    {
        for(;arr[i] <= pivot; i++);
        for(;arr[j] > pivot; j--);

        if(i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;

    quickSort(arr,left,j-1);
    quickSort(arr,j+1,right);
}

void display(int arr[SIZE])
{
    for(int i=0; i<SIZE; i++)
    {
        printf("%4d",arr[i]);
    }
}