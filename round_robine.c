#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;              // Process ID
    int burstTime;       // Burst Time (CPU Time needed)
    int remainingTime;   // Remaining Burst Time
    int waitingTime;     // Waiting Time
    int turnaroundTime;  // Turnaround Time
    int arrivalTime;     // Arrival Time
};

// Function to find waiting time of all processes
void findWaitingTime(struct Process processes[], int n, int quantum) {
    int time = 0;  // Current time
    int done;

    while (1) {
        done = 1;  // Assume all are done

        for (int i = 0; i < n; i++) {
            // Execute process only if it has arrived and has remaining time
            if (processes[i].remainingTime > 0 && processes[i].arrivalTime <= time) {
                done = 0;  // There is at least one process pending

                if (processes[i].remainingTime > quantum) {
                    time += quantum;
                    processes[i].remainingTime -= quantum;
                } else {
                    time += processes[i].remainingTime;
                    processes[i].waitingTime = time - processes[i].burstTime - processes[i].arrivalTime;
                    if (processes[i].waitingTime < 0)
                        processes[i].waitingTime = 0;
                    processes[i].remainingTime = 0;
                }
            }
        }

        // If all processes are done, exit the loop
        if (done == 1)
            break;

        // If CPU is idle (no process has arrived yet)
        int nextArrival = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                if (nextArrival == -1 || processes[i].arrivalTime < nextArrival)
                    nextArrival = processes[i].arrivalTime;
            }
        }
        if (nextArrival > time)
            time = nextArrival;
    }
}

// Function to find Turnaround Time
void findTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++)
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
}

// Function to calculate average time
void findAvgTime(struct Process processes[], int n, int quantum) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    findWaitingTime(processes, n, quantum);
    findTurnaroundTime(processes, n);

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
        printf("%d\t%d\t%d\t%d\t%d\n",
               processes[i].id,
               processes[i].arrivalTime,
               processes[i].burstTime,
               processes[i].waitingTime,
               processes[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time: %.2f", (float)totalWaitingTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Arrival Time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    printf("\n--- Round Robin Scheduling (with Arrival Time) ---\n");
    findAvgTime(processes, n, quantum);

    return 0;
}
x