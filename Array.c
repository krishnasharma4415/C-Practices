void main()
{
    int r,c;
    printf("Enter the number of rows");
    scanf("%d",&r);
    printf("Enter the number of column");
    scanf("%d",&c);
    int a[r][c],b[r][c],c[r][c];
    printf("Enter elements of 1st Matrix");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d\t",&a[i][j]);
        }
        printf("\n");
    }
    printf("Enter elements of 2nd Matrix");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d\t",&b[i][j]);
        }
        printf("\n");
    }
    char op;
    printf("Enter the type of Arithmatic Operation (+,-,*) : ");
    scanf("%d",&op);
    if(op=='+');
    {
        printf("Sum of Matrix is:\n");
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                printf("%d\t",a[i][j] + b[i][j]);
            }
            printf("\n");
        }
    }
    else if(op=='-')
    {
        printf("Difference of Matrix is:\n");
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                printf("%d\t",a[i][j] - b[i][j]);
            }
            printf("\n");
        }
    }
    else if(op=='*')
    {
        printf("Product of Matrix is:\n");
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                for(int k=0;k<c;k++)
                {
                    c[i][j] += a[i][k]*b[k][j];
                }
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                printf("%d\t",c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Wrong Choice");
    }
}
