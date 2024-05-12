#include<stdio.h>
int main()
{
	int n,d=0,y;
	printf("Enter a number");
	scanf("%d",&n);
	
	while(d<n)
	{
		if((n%d)==0)
		{
			y++;
		}
	}
	if(y==2)
	{
		printf("Prime No.");
	}
	else
	{
		printf("NOT Prime");
	}
	return 0;
}
