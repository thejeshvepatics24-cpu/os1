#include <stdio.h>
#include <stdbool.h>

#define MAX 20

// Function prototypes with clear variable names
void firstFitFixed(int blocks[], int numBlocks, int processes[], int numProcesses);
void bestFitFixed(int blocks[], int numBlocks, int processes[], int numProcesses);
void worstFitFixed(int blocks[], int numBlocks, int processes[], int numProcesses);
void printAllocation(int processes[], int numProcesses, int allocation[]);

int main() {
    // Renamed m -> numBlocks and n -> numProcesses
    int numBlocks = 5; 
    int numProcesses = 4;
    
    int blocks[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    printf("--- 1BF24CS319 ---\n");

    printf("--- Fixed Partition Allocation (Clear Variables) ---\n");

    firstFitFixed(blocks, numBlocks, processes, numProcesses);
    bestFitFixed(blocks, numBlocks, processes, numProcesses);
    worstFitFixed(blocks, numBlocks, processes, numProcesses);

    return 0;
}

// 1. FIRST-FIT
void firstFitFixed(int blocks[], int numBlocks, int processes[], int numProcesses) {
    int allocation[MAX];
    bool blockOccupied[MAX];
    
    for (int i = 0; i < numProcesses; i++) allocation[i] = -1;
    for (int j = 0; j < numBlocks; j++) blockOccupied[j] = false;

    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numBlocks; j++) {
            if (!blockOccupied[j] && blocks[j] >= processes[i]) {
                allocation[i] = j;
                blockOccupied[j] = true; 
                break; 
            }
        }
    }
    printf("\n--> FIRST-FIT RESULTS <--\n");
    printAllocation(processes, numProcesses, allocation);
}

// 2. BEST-FIT
void bestFitFixed(int blocks[], int numBlocks, int processes[], int numProcesses) {
    int allocation[MAX];
    bool blockOccupied[MAX];
    
    for (int i = 0; i < numProcesses; i++) allocation[i] = -1;
    for (int j = 0; j < numBlocks; j++) blockOccupied[j] = false;

    for (int i = 0; i < numProcesses; i++) {
        int bestIdx = -1;
        for (int j = 0; j < numBlocks; j++) {
            if (!blockOccupied[j] && blocks[j] >= processes[i]) {
                if (bestIdx == -1 || blocks[j] < blocks[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockOccupied[bestIdx] = true; 
        }
    }
    printf("\n--> BEST-FIT RESULTS <--\n");
    printAllocation(processes, numProcesses, allocation);
}

// 3. WORST-FIT
void worstFitFixed(int blocks[], int numBlocks, int processes[], int numProcesses) {
    int allocation[MAX];
    bool blockOccupied[MAX];
    
    for (int i = 0; i < numProcesses; i++) allocation[i] = -1;
    for (int j = 0; j < numBlocks; j++) blockOccupied[j] = false;

    for (int i = 0; i < numProcesses; i++) {
        int worstIdx = -1;
        for (int j = 0; j < numBlocks; j++) {
            if (!blockOccupied[j] && blocks[j] >= processes[i]) {
                if (worstIdx == -1 || blocks[j] > blocks[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockOccupied[worstIdx] = true; 
        }
    }
    printf("\n--> WORST-FIT RESULTS <--\n");
    printAllocation(processes, numProcesses, allocation);
}

void printAllocation(int processes[], int numProcesses, int allocation[]) {
    printf("-------------------------------------------------------\n");
    printf("| Process No. | Process Size | Block No. Allocated |\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("| %-11d | %-12d | ", i + 1, processes[i]);
        if (allocation[i] != -1) {
            printf("%-19d |\n", allocation[i] + 1);
        } else {
            printf("%-19s |\n", "Not Allocated");
        }
    }
    printf("-------------------------------------------------------\n");
}