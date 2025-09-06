#include<stdio.h>
#include<time.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr,int start,int end)
{
    int pivot=arr[end];
    int i=start-1;
    for(int j=start;j<=end-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    i++;
    swap(&arr[i],&arr[end]);
    return i;
}

void quicksort(int *arr,int start,int end)
{
    if(end<=start)
    {
    return;
    }
    int pivot=partition(arr,start,end);
    quicksort(arr,start,pivot-1);
    quicksort(arr,pivot+1,end);
}

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\n%d", arr[i]);
    }
}

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

    quicksort(arr,0,n-1);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nThe sorted array is:");
    display(arr, n);

    printf("\n\n⏰ Quick Sort took %f seconds to execute.\n", cpu_time_used);

    return 0;
}