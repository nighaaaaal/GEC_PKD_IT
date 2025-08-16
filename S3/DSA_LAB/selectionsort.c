#include<stdio.h>
#include<time.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int *arr,int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[min_index]>arr[j])
            {
                min_index=j;
            }
        }
        if(i!=min_index)
        {
            swap(&arr[i],&arr[min_index]);
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
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter element(%d): ",i+1);
        scanf("%d", &arr[i]);
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    selectionsort(arr, n);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nThe sorted array is:");
    display(arr, n);

    printf("\n\n⏰ Selection Sort took %f seconds to execute.\n", cpu_time_used);

    return 0;
}