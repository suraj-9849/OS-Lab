#include <stdio.h>

int main(){
    int n,idxBlock;
    int memory[100] = {0}; // Free =0  and 1=Occupied

    printf("Enter the indexBlock: ");
    scanf("%d",&idxBlock);
    if(memory[idxBlock]!=0){
        printf("File is already Allocated!\n");
        return 0;
    }
    memory[idxBlock]=1;
    printf("Enter the blocks required for the file to be stored: ");
    scanf("%d",&n);
    int block[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&block[i]);
        if(memory[block[i]]==0){
            memory[block[i]]=1;
        }else{
            printf("Block %d already allocated! File allocation failed.\n", block[i]);
            return 0;
        }

    }
    printf("\nFile allocated using index block %d.\n", idxBlock);
    printf("Index Block contains:\n");
    for (int i = 0; i < n; i++) {
        printf("Block[%d] -> %d\n", i, block[i]);
    }
return 0;
}