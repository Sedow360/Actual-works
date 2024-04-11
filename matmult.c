
#include <stdio.h>
#include <math.h>

int main()
{
    int c1, r1, r2, c2; 

    for (int i = 0; ; i++)
    {
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d%d", &r2, &c2);

    if (c1!=r2)
    { printf("Cannot multiply the matrices.\n Please try again!\n"); }
    else {break;}
    }

    int a[r1][c1], b[r2][c2], pro[r1][c2];

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("Enter the value of %d row and %d column of the first matrix: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
        
    }

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("Enter the value of %d row and %d column of the second matrix: ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
        
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            pro[i][j]=0;
                for (int k = 0; k < c1; k++)
                {
                    pro[i][j]+=a[i][k]*b[k][j];
                }
        }
        
    }
    
    printf("The product of the two matrices is as follows: \n");

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", pro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
    
}
