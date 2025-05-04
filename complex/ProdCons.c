#include <stdio.h>

int main()
{
    int bufferSize = 10, buffer[10], produce, consume, choice = 0, in = 0, out = 0;
    while (choice != 3)
    {
        printf("\n1.Produce\n2.Consume\n3.Exit\n");
        printf("Enter the Choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (((in + 1) % bufferSize) == out)
            {
                printf("buffer is Full.\n");
            }
            else
            {
                printf("\nEnter the value: ");
                scanf("%d", &produce);
                buffer[in] = produce;
                in = (in + 1) % bufferSize;
            }
            break;
        case 2:
            if (in == out)
            {
                printf("buffer is Empty.\n");
            }
            else
            {
                consume = buffer[out];
                printf("\nThe consumed value is %d", consume);
                out = (out + 1) % bufferSize;
            }
            break;
        case 3:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid choice! Please enter 1, 2, or 3.");
        }
    }
}