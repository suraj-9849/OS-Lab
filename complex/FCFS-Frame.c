#include <stdio.h>

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
    int frames[f];
    int pos = 0, ans = 0;
    for (int i = 0; i < f; i++)
        frames[i] = -1;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
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
        printf("Frames: ");
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