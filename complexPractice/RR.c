#include <stdio.h>
#define M 100
int main()
{
    int rt[M], bt[M], at[M], n;
    int wt = 0, tat = 0;
    printf("Enter the Processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
       printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    int timeQ = 0;
    printf("Enter tq:");
    scanf("%d", &timeQ);
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    int cnt = 0;
    int time = 0;
    int remain = n;
    while (remain != 0)
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (rt[i] > 0 && at[i] <= time)
            {
                flag = 1;
                if (rt[i] > timeQ)
                {
                    time += timeQ;
                    rt[i] -= timeQ;
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
}