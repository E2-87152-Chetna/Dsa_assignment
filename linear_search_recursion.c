#include <stdio.h>
#define SIZE 9

int linear_search_recursion(int arr[SIZE],int key);
int comparisons;

int main()
{
    int arr[SIZE] = {33,55,88,77,44,11,66,22,99};
    int key,index;

    printf("enter the key to search: \n");
    scanf("%d",&key);
    printf("\nRecursive linear search: \n");
    int result = linear_search_recursion(arr,key);

    if(result == -1)
        printf("Key not found! \n");
    else
        printf("Key found at index = %d\n",result);

    printf("comparisons = %d\n",comparisons);

    return 0;
}

int linear_search_recursion(int arr[SIZE],int key)
{
    int result,index;
    for( index = 0; index < SIZE; index++)
    {
        comparisons++;
        if(key == arr[index])
        {
            result = linear_search_recursion(arr, key);  
            
        }
        return result;
    }
    return -1;
}