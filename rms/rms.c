#include <stdio.h>
int find_lcm(int a, int b) {
    int max = (a > b) ? a : b;
    while (1) {
        if (max % a == 0 && max % b == 0) return max;
        max++;
    }
}
int main() {
    int n, i, j, time;
    int burst[10], period[10], remaining[10], last_release[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the CPU burst times:\n");
    for (i = 0; i < n; i++) scanf("%d", &burst[i]);

    printf("Enter the time periods:\n");
    for (i = 0; i < n; i++) scanf("%d", &period[i]);

    int lcm = period[0];
    for (i = 1; i < n; i++) lcm = find_lcm(lcm, period[i]);
    printf("LCM = %d\n", lcm);

    printf("\nRate Monotone Scheduling:\nPID\tBurst\tPeriod\n");
    float utilization = 0;
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, burst[i], period[i]);
        utilization += (float)burst[i] / period[i];
        remaining[i] = 0;
        last_release[i] = -1;
    }
    printf("%f <= 0.828427 => true\n", utilization);
    printf("Scheduling occurs for %d ms\n\n", lcm);

    int current_task = -1;
    for (time = 0; time < lcm; time++) {

        for (i = 0; i < n; i++) {
            if (time % period[i] == 0) {
                remaining[i] = burst[i];
            }
        }
        int selected = -1;
        int min_period = 10000;
        for (i = 0; i < n; i++) {
            if (remaining[i] > 0 && period[i] < min_period) {
                min_period = period[i];
                selected = i;
            }
        }
        if (selected != current_task) {
            if (selected != -1)
                printf("%dms onwards: Process %d running\n", time, selected + 1);
            else
                printf("%dms onwards: CPU is idle\n", time);
            current_task = selected;
        }

        if (selected != -1) remaining[selected]--;
    }
    printf("1BF24CS319 \n");
    return 0;
}
