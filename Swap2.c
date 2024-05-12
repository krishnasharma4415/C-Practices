#include<stdio.h>
main()
{
	int option;
	printf("Enter option 1 or 2");
	scanf("%d",&option);
	int a,b,c;
	printf("Enter value of two numbers a and b \n");
	scanf("%d %d",&a,&b);
	c=a;
	a=b;
	b=c;
	printf("New values after swap are %d%d",a,b);
}

