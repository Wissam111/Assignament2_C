#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

int main()
{

    int i, j;
    char ans;
    
    while (true)
    {
        int matrix[nV][nV];
        printf("Enter Function: ");
        scanf("%c", &ans);
        printf("\n");
        if (ans == 'A')
        {

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