#include <stdio.h>
int absolute(int a)
{
    return a < 0 ? -a : a;
}
int main()
{
    int n, head, totalSeek = 0;
    printf("Enter the no of Disks: ");
    scanf("%d", &n);
    int requests[n], visited[n];
    printf("Enter disk request queue:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
        visited[i] = 0;
    }
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("\nSeek Sequence: \n");
    for (int i = 0; i < n; i++)
    {
        int minDis = 9999, index = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j])
            {
                int dis = absolute(requests[j] - head);
                if (dis < minDis)
                {
                    minDis = dis;
                    index = j;
                }
            }
        }
        visited[index] = 1;
        totalSeek += absolute(requests[index] - head);
        head = requests[index];
    
        printf("%d", head);
        if (i != n - 1) printf("->");
    }
     printf("\nTotal Seek Time:%d\n", totalSeek);
    return 0;
}