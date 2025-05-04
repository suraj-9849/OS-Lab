#include <stdio.h>

int findLRU(int time[],int n){
    int i, min=time[0],pos = 0;
    for(int i=1;i<n;i++){
        if(time[i]<min){
            min = time[i];
            pos = i;
        }
    }
    return pos;
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
        time[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                flag = 1;
                time[j] = t++;
                break;
            }
        }

        if (flag == 0)
        {
            if (count < f)
            {
                frames[count] = pages[i];
                time[count] = t++;
                count++;
            }
            else
            {
                pos = findLRU(time,f);
                frames[pos] = pages[i];
                time[pos]=t++;
            }
            pageFaults++;
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
    printf("Total no of Page Faults: %d\n", pageFaults);

    return 0;
}