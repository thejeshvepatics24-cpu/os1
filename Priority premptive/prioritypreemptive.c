#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int bt_remaining;
    int priority;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time, Burst Time, Priority for P%d: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
        p[i].bt_remaining = p[i].bt;
    }

    int completed = 0, time = 0;
    while (completed != n) {
        int idx = -1;
        int highest_priority = 999999;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].bt_remaining > 0) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
                else if (p[i].priority == highest_priority) {
                    if (p[i].at < p[idx].at) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            p[idx].bt_remaining--;
            time++;

            if (p[idx].bt_remaining == 0) {
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                completed++;
            }
        } else {
            time++;
        }
    }
    float total_tat = 0 , total_wt = 0;
  for(int i=0 ; i<n ; i++){
    total_tat += p[i].tat;
    total_wt += p[i].wt;
  }
    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].priority,
               p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat/n);
    printf("1BF24CS319");
    return 0;
}