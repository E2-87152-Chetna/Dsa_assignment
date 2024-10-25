#include<stdio.h>
#define SIZE 6

void insertion(int arr[SIZE])
{
    int i,j,temp;

    for(i=1;i<SIZE;i++)
    {
        temp = arr[i];
        for(j=i-1;j>0 && temp <arr[j];j--)
        {
            arr[j+1] = arr[j];
        }
         arr[j+1] = temp;
    }
}
void display(int arr[SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
}

int main(){
    int arr[SIZE] ={21,23,45,67,78,76};

    display(arr);
    insertion(arr);
    display(arr);
    return 0;
}