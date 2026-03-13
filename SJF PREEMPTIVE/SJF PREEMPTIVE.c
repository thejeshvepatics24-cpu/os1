#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
    bool finished;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i+1);
        p[i].pid = i+1;
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].remaining = p[i].burst;
        p[i].finished = false;
    }

    int current_time = 0;
    int completed = 0;

    while (completed < n) {
        int idx = -1;
        int min_remaining = 1e9;


        for (int i = 0; i < n; i++) {
            if (!p[i].finished && p[i].arrival <= current_time && p[i].remaining < min_remaining) {
                min_remaining = p[i].remaining;
                idx = i;
            }
        }

        if (idx == -1) {
            current_time++; // No process ready
        } else {
            p[idx].remaining--;
            current_time++;

            if (p[idx].remaining == 0) {
                p[idx].completion = current_time;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
                p[idx].finished = true;
                completed++;
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival, p[i].burst,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }
    printf("1BF24CS319");

    return 0;
}
