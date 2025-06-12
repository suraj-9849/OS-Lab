#include <stdio.h>

int predict(int pages[], int frames[], int n, int index, int f)
{
    int farthest = index;
    int pos = -1;
    for (int i = 0; i < f; i++)
    {
        int j;
        for (j = index + 1; j < n; j++)
        {
            if (frames[i] == pages[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n)
        {
            return i;
        }
    }
    return (pos == -1) ? 0 : pos;
}

int main()
{
    int n;
    printf("Enter the no.of Pages:");
    scanf("%d", &n);
    int pages[n], f;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("ENter the NO.of Frames:");
    scanf("%d", &f);
    int time[f], frames[f];
    int count = 0;
    int pos = 0;
    int t = 0;
    int pageFaults = 0;
    for (int i = 0; i < f; i++)
    {
        frames[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            if (count < f)
            {
                frames[count++] = pages[i];
            }
            else
            {
                pos = predict(pages, frames, n, i + 1, f);
                frames[pos] = pages[i];
            }
            pageFaults++;
        }
        printf("Frames: ");
        for (int k = 0; k < f; k++)
        {
            if (frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("%d", pageFaults);
    return 0;
}