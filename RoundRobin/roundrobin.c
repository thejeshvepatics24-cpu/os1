#include <stdio.h>
#include <stdbool.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    bool is_completed;
    bool in_queue;
};

int main() {
    int n, time_quantum, completed = 0, current_time = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    struct Process p[n];
    int queue[1000]; 
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].is_completed = false;
        p[i].in_queue = false;
    }

    for (int i = 0; i < n; i++) {
        if (p[i].arrival_time <= current_time) {
            queue[rear++] = i;
            p[i].in_queue = true;
        }
    }

    while (completed < n) {
        if (front == rear) {
            current_time++;
            for (int i = 0; i < n; i++) {
                if (p[i].arrival_time <= current_time && !p[i].is_completed && !p[i].in_queue) {
                    queue[rear++] = i;
                    p[i].in_queue = true;
                }
            }
            continue;
        }

        int i = queue[front++];
        
        if (p[i].remaining_time > time_quantum) {
            current_time += time_quantum;
            p[i].remaining_time -= time_quantum;
        } else {
            current_time += p[i].remaining_time;
            p[i].remaining_time = 0;
            p[i].is_completed = true;
            completed++;
            p[i].completion_time = current_time;
            p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
            p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        }

        for (int j = 0; j < n; j++) {
            if (p[j].arrival_time <= current_time && !p[j].is_completed && !p[j].in_queue) {
                queue[rear++] = j;
                p[j].in_queue = true;
            }
        }

        if (!p[i].is_completed) {
            queue[rear++] = i;
        }
    }

    float total_wt = 0, total_tat = 0;
    printf("\nID\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].waiting_time, p[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\n1BF24CS319\n");

    return 0;
}