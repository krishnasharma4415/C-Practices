#include<stdio.h>
int main()
{
    int rows,columns;
    printf("Enter the number of rows \n");
    scanf("%d",&rows);
    printf("Enter the number of columns \n");
    scanf("%d",&columns);
    int a[rows][columns],b[rows][columns];

    printf("Enter elements of First matrix\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            //printf("Enter element [%d][%d]\n",i,j);
            scanf("%d\t",&a[i][j]);
        }
        printf("\n");
    }
    /*printf("Entered matrix is \n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/

    printf("Enter elements of Second matrix\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            //printf("Enter element [%d][%d]\n",i,j);
            scanf("%d\t",&b[i][j]);
        }
        printf("\n");
    }
    /*printf("Entered matrix is \n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }*/

    printf("Sum of Matrix is:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            printf("%d \t",a[i][j] + b[i][j]);
        }
        printf("\n");
    }
    printf("Difference of matrix :");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<rows;j++)
        {
            printf("%d\t",a[i][j]-b[i][j]);
        }
        printf("\n");
    }
}