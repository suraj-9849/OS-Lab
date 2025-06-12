#include <stdio.h>

int main()
{
    int n, start, blocks, block, prev;
    int allocated[50] = {0}, link[50];

    printf("Enter number of files: ");
    scanf("%d", &n);
    while (n--)
    {
        printf("Enter the Starting Block:");
        scanf("%d", &start);
        if (allocated[start])
            continue;
        allocated[start] = 1;
        prev = start;
        printf("Enter the No of blocks:");
        scanf("%d", &blocks);
        for (int i = 0; i < blocks; i++)
        {
            scanf("%d", &block);
            if (allocated[block])
            {
                printf("Block %d allocated. Skipping.\n", block);
                break;
            }
            else
            {
                allocated[block] = 1;
                link[prev] = block;
                prev = block;
            }
        }
        link[prev] = -1;
        for (int current = start; current != -1; current = link[current])
            printf("%d -> ", current);
        printf("null\n");
    }
    return 0;
}