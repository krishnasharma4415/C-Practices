#include<stdio.h>
int SumOfDigits()
{
    int n1,n2;
    printf("Enter 1st digit : ");
    scanf("%d",&n1);
    printf("Enter 2nd digit : ");
    scanf("%d",&n2);
    printf("Sum of Digits : %d\n",(n1+n2));
}
int Reverse()
{
    int num,revnum=0,digit;
    printf("Enter Number : ");
    scanf("%d",&num);
    while(num>0)
    {
        digit=num%10;
        revnum=revnum*10+digit;
        num=num/10;
    }
    printf("Reverse of number is : %d\n",revnum);
}
void PrimeNo()
{
    int start,end,check=0;
    printf("Enter start value : ");
    scanf("%d",&start);
    printf("Enter end value : ");
    scanf("%d",&end);
    for(int i=start;i<=end;i++)
    {
        check=0;
        for(int j=1;j<i;j++)
        {
            if(i%j==0)
            {
                check++;
            }
        }
        if(check<2)
        {
            printf("%d\t",i);
        }
    }
}
int Factorial()
{
    int num,fact=1;
    printf("Enter the number : ");
    scanf("%d",&num);
    for(int i=num;i>1;i--)
    {
        fact = fact * i;
    }
    printf("Factorial of entered is : %d",fact);
}
void main()
{
    printf("WELCOME \n");
    PrimeNo();
}
