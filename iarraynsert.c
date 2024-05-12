//Program to find sum of elements of array
#include<stdio.h>
int main()
{
    int n,sum=0;
    printf("Enter the size of array \n  ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }
    printf("Sum of elements : %d",sum);
}