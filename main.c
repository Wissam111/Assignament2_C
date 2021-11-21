#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

int main()
{

    int i, j;
    char ans;

    while (true)
    {

        scanf("%c", &ans);
        printf("\n");
        if (ans == 'A')
        {

            interNumbersMatrix();
        }

        if (ans == 'B')
        {

            scanf("%d", &i);

            scanf("%d", &j);
            if (pathExists(i, j))
            {
                printf("True");
            }
            else
            {
                printf("False");
            }
        }

        if (ans == 'C')
        {

            scanf("%d", &i);

            scanf("%d", &j);
            printf("%d \n", floydWarshall(i, j));
        }

        if (ans == 'D')
        {

            break;
        }
    }
    return 0;
}