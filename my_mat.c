#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"
#include <limits.h>

#define nV 10
int graph[nV][nV];

void enterNumbersMatrix()
{
    for (int i = 0; i < nV; i++)
    {

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
            if (i != j && matrix[i][j] == 0)
            {
                matrix[i][j] = INT_MAX;
            }
            else
            {
                matrix[i][j] = graph[i][j];
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

    if (ans == 0 || ans == INT_MAX)
    {
        return -1;
    }

    return ans;
}

bool pathExists(int a, int b)
{

    int ans = floydWarshall(a, b);

    if (ans == INT_MAX || ans == 0)
    {
        return false;
    }

    return true;
}
