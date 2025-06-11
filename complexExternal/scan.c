#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int diskSize = 199;
    printf("Enter the n: ");
    scanf("%d", &n);
    int requests[n + 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
    }
    int head, direction;
    printf("\n\n");
    printf("Enter the Head Value: ");
    scanf("%d", &head);
    printf("Enter the Direction: 1-right, 0-left-----> ");
    scanf("%d", &direction);
    requests[n++] = head;
    // Sort:
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (requests[i] > requests[j])
            {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (requests[i] == head)
        {
            pos = i;
            break;
        }
    }
    int totalSeek = 0;
    if (direction == 1)
    {
        // Right:
        for (int i = pos; i < n; i++)
        {
            printf("%d->", requests[i]);
            if (i != pos)
            {
                totalSeek += abs(requests[i] - requests[i - 1]);
            }
        }

        if (requests[n - 1] != 199)
        {
            totalSeek += abs(199 - requests[n - 1]);
        }
        printf("199->");
        for (int i = pos - 1; i >= 0; i--)
        {
            printf("%d->", requests[i]);
            if (i != pos - 1)
            {
                totalSeek += abs(requests[i + 1] - requests[i]);
            }
            else
            {
                totalSeek += abs(199 - requests[i]);
            }
        }
    }
    else
    {
        // Left:
        for (int i = pos; i >= 0; i--)
        {
            printf("%d->", requests[i]);
            if (i != pos)
            {
                totalSeek += abs(requests[i] - requests[i + 1]);
            }
        }

        if (requests[0] != 0)
        {
            totalSeek += abs(requests[0] - 0);
        }
        printf("0->");
        for (int i = pos + 1; i < n; i++)
        {
            printf("%d -> ", requests[i]);
            if (i != pos + 1)
            {
                totalSeek += abs(requests[i] - requests[i - 1]);
            }
            else
            {
                totalSeek += abs(0 - requests[i]);
            }
        }
    }
    printf("Total Requests are: %d\n", totalSeek);
    return 0;
}