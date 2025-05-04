#include <stdio.h>
#define MAX 10

struct Segment{
    int base;
    int limit;
    int values[MAX];
};

struct Segment segTable[MAX];
int n;

void getSegInfo(){
    printf("Enter the n: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the base: ");
        scanf("%d",&segTable[i].base);
        printf("Enter the limit: ");
        scanf("%d",&segTable[i].limit);
        printf("Enter the values: ");
        for (int j = 0; j < segTable[i].limit; j++)
        {
            printf("Value at offset %d: ", j);
            scanf("%d",&segTable[i].values[j]);
        }
    }
}



void translateLogicalAdd(){
    int segNum, offset;
    printf("Enter the Seg Number: ");
    scanf("%d",&segNum);
    printf("Enter the offset: ");
    scanf("%d",&offset);
    if (segNum>=n)
    {
        printf("Seg num is invalid\n");
    }
    if(offset>=segTable[segNum].limit){
        printf("Offset is invalid");
    }
    int phyAdd = segTable[segNum].base+offset;
    int val  = segTable[segNum].values[offset];
    printf("\n✅ Logical Address (Segment %d, Offset %d)", segNum, offset);
    printf("\n Physical Address: %d", phyAdd);
    printf("\n Value at Address: %d\n", val);
}


int main(){
    char choice;
    getSegInfo();
    do
    {
        translateLogicalAdd();
        printf("\nDo you want to translate another address (Y/N)? ");
        scanf(" %c", &choice); 
    } while ((choice=='Y')|| (choice == 'y'));
    return 0;
}