#include <stdio.h>
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int f, pages[n];
    printf("Enter the Page References:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("Enter the size of Frames:");
    scanf("%d", &f);
    int frames[f];
    int pos = 0, ans = 0;
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
            frames[pos] = pages[i];
            pos = (pos + 1) % f;
            ans += 1;
        }
        for (int k = 0; k < f; k++)
        {
            if (frames[i] != -1)
            {
                printf("%d ", frames[k]);
            }
            else
            {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("Total no of Page Faults: %d\n", ans);

    return 0;
}