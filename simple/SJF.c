#include <stdio.h>

int main()
{
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], wt[n], tat[n];
    float totalWT = 0, totalTAT = 0;

    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter Burst Time for Process %d: ", pid[i]);
        scanf("%d", &bt[i]);
    }
    // Sort:
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst times
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
    
                // Swap process IDs
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }
    wt[0] = 0;
    for (int i =1; i < n; i++)
    {
        wt[i] =wt[i-1]+bt[i-1];
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i]+bt[i];
        totalTAT+=tat[i];
        totalWT+=wt[i];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
    return 0;
}