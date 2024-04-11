
#include <stdio.h>
#include <math.h>

int main()
{
    int c1, r1, r2, c2; char c;

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

    for (int k = 0; ; )   //first matrix
    {
        printf("\nEnter the values for the first matrix in:\n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                printf("%d row and %d column: ", i+1, j+1);
                scanf("%d", &a[i][j]);
            }
        }
        printf("The first matrix is as follows:\n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }

        printf("Is it accurate?[y/n]: ");
        scanf(" %c", &c);
        
        if (c=='y') {break;}
    }

    for (int k = 0; ; )   //second matrix
    {
        printf("\nEnter the values for the second matrix in:\n");
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("%d row and %d column: ", i+1, j+1);
                scanf("%d", &b[i][j]);
            }
        }
        printf("The second matrix is as follows:\n");
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("%d ", b[i][j]);
            }
            printf("\n");
        }

        printf("Is it accurate?[y/n]\n");
        scanf(" %c", &c);
        
        if (c=='y') {break;}
    }

    for (int i = 0; i < r1; i++)  //multiplication
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
