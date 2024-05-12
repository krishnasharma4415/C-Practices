#include <stdio.h>

struct Job
{
    char id;
    int profit;
    int deadline;
};

int compareJobs(const void *a, const void *b)
{
    struct Job *job1 = (struct Job *)a;
    struct Job *job2 = (struct Job *)b;
    return job2->profit - job1->profit;
}

int findMaxDeadline(struct Job jobs[], int n)
{
    int max_deadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > max_deadline)
        {
            max_deadline = jobs[i].deadline;
        }
    }
    return max_deadline;
}

void scheduleJobs(struct Job jobs[], int n)
{
    qsort(jobs, n, sizeof(jobs[0]), compareJobs);

    int max_deadline = findMaxDeadline(jobs, n);

    int slot[max_deadline];
    for (int i = 0; i < max_deadline; i++)
    {
        slot[i] = -1;
    }

    int count = 0;
    int total_profit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = jobs[i].id;
                count++;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Scheduled jobs:\n");
    printf("Job ID  | Deadline | Profit\n");
    printf("--------|----------|--------\n");
    for (int i = 0; i < max_deadline; i++)
    {
        if (slot[i] != -1)
        {
            printf("  %c     |    %d     |  %d\n", slot[i], i + 1, jobs[i].profit);
        }
    }
    printf("Total profit earned: %d\n", total_profit);
}

int main()
{
    struct Job jobs[] = {{'a', 100, 2}, {'b', 19, 1}, {'c', 27, 2}, {'d', 25, 1}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    scheduleJobs(jobs, n);

    return 0;
}
