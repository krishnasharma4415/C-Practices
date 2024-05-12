#include<stdio.h>
int main()
{
	int x,y,z;
	printf("Enter the value of three numbers \n");
	scanf("%d %d %d",&x,&y,&z);
	if((x>y)&&(x>z))
	{
		printf("The greater number is %d ",x);
	}
	else if((y>x)&&(y>z))
	{
		printf("The greater number is %d ",y);
	}
	else if((z>x)&&(z>y))
	{
		printf("The greater number is %d ",z);
	}
	return 0;
}
