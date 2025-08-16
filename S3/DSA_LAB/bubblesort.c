#include <stdio.h>
#include <time.h> // 1. Include the time header

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("\n%d", arr[i]);
    }
}

// It's standard practice for main to return an int
int main() {
    int n;
    printf("Enter the number of terms in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the details of the array:");
    for (int i = 0; i < n; i++) {
        printf("\nEnter element(%d): ", i + 1);
        scanf("%d", &arr[i]);
    }

    // --- Timing Logic Starts Here ---

    // 2. Declare variables for timing
    clock_t start, end;
    double cpu_time_used;

    // 3. Record the start time
    start = clock();

    // Call the function you want to measure
    bubblesort(arr, n);

    // 4. Record the end time
    end = clock();

    // 5. Calculate the time elapsed in seconds
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // --- Timing Logic Ends Here ---

    printf("\nThe sorted array is:");
    display(arr, n);

    // Print the final execution time
    printf("\n\n⏰ Bubble sort took %f seconds to execute.\n", cpu_time_used);

    return 0;
}