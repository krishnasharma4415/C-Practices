#include<stdio.h>
#include<string.h>
#include<math.h>
int Sum(int n)
{
    int sum;
    if(n==1)
        return 1;
    else
        sum = n+Sum(n-1);
    return(sum);
}
int main()
{
    int n,result;
    printf("Enter the range : ");
    scanf("%d",&n);
    result=Sum(n);
    printf("Sum of numbers from 0-%d is : %d",n,result);
}