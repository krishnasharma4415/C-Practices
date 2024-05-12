#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compareBoards(const void *a, const void *b)
{
    return *(int *)b - *(int *)a; // Sort boards in descending order
}

int minimizePaintingTime(int boards[], int n, int num_parameters)
{
    // Sort boards in descending order (prioritize longer boards).
    qsort(boards, n, sizeof(int), compareBoards);

    // Initialize current painting times for each parameter.
    int current_times[num_parameters]; // Use the actual number of parameters
    for (int i = 0; i < num_parameters; i++)
    {
        current_times[i] = 0;
    }

    // Assign boards to the parameter with the least current painting time.
    for (int i = 0; i < n; i++)
    {
        int min_time_index = 0;
        for (int j = 1; j < num_parameters; j++)
        { // Use the actual number of parameters
            if (current_times[j] < current_times[min_time_index])
            {
                min_time_index = j;
            }
        }
        current_times[min_time_index] += boards[i];
    }

    // Maximum time taken by any parameter is the minimum completion time.
    int max_time = current_times[0];
    for (int i = 1; i < num_parameters; i++)
    {
        max_time = fmax(max_time, current_times[i]);
    }

    return max_time;
}

int main()
{
    int boards[] = {5, 3, 2};
    int n = sizeof(boards) / sizeof(boards[0]);
    int num_parameters = 2;
    int min_time = minimizePaintingTime(boards, n, num_parameters);
    printf("Minimum time to color all boards: %d\n", min_time);
    return 0;
}
