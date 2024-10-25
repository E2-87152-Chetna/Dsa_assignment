#include<stdio.h>
#define SIZE 9
int search(int arr[SIZE],int key);

int main()
{
   int arr[SIZE] = {11,22,33,44,55,66,77,88,99};
    int key;

    printf("enter key\n");
    scanf("%d",&key);

    int result = search(arr,key);

    if(result == -1)
    printf("key not found\n");
    else
    printf("key found %d\n",result);

    return 0;
}

int search(int arr[SIZE],int key)
{
    for(int i=0;i<SIZE;i++)

        if(key == arr[i])
        return i;
        return -1;
}