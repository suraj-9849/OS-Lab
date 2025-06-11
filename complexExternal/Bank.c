#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, m;
    printf("Enter the no. of Processes:");
    scanf("%d", &n);
    printf("Enter the no. of Resources:");
    scanf("%d", &m);
    int alloc[n][m], max[n][m], work[m], need[n][m];
    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the Max Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the Available Resources: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &work[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    bool Finish[n];
    for (int i = 0; i < n; i++)
    {
        Finish[i] = false;
    }
    int ss[n], count = 0;
    while (count < n)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (!Finish[i])
            {
                bool canExecute = true;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canExecute = false;
                        break;
                    }
                }
                if (canExecute)
                {
                    for (int k = 0; k < m; k++)
                    {
                        work[k] += alloc[i][k];
                    }
                        ss[count++] = i;
                        found = true;
                        Finish[i] = true;
                }
            }
        }
        if (!found)
        {
            printf("\nSystem is NOT in a safe state (Deadlock may occur).\n");
            return 1;
        }
    }
    printf("\nSystem is in a SAFE STATE.\nSafe sequence is: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", ss[i]);
    printf("\n");
    return 0;
}