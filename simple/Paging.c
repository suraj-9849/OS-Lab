#include <stdio.h>
int main()
{
    int pageTable[10];
    int n, logicalAdd, pageSize;
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
    int pageAdd = logicalAdd / pageSize;
    int offset = logicalAdd % pageSize;
    int physicalAdd = pageTable[pageAdd] * pageSize + offset;
    printf("Physical Address: %d\n", physicalAdd);
    return 0;
}