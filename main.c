
#include <stdio.h>
#include <stdbool.h>
// #define N 4
// int N;

#define nV 10
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


int main()
{
int matrix[nV][nV];
    int i,j;
     
   
    printf("\nEnter matrix elements :\n");
    for(i=0;i< nV;i++)
    {
        for(j=0;j< nV;j++)
        {
            printf("Enter element [%d,%d] : ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
 
    printf("\nMatrix is :\n");
    for(i=0;i< nV;i++)
    {
        for(j=0;j< nV;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");   
    }
   
    int graph[nV][nV] = {
        {0, 3, 5},
        {3, 0, 1},
        {5, 1, 0},

    };

    printf("The shortest Path is : %d \n", floydWarshall(graph, 0, 2));
    printf("if path exisits : %d \n" , pathExists(graph , 0,2));
    // floydWarshall(graph);
    return 0;
}
