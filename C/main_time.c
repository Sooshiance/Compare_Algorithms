#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];

        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(int *arr, int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Not found
}

void measureSortingTime()
{
    int sizes[] = {1000, 5000, 10000}; // Different sizes to test
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numSizes; i++)
    {
        int size = sizes[i];
        int *arr = (int *)malloc(size * sizeof(int));

        // Fill with random numbers
        for (int j = 0; j < size; j++)
        {
            arr[j] = rand() % 10000; // Random numbers between 0 and 9999
        }
        printf("\n\n");

        // Measure Bubble Sort
        clock_t start = clock();
        bubbleSort(arr, size);
        clock_t end = clock();
        printf("Bubble Sort Time for size %d: %lf microseconds", size,
               ((double)(end - start) / CLOCKS_PER_SEC) * 1e6);

        // Regenerate random numbers
        for (int j = 0; j < size; j++)
        {
            arr[j] = rand() % 10000;
        }
        printf("\n\n");

        // Measure Selection Sort
        start = clock();
        selectionSort(arr, size);
        end = clock();
        printf("Selection Sort Time for size %d: %lf microseconds", size,
               ((double)(end - start) / CLOCKS_PER_SEC) * 1e6);

        // Regenerate random numbers
        for (int j = 0; j < size; j++)
        {
            arr[j] = rand() % 10000;
        }
        printf("\n\n");

        // Measure Quick Sort
        start = clock();
        quickSort(arr, 0, size - 1);
        end = clock();
        printf("Quick Sort Time for size %d: %lf microseconds", size,
               ((double)(end - start) / CLOCKS_PER_SEC) * 1e6);

        printf("\n-----------------------------------");

        free(arr); // Free allocated memory
    }

    printf("\n");
}

int main()
{
    printf("\n\n\n\n");
    printf("Sorting Algorithm Efficiency Comparison:");
    measureSortingTime();

    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;
    int result = binarySearch(sortedArray, sizeof(sortedArray) / sizeof(sortedArray[0]), target);

    printf("\n");

    if (result != -1)
        printf("Element found at index: %d", result);
    else
        printf("Element not found.");

    printf("\n\n");

    return 0;
}