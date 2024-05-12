#include<stdio.h>
int main()
{
	int b,h;
	float area;
	printf("Enter base and height of the triangle");
	
	scanf("%d",&b);
	scanf("%d",&h);
	area=0.5*b*h;
	printf("Area of triangle is %f",area);
	return 0;
}
