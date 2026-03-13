#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int completed;
};
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time for Process %d: ", i+1);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time for Process %d: ", i+1);
        scanf("%d", &p[i].bt);
        p[i].completed = 0;
    }
    int completed = 0, current_time = 0;
    float total_wt = 0, total_tat = 0, total_rt = 0;
    while(completed < n) {
        int idx = -1;
        int min_bt = 1e9;
        for(int i = 0; i < n; i++) {
            if(p[i].at <= current_time && p[i].completed == 0) {
                if(p[i].bt < min_bt) {
                    min_bt = p[i].bt;
                    idx = i;
                }
            }
        }
        if(idx == -1) {
            current_time++;
        } else {
            p[idx].ct = current_time + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].rt = p[idx].wt;
            current_time = p[idx].ct;
            p[idx].completed = 1;
            completed++;

            total_wt += p[idx].wt;
            total_tat += p[idx].tat;
            total_rt += p[idx].rt;
        }
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }
    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Response Time = %.2f\n", total_rt/n);
    printf("\n 1BF24CS319");

    return 0;
}
