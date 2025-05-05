#include <stdio.h>

int main()
{
    int logicalAdd, pageSize,n;
    int pageTable[100];
    printf("Enter the Pages: ");
    scanf("%d", &n);
    printf("Enter the pageSize: ");
    scanf("%d", &pageSize);
    printf("Enter frame number for each page:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }
    printf("Enter the LogicalAdd:");
    scanf("%d", &logicalAdd);
    int pageadd = logicalAdd / pageSize;
    int offset = logicalAdd % pageSize;
    int phyAdd = pageTable[pageadd] * pageSize + offset;
    printf("Physical address: %d", phyAdd);
    return 0;
}