
#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

int main()
{
    int matrix[nV][nV];
    // int i,j;
    //  interNumbersMatrix(matrix);
    int i, j;
    char ans;

    while (true)
    {

        printf("Enter Function: ");
        scanf("%c", &ans);
        printf("\n");
        if (ans == 'A')
        {
            int matrix[nV][nV];
            interNumbersMatrix(matrix);
        }

        if (ans == 'B')
        {
            printf("Enter i: ");
            scanf("%d", &i);
            printf("Enter j: ");
            scanf("%d", &j);

            printf("Path exisits: %s \n ", pathExists(matrix, i, j));
        }

        if (ans == 'C')
        {
            printf("Enter i: ");
            scanf("%d", &i);
            printf("Enter j: ");
            scanf("%d", &j);
            printf("Shortest Path: %d \n", floydWarshall(matrix, i, j));
        }

        if (ans == 'D')
        { 
            printf("------------------Done---------------------- \n");
            break;
        }
    }
    return 0;
}
