#include <stdio.h>

int main(){
    int n,startBlock,length;
    int memory[100] = {0};
    printf("Enter the n: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &startBlock,&length);
        int isFree = 1;
        for (int j = startBlock; j < startBlock+length; j++)
        {
            if(memory[j]==1){
                isFree=0;
                break;
            }
        }
        if(isFree){
            for (int j = startBlock; j < startBlock+length; j++)
            {
                memory[j]=1;
            }
            printf("File %d allocated from block %d to %d.\n", i + 1, startBlock, startBlock + length - 1);  
        }else{
            printf("File %d cannot be allocated. Blocks already in use.\n", i + 1);
        }
    }
    return 0;
}