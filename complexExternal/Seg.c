#include <stdio.h>
#define MAX 10
struct Segment
{
    int base;
    int limit;
    int values[MAX];
};

struct Segment segTable[MAX];
int n;
void getSegInfo()
{
    printf("Enter n:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the base:");
        scanf("%d", &segTable[i].base);
        printf("Enter the limit:");
        scanf("%d", &segTable[i].limit);
        printf("Enter the values:");
        for (int j = 0; j < segTable[i].limit; j++)
        {
            scanf("%d", &segTable[i].values[j]);
        }
    }
}

void translateLogicalAdd()
{
    int segNum, offset;
    printf("Enter the Seg Number:");
    scanf("%d", &segNum);
    printf("Enter the Offset:");
    scanf("%d", &offset);
    segNum -= 1;
    if (segNum < 0 || segNum >= n || offset < 0 || offset >= segTable[segNum].limit)
    {
        printf("Invalid segment number or offset.\n");
        return;
    }
    int phyAdd = segTable[segNum].base + offset;
    int val = segTable[segNum].values[offset];
    printf("phy add : %d\n\n", phyAdd);
    printf("values : %d\n\n", val);
}

int main()
{
    char ch;
    getSegInfo();
    do
    {
        translateLogicalAdd();
        printf("Do u want to continue(Y|N):\n");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
}