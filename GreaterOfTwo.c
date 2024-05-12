#include<stdio.h>
int main()
{
	int x,y;
	printf("Enter two numbers \n");
	scanf("%d %d",&x,&y);
	if(x>y)
	{
		printf("The greater number is %d",x);
	}
	else
	{
		printf("The greater number is %d",y);
	}
	return 0;
}
