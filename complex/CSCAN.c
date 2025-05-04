#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, head, direction, n;
    printf("Enter the n(no of disks): ");
    scanf("%d", &n);

    int requests[n + 2]; // include head and boundary
    printf("Enter the requests:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the Head: ");
    scanf("%d", &head);

    printf("Enter the Direction left-0 right-1: ");
    scanf("%d", &direction);

    requests[n++] = head;

    // Add boundary based on direction
    int diskSize = 199;
    if (direction == 1)
        requests[n++] = diskSize;
    else
        requests[n++] = 0;

    // Sort the requests
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    // Find head index
    int pos = 0;
    for (i = 0; i < n; i++) {
        if (requests[i] == head) {
            pos = i;
            break;
        }
    }

    int totalSeek = 0;
    printf("Seek Sequence:\n");

    if (direction == 1) {
        // Move right
        for (i = pos; i < n; i++) {
            printf("%d -> ", requests[i]);
            if (i != pos)
                totalSeek += abs(requests[i] - requests[i - 1]);
        }

        // Jump from end to start
        totalSeek += abs(diskSize - 0);
        printf("0 -> ");

        for (i = 0; i < pos; i++) {
            printf("%d -> ", requests[i]);
            if (i != 0)
                totalSeek += abs(requests[i] - requests[i - 1]);
            else
                totalSeek += abs(requests[i] - 0);
        }
    } else {
        // Move left
        for (i = pos; i >= 0; i--) {
            printf("%d -> ", requests[i]);
            if (i != pos)
                totalSeek += abs(requests[i] - requests[i + 1]);
        }

        // Jump from 0 to diskSize
        totalSeek += abs(0 - diskSize);
        printf("%d -> ", diskSize);

        for (i = n - 1; i > pos; i--) {
            printf("%d -> ", requests[i]);
            if (i != n - 1)
                totalSeek += abs(requests[i] - requests[i + 1]);
            else
                totalSeek += abs(requests[i] - diskSize);
        }
    }

    printf("END\nTotal Seek Time: %d\n", totalSeek);
    return 0;
}
