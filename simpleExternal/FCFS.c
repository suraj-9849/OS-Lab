#include <stdio.h>

int main()
{
    int n;
    printf("Enter the n:");
    scanf("%d", &n);
    int pid[n], bt[n], tat[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter the Burst Time for the Process P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    tat[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }
    int totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++)
    {
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("Process\tBurst time\tWaitingTime\tTurnAroundTime\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("Avg Waiting Time: %.2f\n", (float)totalWT / n);
    printf("Avg Turnaround Time: %.2f\n", (float)totalTAT / n);

    return 0;
}