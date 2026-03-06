#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
};

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n], temp;


    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
    }


    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int current_time = 0;

    for(i = 0; i < n; i++) {

        if(current_time < p[i].at)
            current_time = p[i].at;

        p[i].ct = current_time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        current_time = p[i].ct;
    }


    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    float total_wt = 0, total_tat = 0;

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);

        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Thejesh Vepati Balaji 1BF24CS319");


    return 0;
}
