#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
    char type[10];
} Process;

int main() {
    int n, sq_count = 0, uq_count = 0;
    int current_time = 0;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process sq[n], uq[n], all_p[n];

    for (int i = 0; i < n; i++) {
        all_p[i].id = i + 1;
        printf("\nProcess %d Details:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &all_p[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &all_p[i].burst);
        printf("Type (System/User): ");
        scanf("%s", all_p[i].type);

        if (strcmp(all_p[i].type, "System") == 0) {
            sq[sq_count++] = all_p[i];
        } else {
            uq[uq_count++] = all_p[i];
        }
    }

    int sq_idx = 0, uq_idx = 0;
    while (sq_idx < sq_count || uq_idx < uq_count) {


        while (sq_idx < sq_count) {
            if (current_time < sq[sq_idx].arrival) {
                current_time = sq[sq_idx].arrival;
            }
            current_time += sq[sq_idx].burst;
            sq[sq_idx].completion = current_time;
            for(int i=0; i<n; i++) {
                if(all_p[i].id == sq[sq_idx].id) all_p[i].completion = current_time;
            }
            sq_idx++;
        }

        while (sq_idx == sq_count && uq_idx < uq_count) {
            if (current_time < uq[uq_idx].arrival) {
                current_time = uq[uq_idx].arrival;
            }
            current_time += uq[uq_idx].burst;
            uq[uq_idx].completion = current_time;

            for(int i=0; i<n; i++) {
                if(all_p[i].id == uq[uq_idx].id) all_p[i].completion = current_time;
            }
            uq_idx++;
        }
    }

    printf("\nID\tType\tArr\tBurst\tComp\tTAT\tWait\n");
    for (int i = 0; i < n; i++) {
        all_p[i].turnaround = all_p[i].completion - all_p[i].arrival;
        all_p[i].waiting = all_p[i].turnaround - all_p[i].burst;

        total_tat += all_p[i].turnaround;
        total_wt += all_p[i].waiting;

        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n",
            all_p[i].id, all_p[i].type, all_p[i].arrival,
            all_p[i].burst, all_p[i].completion,
            all_p[i].turnaround, all_p[i].waiting);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("1BF24CS319\n");

    return 0;
}
