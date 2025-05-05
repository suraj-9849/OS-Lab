#include <stdio.h>

int main(){
    int produce,consume, bufferSize=10, buffer[10], choice=0,in=0,out=0;
    while (choice!=3)
    {
        printf("\n1.Produce\n2.Consume\n3.Exit\n");
        printf("Enter the Choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        if((in+1)%bufferSize==out){
            printf("Full!\n");
        }else{
            printf("Enter the Producer Value:");
            scanf("%d",&produce);
            buffer[in]=produce;
            in = (in+1)%bufferSize;
        }
            break;
        case 2:
        if(in==out){
            printf("Empty\n");
        }else{
            printf("%d\n", buffer[out]);
            out = (out + 1) % bufferSize;
        }
        break;
        case 3:
        printf("Exiting....\n");
        break;
        default:
            break;
        }
    }
    
}