#include <stdio.h>
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int tat[n], bt[n], pr[n], p[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the bt and priority for P%d: ", i + 1);
        scanf("%d%d", &bt[i], &pr[i]);
        p[i] = i + 1;
    }
    int totalwt = 0, totaltat = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // swap pr:
            if (pr[i] > pr[j])
            {
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

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
        totalwt += wt[i];
        totaltat += tat[i];
    }
    printf("Avg Tat: %.2f\n", (float)totaltat / n);
    printf("Avg Wt: %.2f\n", (float)totalwt / n);

    return 0;
}