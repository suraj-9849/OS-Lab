#include <stdio.h>

int main(){
    int n,m;
    printf("Enter process: ");
    scanf("%d",&n);
    printf("Enter resources: ");
    scanf("%d",&m);
    int alloc[n][m], need[n][m], work[m],max[n][m];
    int Finish[n];
    printf("\nEnter alloc Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    printf("\nEnter (Work-332) work Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &work[i]);
    // Calculate need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];


    for (int i = 0; i < n; i++)
    {
        Finish[i] =0;
    }
    int ss[n],count = 0;
    while(count< n){
        int found=0;
        for (int i = 0; i < n; i++)
        {
            if(!Finish[i]){
                int canExecute = 0;
                for (int j = 0; j < m; j++)
                {
                    if(need[i][j]>work[j]){
                        canExecute=1;
                        break;
                    }
                }
                if(canExecute==0){
                    for (int k = 0; k < m; k++)
                    {
                        work[k]+=alloc[i][k];
                    }
                    ss[count++] = i;
                    found = 1;
                    Finish[i] = 1;
                }
            }
        }
        if(!found){
            printf("Not Safe State");
            
        }
    }
    return 0;
}