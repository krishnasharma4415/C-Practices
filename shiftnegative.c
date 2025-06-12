#include <stdio.h>
int main() {
    int a[] = {-3, -1, 6, -2, 8, -4, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int temp[n];
    int pos = 0;

    for (int i = 0; i < n; i++) 
    {
        if (a[i] >= 0)
            temp[pos++] = a[i];
    }
        
    for (int i = 0; i < n; i++) 
    {
        if (a[i] < 0)
            temp[pos++] = a[i];
    }
    
    for (int i = 0; i < n; i++) 
        a[i] = temp[i];

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    return 0;
}