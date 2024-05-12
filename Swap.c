#include<stdio.h>
int main()
{
	int a,b,c;
	printf("Enter the values of a and b \n");
	scanf("%d %d",&a,&b);
	c=a;
	a=b;
	b=c;
	printf("New values after swapping are %d %d",a,b);
}
