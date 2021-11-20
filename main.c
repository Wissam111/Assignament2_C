
#include <stdio.h>
#include <stdbool.h>
// #define N 4
// int N;

#define nV 3
#define INF 99999
void printMatrix(int matrix[][nV]);

// Implementing floyd warshall algorithm
int floydWarshall(int graph[][nV], int a, int b)
{
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)

            if (i != j && graph[i][j] == 0)
            {
                matrix[i][j] = INF;
            }
            else
            {
                matrix[i][j] = graph[i][j];
            }

    // Adding vertices individually
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

bool pathExists(int graph[][nV], int a, int b)
{
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)

            if (i != j && graph[i][j] == 0)
            {
                matrix[i][j] = INF;
            }
            else
            {
                matrix[i][j] = graph[i][j];
            }

    // Adding vertices individually
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

    if (matrix[i][j] == INF)
    {
        return false;
    }

    return true;
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

    printf("\nMatrix is :\n");
    for (i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

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
            interNumbersMatrix(matrix);
        }

        if (ans == 'B')
        {
            printf("Enter i: ");
            scanf("%d", &i);
            printf("Enter j: ");
            scanf("%d", &j);

            printf("Path exisits: %d \n ", pathExists(matrix, i, j));
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
            printf("Done \n");
            break;
        }
    }
    return 0;
}
