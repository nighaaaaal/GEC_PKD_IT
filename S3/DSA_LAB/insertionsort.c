#include<stdio.h>
#include<time.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void insertionsort(int *arr,int size)
{
    for (int i=1;i<size;i++)
    {
        int tmp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>tmp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=tmp;
    }
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

    insertionsort(arr, n);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nThe sorted array is:");
    display(arr, n);

    printf("\n\n⏰ Insertion Sort took %f seconds to execute.\n", cpu_time_used);

    return 0;
}