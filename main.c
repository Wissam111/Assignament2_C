#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"



int main()
{

    int i, j;
    char ans;
    
//      int matrix[nV][nV] = {{0 ,3, 1, 0,0 ,2, 0, 0, 0, 0}, {3, 0, 1, 0, 0 ,0 ,0 ,0 ,0 ,0} ,{1, 1, 0, 0 ,0 ,0 ,0 ,0 ,0, 0},{ 0, 0, 0 ,0, 0 ,0 ,0, 5, 0 ,0 }, {0 ,0, 0, 0, 0 ,0 ,0 ,4 ,1 ,1}, {2 ,0, 0, 0 ,0 ,0, 2 ,0, 0 ,0} , {0 ,0 ,0 ,0, 0, 2 ,0 ,0 ,0, 0 } ,{0 ,0, 0, 5 ,4, 0,0 ,0 ,0, 2} ,{ 0 ,0 ,0 ,0 ,1 ,0 ,0, 0,0 ,0},{ 0 ,0 ,0 ,0 ,1,0 ,0, 2 ,0 ,0}};

// printf("%d" , floydWarshall(matrix , 0 ,3));
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