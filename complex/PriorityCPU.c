#include <stdio.h>

int main()
{
    int n;
    int bt[20], p[20], pr[20], wt[20], tat[20];
    int total_wt = 0, total_tat = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority for Process %d: ", i + 1);
        scanf("%d%d", &bt[i], &pr[i]);
        p[i] = i + 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pr[i] > pr[j])
            {
                // Swap priority:
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                // Swap bt:
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                // Swap Process:
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("Avg Tat: %.2f\n", (float)total_tat / n);
    printf("Avg Wt: %.2f\n", (float)total_wt / n);
    return 0;
}