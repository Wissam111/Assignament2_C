#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

int main()
{

    int i, j;
    char ans;
    bool run = true;
    while (run)
    {

        scanf("%c", &ans);
        switch (ans)
        {
        case 'A':
            enterNumbersMatrix();
            break;
        case 'B':
            scanf("%d", &i);

            scanf("%d", &j);
            if (pathExists(i, j))
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }
            break;

        case 'C':
            scanf("%d", &i);
            scanf("%d", &j);
            printf("%d\n", floydWarshall(i, j));
            break;

        case 'D':
            run = false;
            break;
        }
        return 0;
    }
}