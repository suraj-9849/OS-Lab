#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, totalseek = 0;
    printf("Enter the No.of Disks:");
    scanf("%d", &n);
    int requests[n], visited[n];
    int head;
    printf("Enter the Head:");
    scanf("%d", &head);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int minDis = 9999999, idx = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j])
            {
                int dis = abs(requests[j] - head);
                if (dis < minDis)
                {
                    minDis = dis;
                    idx = j;
                }
            }
        }
        visited[idx] = 1;
        totalseek += abs(requests[idx] - head);
        head = requests[idx];
        printf("%d", head);
        if (i != n - 1)
            printf("->");
    }
    printf("\nTotal Seek Time:%d\n", totalseek);
    return 0;
}
