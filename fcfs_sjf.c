#include <stdio.h>

void calculateTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void calculateWaitingTime(int n, int bt[], int wt[]) {
    wt[0] = 0; // First process doesn't have to wait

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
}

void fcfs(int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    calculateWaitingTime(n, bt, wt);
    calculateTurnaroundTime(n, bt, wt, tat);

    printf("FCFS Scheduling:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];

        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

void sjfNonPreemptive(int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    int temp, p[n], i, j;

    for (i = 0; i < n; i++) {
        p[i] = i;
    }

    // Sort the processes based on burst time using selection sort
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process number
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    calculateWaitingTime(n, bt, wt);
    calculateTurnaroundTime(n, bt, wt, tat);

    printf("\nSJF (Non-Preemptive) Scheduling:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];

        printf("%d\t%d\t\t%d\t\t%d\n", p[i] + 1, bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n];

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    fcfs(n, bt);
    sjfNonPreemptive(n, bt);

    return 0;
}
