#include <stdio.h>

int main(){
    int nb, np;
    printf("Enter the blocks Size:");
    scanf("%d",&nb);
    printf("Enter the process Size:");
    scanf("%d",&np);
    int used[100], block[100],alloc[100],process[100];
    for (int i = 0; i < nb; i++)
    {
        scanf("%d",&block[i]);
        used[i]=0;
    }
    for (int i = 0; i < np; i++)
    {
        scanf("%d",&process[i]);
        alloc[i]=-1;
    }
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            if(used[j]==0 && block[j]>=process[i]){
                alloc[i] = j;
                used[j] = 1;
                break;
            }
        }
    }
    printf("\nProcess\tSize\tBlock\n");
    for (int  i = 0; i < np; i++)
    {
        if(alloc[i]!=-1){
            printf("%d\t%d\t%d\n", i + 1, process[i], alloc[i] + 1);
        }
        else{
            printf("%d\t%d\tNot Allocated\n", i + 1, process[i]);
        }
    }
    return 0;
}