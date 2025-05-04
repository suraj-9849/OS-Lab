#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);
    int alloc[n][m], max[n][m], need[n][m], work[m];
    bool Finish[n];
    printf("\nEnter alloc Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    printf("\nEnter (Work-332) work Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &work[i]);
    // Calculate need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    for (int i = 0; i < n; i++)
        Finish[i] = false;

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
                    Finish[i] = true;
                    found = true;
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