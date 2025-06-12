#include <stdio.h>
#include <stdbool.h>

struct Process
{
    int id, burst_time, priority, arrival_time, wait_time, turnaround_time;
};

void sortProcesses(struct Process proc[], int n, char key)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((key == 'A' && proc[j].arrival_time > proc[j + 1].arrival_time) ||
                (key == 'B' && proc[j].burst_time > proc[j + 1].burst_time) ||
                (key == 'P' && proc[j].priority > proc[j + 1].priority))
            {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

void calculateTimes(struct Process proc[], int n)
{
    int current_time = proc[0].arrival_time;
    for (int i = 0; i < n; i++)
    {
        proc[i].wait_time = (current_time > proc[i].arrival_time ? current_time : proc[i].arrival_time) - proc[i].arrival_time;
        current_time += proc[i].burst_time;
        proc[i].turnaround_time = proc[i].wait_time + proc[i].burst_time;
    }
}

void display(struct Process proc[], int n, const char *algorithm)
{
    printf("\n%s Scheduling\n", algorithm);
    printf("P#\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", proc[i].id, proc[i].arrival_time, proc[i].burst_time, proc[i].wait_time, proc[i].turnaround_time);
}

void fcfs(struct Process proc[], int n)
{
    sortProcesses(proc, n, 'A');
    calculateTimes(proc, n);
    display(proc, n, "First Come First Serve (FCFS)");
}

void sjf(struct Process proc[], int n)
{
    sortProcesses(proc, n, 'B');
    calculateTimes(proc, n);
    display(proc, n, "Shortest Job First (SJF)");
}

void priority(struct Process proc[], int n)
{
    sortProcesses(proc, n, 'P');
    calculateTimes(proc, n);
    display(proc, n, "Priority");
}

void roundRobin(struct Process proc[], int n, int quantum)
{
    int remaining[n], t = 0, completed = 0;
    for (int i = 0; i < n; i++)
        remaining[i] = proc[i].burst_time;

    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (remaining[i] > 0)
            {
                int exec_time = (remaining[i] > quantum) ? quantum : remaining[i];
                t += exec_time;
                remaining[i] -= exec_time;

                if (remaining[i] == 0)
                {
                    completed++;
                    proc[i].wait_time = t - proc[i].burst_time - proc[i].arrival_time;
                    proc[i].turnaround_time = proc[i].burst_time + proc[i].wait_time;
                }
            }
        }
    }
    display(proc, n, "Round Robin");
}

int main()
{
    int n, choice, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];
    for (int i = 0; i < n; i++)
    {
        proc[i].id = i + 1;
        printf("P%d - Arrival Time, Burst Time, Priority: ", i + 1);
        scanf("%d %d %d", &proc[i].arrival_time, &proc[i].burst_time, &proc[i].priority);
    }

    printf("1. FCFS\n2. SJF\n3. Priority\n4. Round Robin\nChoose: ");
    scanf("%d", &choice);

    if (choice == 4)
    {
        printf("Enter time quantum: ");
        scanf("%d", &quantum);
    }

    switch (choice)
    {
    case 1:
        fcfs(proc, n);
        break;
    case 2:
        sjf(proc, n);
        break;
    case 3:
        priority(proc, n);
        break;
    case 4:
        roundRobin(proc, n, quantum);
        break;
    default:
        printf("Invalid choice\n");
    }

    return 0;
}
