#include <stdio.h>

int main()
{
    int memory[50] = {0}; // 0 = free, 1 = used
    int start, length, block;

    printf("Enter the starting block of the file: ");
    scanf("%d", &start);

    if (memory[start] == 1)
    {
        printf("Starting block already allocated!\n");
        return 0;
    }
 
    printf("Enter the number of blocks needed: ");
    scanf("%d", &length);

    int file[50];
    file[0] = start;
    memory[start] = 1;

    printf("Enter the block numbers one by one:\n");
    for (int i = 1; i < length; i++)
    {
        scanf("%d", &block);
        if (memory[block] == 0)
        {
            file[i] = block;
            memory[block] = 1;
        }
        else
        {
            printf("Block %d already allocated! File allocation failed.\n", block);
            return 0;
        }
    }

    printf("\nFile stored using linked allocation:\n");
    for (int i = 0; i < length - 1; i++)
    {
        printf("[%d] -> ", file[i]);
    }
    printf("[%d] -> NULL\n", file[length - 1]);

    return 0;
}
