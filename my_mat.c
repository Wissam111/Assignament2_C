#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

#define nV 10
#define INF 99999
void printMatrix(int matrix[][nV]);

int floydWarshall(int graph[][nV], int a, int b)
{
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            matrix[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {

                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    printMatrix(matrix);

    int ans = matrix[a][b];

    if (ans == 0)
    {
        return -1;
    }

    return ans;
}

void printMatrix(int matrix[][nV])
{
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

const char *pathExists(int graph[][nV], int a, int b)
{
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            matrix[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {

                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    if (matrix[a][b] == INF || matrix[a][b] == 0)
    {
        return "False";
    }

    return "True";
}

void interNumbersMatrix(int matrix[][nV])
{

    int i, j;

    printf("\nEnter matrix elements :\n");
    for (i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            printf("Enter element [%d,%d] : ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            if (i != j && matrix[i][j] == 0)
            {
                matrix[i][j] = INF;
            }
        }
    }

    printMatrix(matrix);
}