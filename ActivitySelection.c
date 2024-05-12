#include <stdio.h>

struct Activity
{
  int start;
  int finish;
};

int compareActivities(const void *a, const void *b)
{
  struct Activity *activity1 = (struct Activity *)a;
  struct Activity *activity2 = (struct Activity *)b;
  return activity1->finish - activity2->finish;
}

void printMaxActivities(struct Activity arr[], int n)
{
  qsort(arr, n, sizeof(arr[0]), compareActivities);

  printf("Following activities can be done without conflict:\n");
  int i = 0;
  printf("(%d, %d) ", arr[i].start, arr[i].finish);

  for (int j = 1; j < n; j++)
  {
    if (arr[j].start >= arr[i].finish)
    {
      printf("(%d, %d) ", arr[j].start, arr[j].finish);
      i = j;
    }
  }
  printf("\n");
}

int main()
{
  struct Activity arr[] = {{5, 9}, {1, 2}, {0, 6}, {8, 9}, {2, 4}, {7, 8}};
  int n = sizeof(arr) / sizeof(arr[0]);

  printMaxActivities(arr, n);

  return 0;
}
