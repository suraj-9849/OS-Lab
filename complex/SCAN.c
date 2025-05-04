#include <stdio.h>
#include <stdlib.h>
int main(){
    int i,j,head,direction,n;
    printf("Enter the n(no of disks): ");
    scanf("%d",&n);
    int requests[n+1];
    printf("Enter the requests:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&requests[i]);
    }
    printf("Enter the Head:");
    scanf("%d",&head);
    printf("Enter the Direction left-0 right-1:  ");
    scanf("%d",&direction);
    requests[n] = head;
    n++;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(requests[i]>requests[j]){
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if(head==requests[i]){
            pos = i;
            break;
        }
    }
    
    int totalSeek=0;
    if(direction==1){
        //Move right:
        for(int i=pos;i<n;i++){
            printf("%d -> ", requests[i]);
            if(i!=pos){
                totalSeek+= abs(requests[i]-requests[i-1]);
            }
        }
        if (requests[n - 1] != 199) {
            totalSeek += abs(199 - requests[n - 1]);
        }
        // Now move Left:
        for (int i = pos-1; i >=0; i--)
        {
            printf("%d -> ", requests[i]);
            if(i!=pos-1){
                totalSeek+=abs(requests[i+1]-requests[i]);
            }else{
                totalSeek += abs(199 - requests[i]);
            }
        }
    }else{
        // Move left;
        for (int i = pos; i >=0; i--)
        {
            printf("%d -> ", requests[i]);
            if(i!=pos){
                totalSeek+=abs(requests[i+1]-requests[i]);
            }
        }
        if(requests[0]!=0){
            totalSeek+=abs(requests[0]-0);
        }
        // Now move right;
        for (int  i = pos+1; i < n; i++)
        {
            printf("%d -> ", requests[i]);
            if(i!=pos+1){
                totalSeek+=abs(requests[i]-requests[i-1]);
            }else{
                totalSeek+=abs(0-requests[i]);
            }
        }
    }
    printf("totalSeek: %d\n", totalSeek);
    return 0;
}