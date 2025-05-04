#include <stdio.h>
int main()
{
    int i, time = 0, remain, flag = 0;
    int time_quantum;
    int wt = 0, tat = 0;
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int at[n], rt[n], bt[n];
    remain = n;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Arrival time and Burst Time of the Process %d:  ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    int cnt = 0;
    while (remain != 0)
    {
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (rt[i] > 0 && at[i] <= time)
            {
                flag = 1;
                if (rt[i] > time_quantum)
                {
                    time += time_quantum;
                    rt[i] -= time_quantum;
                }
                else
                {
                    time += rt[i];
                    int turnaround_time = time - at[i];
                    int waiting_time = turnaround_time - bt[i];
                    wt += waiting_time;
                    tat += turnaround_time;
                    printf("P%d\t%d\t\t%d\n", i + 1, turnaround_time, waiting_time);
                    rt[i] = 0;
                    remain -= 1;
                }
            }
        }
        if (flag == 0)
            time++;
    }
    printf("\nAverage Waiting Time = %.2f", (float)wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)tat / n);

    return 0;
}