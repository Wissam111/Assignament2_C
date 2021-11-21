#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

int main()
{

    int i, j;
    char ans;
    // int matrix[nV][nV];
    //  int matrix[nV][nV] = {{0 ,9 ,48, 20, 10, 39, 22, 49, 44 ,33}, {9 ,0 ,38, 45, 26, 22, 2 ,4 ,26, 42} ,{48, 38 ,0 ,47, 32, 5 ,5 ,1 ,5 ,12},{ 20 ,45, 47 ,0 ,19 ,4 ,36 ,46, 36, 4 }, {10, 26 ,32, 19 ,0, 46 ,16, 3 ,37 ,27 }, {39 ,22 ,5 ,4 ,46 ,0 ,46, 29,16 ,28 } , {22, 2, 5 ,36, 16, 46, 0 ,4, 46, 7 } ,{49 ,4 ,1 ,46, 3 ,29 ,4 ,0 ,10 ,41} ,{ 44, 26, 5, 36, 37 ,16, 46 ,10, 0 ,19 },{ 33, 42, 12, 4 ,27 ,28, 7, 41 ,19, 0 } };
    // printf("%d" , floydWarshall(matrix , 0 ,3));

    while (true)
    {

        //  int matrix[nV][nV];
        printf("Enter Function: ");

        scanf("%c", &ans);
        printf("\n");
        if (ans == 'A')
        {

            interNumbersMatrix();
        }

        if (ans == 'B')
        {
            // printf("Enter i: ");
            scanf("%d", &i);
            // printf("Enter j: ");
            scanf("%d", &j);
            if(pathExists(i,j)){
                printf("True");
            }else{
                printf("False");
            }
            
        }

        if (ans == 'C')
        {
            // printf("Enter i: ");
            scanf("%d", &i);
            // printf("Enter j: ");
            scanf("%d", &j);
            printf("Shortest Path: %d \n", floydWarshall(i, j));
        }

        if (ans == 'D')
        {
            printf("------------------Done---------------------- \n");
            break;
        }
    }
    return 0;
}