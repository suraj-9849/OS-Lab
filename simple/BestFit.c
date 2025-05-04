#include <stdio.h>
#define M 25
int main()
{
    int block[M], process[M], alloc[M], used[M];
    int nb, np;
    printf("Enter the BlockSize: ");
    scanf("%d", &nb);
    printf("Enter the ProcessSize:");
    scanf("%d", &np);
    printf("Enter block sizes:\n");
    for (int i = 0; i < nb; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
        used[i] = 0;
    }

    printf("Enter process sizes:\n");
    for (int i = 0; i < np; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &process[i]);
        alloc[i] = -1;
    }
    for (int i = 0; i < np; i++)
    {
        int bestidx = -1;
        for (int j = 0; j < nb; j++)
        {
            if (block[j] >= process[i])
            {
                if (bestidx == -1 || block[j] < block[bestidx])
                {
                    bestidx = j;
                }
            }
        }
        if (bestidx != -1)
        {
            alloc[i] = bestidx;
            block[bestidx] -= process[i];
        }
    }
    printf("\nProcess\tSize\tBlock\n");
    for (int i = 0; i < np; i++)
    {
        if (alloc[i] != -1)
            printf("%d\t%d\t%d\n", i + 1, process[i], alloc[i] + 1);
        else
            printf("%d\t%d\tNot Allocated\n", i + 1, process[i]);
    }

    return 0;
}