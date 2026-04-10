#include <stdio.h>
int main() {
    int n, i, time, completed = 0;
    int arrival[10], burst[10], deadline[10], period[10], remaining[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("PID %d - Burst, Deadline, Period: ", i + 1);
        scanf("%d %d %d", &burst[i], &deadline[i], &period[i]);
        arrival[i] = 0;
        remaining[i] = burst[i];
    }
    printf("\nScheduling occurs for 20 ms\n");

    for (time = 0; time < 20; time++) {
        int selected = -1;
        int min_deadline = 10000;
        for (i = 0; i < n; i++) {
            if (time % period[i] == 0) remaining[i] = burst[i];

            if (remaining[i] > 0) {
                int current_deadline = (time / period[i]) * period[i] + deadline[i];
                if (current_deadline < min_deadline) {
                    min_deadline = current_deadline;
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            printf("%dms: CPU is idle.\n", time);
        } else {
            printf("%dms: Task %d is running.\n", time, selected + 1);
            remaining[selected]--;
        }
    }
printf("1BF24CS319 \n");
    return 0;
}
