#include<stdio.h>

struct Process {
    int pid;
    int bt;
    int art;
    int pri;
    int ct;
    int tat;
    int wt;
    int isCompleted;
};

int main() {
    int n, current_time = 0, completed = 0;
    float avgwt = 0, avgtat = 0;
    struct Process p[100];
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for Process %d (AT BT Priority): ", i + 1);
        p[i].pid = i + 1;
        scanf("%d %d %d", &p[i].art, &p[i].bt, &p[i].pri);
        p[i].isCompleted = 0;
    }
    while(completed != n) {
        int idx = -1;
        int max_pri = 9999;
        for(int i = 0; i < n; i++) {
            if(p[i].art <= current_time && p[i].isCompleted == 0) {
                if(p[i].pri < max_pri) {
                    max_pri = p[i].pri;
                    idx = i;
                }
                if(p[i].pri == max_pri) {
                    if(idx != -1 && p[i].art < p[idx].art) {
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            p[idx].ct = current_time + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].art;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].isCompleted = 1;
            current_time = p[idx].ct;
            completed++;
        } else {
            current_time++;
        }
    }
    printf("\nPID\tAT\tBT\tPri\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].art, p[i].bt, p[i].pri, p[i].ct, p[i].tat, p[i].wt);
        avgwt += p[i].wt;
        avgtat += p[i].tat;
    }
    printf("\nAverage Waiting Time: %.2f", avgwt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgtat / n);
    printf("1BF24CS319");

    return 0;
}
