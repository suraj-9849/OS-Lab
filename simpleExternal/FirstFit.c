#include <stdio.h>


void firstFit(int m, int n, int process[], int blocks[], int alloc[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blocks[j] >= process[i])
            {
                alloc[i] = j;
                blocks[j] -= process[i];
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\tBlock Size\n");
    for (int i = 0; i < n; i++)
    {
        if (alloc[i] != -1)
        {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, process[i], alloc[i] + 1, blocks[alloc[i]]);
        }
        else
        {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, process[i]);
        }
    }
}
int main()
{
    int m;
    int n;
    printf("Enter the size of the Blocks");
    scanf("%d", &m);
    int blocks[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &blocks[i]);
    }
    printf("Enter the processes");
    scanf("%d", &n);
    int process[n];
    int alloc[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &process[i]);
        alloc[i] = -1;
    }
    firstFit(m, n, process, blocks, alloc);
    return 0;
}