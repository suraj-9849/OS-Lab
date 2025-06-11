#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of Pages: ");
    scanf("%d", &n);
    int pageTable[n];
    int pageSize;
    printf("Enter the page size: ");
    scanf("%d", &pageSize);
    printf("Enter frame number for each page:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pageTable[i]);
    }
    int logicaladdress;
    printf("Enter the Logical Address: ");
    scanf("%d", &logicaladdress);
    int pageNum = logicaladdress / pageSize;
    int offset = logicaladdress % pageSize;
    if (pageNum >= n)
    {
        printf("Invalid logical address! Page number out of range.\n");
        return 0;
    }
    int phyAddress = pageTable[pageNum] * pageSize + offset;
    printf("Physical Address: %d\n", phyAddress);
    return 0;
}