#include<stdio.h>

/*void create(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d\t",arr[i]);
    }
}*/

void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

int main()
{
    int size = 5;
    /*printf("Enter the number of elements:\t");
    scanf("%d",&num);*/
    int arr[100] = {1,2,3,4,5};
    //create(arr,num);
    display(arr,5);
    return 0;
}