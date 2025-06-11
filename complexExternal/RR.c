#include <stdio.h>

int main()
{
    int remain, n;
    printf("Enter the n:");
    scanf("%d", &n);
    int rt[n], at[n], bt[n];
    remain = n;
    int timeQuantum, time = 0, flag = 0;
    int wt = 0, tat = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Arrival time and Burst Time of the Process %d:  ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter the TimeQuantum:");
    scanf("%d", &timeQuantum);
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    while (remain != 0)
    {
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (rt[i] > 0 && at[i] <= time)
            {
                flag = 1;
                if (rt[i] > timeQuantum)
                {
                    time += timeQuantum;
                    rt[i] -= timeQuantum;
                }
                else
                {
                    time += rt[i];
                    int turnArT = time - at[i];
                    int waitT = turnArT - bt[i];
                    wt += waitT;
                    tat += turnArT;
                    printf("P%d\t%d\t\t%d\n", i + 1, turnArT, waitT);
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