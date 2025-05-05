#include <stdio.h>
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int tat[n],totalTat=0,totalWt = 0,wt[n],bt[n],p[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Enter Burst Time for Process %d: ", p[i]);
        scanf("%d",&bt[i]);
    }
    wt[0] = 0;
    tat[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i-1]+bt[i-1];
    }
    for (int i = 0; i < n; i++)
    {
       tat[i] = wt[i]+bt[i];
       totalTat+=tat[i];
       totalWt+=wt[i];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", totalWt/ n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTat / n);
    return 0;
    
}