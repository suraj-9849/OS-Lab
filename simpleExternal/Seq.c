#include <stdio.h>

int main()
{
    int memory[50] = {0};
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int start, length;
        printf("Enter the Start block and Length:\n");
        scanf("%d%d", &start, &length);
        int free = 1;
        for (int i = start; i < start + length; i++)
        {
            if (memory[i] == 1)
            {
                free = 0;
                break;
            }
        }
        if (free)
        {
            for (int j = start; j < start + length; j++)
            {
                memory[j] = 1;
            }
            printf("File %d allocated from block %d to %d.\n", i + 1, start, start + length - 1);
        }
        else
        {
            printf("It is Not free!");
        }
    }
    return 0;
}