#include <stdio.h>

int predict(int pages[], int frames[], int n, int index, int f)
{
    int res = -1, farthest = index;
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
                    res = i;
                }
                break;
            }
        }
        if (j == n)
        {
            return i;
        }
    }
    return (res == -1) ? 0 : res;
}

int main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the Page references: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    int f;
    printf("Enter the frames: ");
    scanf("%d", &f);
    int frames[f], time[f];
    int count = 0, pageFaults = 0;
    int t = 0;
    int pos = 0;
    for (int i = 0; i < f; i++)
    {
        frames[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int hit = 0;
        for (int j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                hit = 1;
                break;
            }
        }
        if (hit == 0)
        {
            if (count < f)
            {
                frames[count++] = pages[i];
            }
            else
            {
                int pos = predict(pages, frames, n, i + 1, f);
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

    printf("Total no of Page Faults: %d\n", pageFaults);

    return 0;
}