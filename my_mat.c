#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

#define nV 10
#define INF 99999
int graph[nV][nV];

void interNumbersMatrix()
{
    for (int i = 0; i < nV; i++){

        for (int j = 0; j < nV; j++)
        {
            scanf(" %d", &graph[i][j]);
        }
    }
}


int floydWarshall(int a, int b)
{
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            matrix[i][j] = graph[i][j];
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

  

    int ans = matrix[a][b];

    if (ans == 0 || ans == INF)
    {
        return -1;
    }

    return ans;
}

bool pathExists(int a, int b)
{
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            matrix[i][j] = graph[i][j];
        }
    }
    for (i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            if (i != j && matrix[i][j] == 0)
            {
                matrix[i][j] = INF;
            }
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
        return false;
    }

    return true;
}
