#include <stdio.h>
int main(){
    int n;
    printf("Enter the n: ");
    scanf("%d",&n);
    int pid[n],bt[n],tat[n],wt[n];
    float totalTAT=0,totalWT=0;
    for(int i=0;i<n;i++){
        pid[i] = i + 1;
        printf("Enter Burst Time for Process %d: ", pid[i]);
        scanf("%d",&bt[i]);
    }
    wt[0] = 0;
    for (int  i = 1; i < n; i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
    }
    for (int  i = 0; i < n; i++)
    {
        tat[i] = wt[i]+bt[i];
        totalTAT+=tat[i];
        totalWT+=wt[i];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
    return 0;
}