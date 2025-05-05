#include <stdio.h>

int main()
{
    int memory[100] = {0}; // 0 = Free, 1 = Occupied
    int startIndex, block;

    printf("Enter the Index: ");
    scanf("%d", &startIndex);

    if (memory[startIndex] == 1)
    {
        printf("Already allocated\n");
        return 0;
    }

    int n;
    printf("Enter the blockSize: ");
    scanf("%d", &n);

    int file[50];
    file[0] = startIndex;
    memory[startIndex] = 1;

    for (int i = 1; i < n; i++)
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

    printf("\nFile allocated using start block %d.\n", startIndex);
    printf("Index Block contains:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Block[%d] -> %d\n", i, file[i]);
    }

    return 0;
}
