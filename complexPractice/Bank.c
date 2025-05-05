#include <stdio.h>


int main(){
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);
    int work[m],need[n][m], alloc[n][m],max[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    
    for (int i = 0; i < m; i++)
    {
            scanf("%d",&work[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int Finish[n];
    for (int i = 0; i < n; i++)
        Finish[i] =0;
    int ss[n],count=0;
   
    while (count<n)
    {
        int found =0;
        for (int i = 0; i < n; i++)
        {
            if(!Finish[i]){
                int canExecute=1;
                for (int j = 0; j < m; j++)
                {
                    if(need[i][j]>work[j]){
                        canExecute=0;
                        break;
                    }
                }
                if(canExecute){
                    for (int k = 0; k < m; k++)
                    {
                        work[k] += alloc[i][k];
                    }
                    ss[count++] = i;
                    Finish[i] =1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is in an unsafe state. No safe sequence.\n");
            return 1;
        }        
    }
    printf("\nSystem is in a SAFE STATE.\nSafe sequence is: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", ss[i]);
    printf("\n");
    return 0;
}