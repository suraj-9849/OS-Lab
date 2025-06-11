#include <stdio.h>
#define BUFFERSIZE 3

int main()
{
    int b[BUFFERSIZE], s = 3, in = 0, out = 0, produce, consume, c;
    while (1)
    {
        printf("Enter the Choice \n 1. Produce \n 2. Consume \n 3. Exit\n\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            if ((in + 1) % s == out)
            {
                printf("Buffer is Full\n");
            }
            else
            {
                printf("Enter the value of Produce: ");
                scanf("%d", &produce);
                b[in] = produce;
                in = (in + 1) % s;
                printf("Produce: %d\n", produce);
            }
            break;
        case 2:
            if (in == out)
            {
                printf("Buffer is Empty!\n");
            }
            else
            {
                consume = b[out];
                out = (out + 1) % s;
                printf("Consume: %d\n", consume);
            }
            break;
        case 3:
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}