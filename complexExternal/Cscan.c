#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int diskSize = 199;
    printf("Enter the n: ");
    scanf("%d", &n);
    int requests[n + 2];
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
    if (direction == 1)
    {
        requests[n++] = 199;
    }
    else
    {
        requests[n++] = 0;
    }
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
            printf("%d->",requests[i]);
            if(i!=pos){
                totalSeek+=abs(requests[i]- requests[i-1]);
            }
        }
        totalSeek+=abs(199-0);
        printf("0->");
        for(int i=0;i<pos;i++){
            printf("%d->",requests[i]);
            if(i!=0){
                totalSeek+=abs(requests[i]-requests[i-1]);
            }else{
                totalSeek+=abs(requests[i]-0);
            }
        } 
    }
    else
    {
        // Left:
        for (int i = pos; i >=0; i--)
        {
            printf("%d->",requests[i]);
            if(i!=pos){
                totalSeek+=abs(requests[i]- requests[i+1]);
            }
        }
        totalSeek+=abs(199-0);
        printf("199->");
        for(int i=n-1;i<pos;i++){
            printf("%d->",requests[i]);
            if(i!=n-1){
                totalSeek+=abs(requests[i]-requests[i+1]);
            }else{
                totalSeek+=abs(requests[i]-0);
            }
        }
    }
    printf("Total Requests are: %d\n",totalSeek);
    return 0;
}