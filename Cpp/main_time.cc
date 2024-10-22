#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// Function to perform Bubble Sort
void bubbleSort(std::vector<std::int32_t> &arr)
{
    std::int32_t n = arr.size();

    for (std::int32_t i = 0; i < n - 1; i++)
    {
        for (std::int32_t j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(std::vector<std::int32_t> &arr)
{
    std::int32_t n = arr.size();

    for (std::int32_t i = 0; i < n - 1; i++)
    {
        std::int32_t minIndex = i;

        for (std::int32_t j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);
    }
}

// Function to perform Quick Sort
void quickSort(std::vector<std::int32_t> &arr, std::int32_t low, std::int32_t high)
{
    if (low < high)
    {
        std::int32_t pivot = arr[high];
        std::int32_t i = low - 1;

        for (std::int32_t j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);
        std::int32_t pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


/*

You can add more Sort functions to compare later on

*/


// Function for Binary Search
int binarySearch(const std::vector<std::int32_t> &arr, std::int32_t target)
{
    std::int32_t left = 0;
    std::int32_t right = arr.size() - 1;

    while (left <= right)
    {
        std::int32_t mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Not found
}

// Function to measure time taken by sorting algorithms
void measureSortingTime()
{
    std::vector<std::int32_t> sizes = {1000, 5000, 10000}; // Different sizes to test

    for (int size : sizes)
    {
        std::vector<std::int32_t> arr(size);
        generate(arr.begin(), arr.end(), rand); // Fill with random numbers

        // Measure Bubble Sort
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(arr);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Bubble Sort Time for size " << size << ": "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << "\n";

        // Measure Selection Sort
        generate(arr.begin(), arr.end(), rand); // Regenerate random numbers
        start = std::chrono::high_resolution_clock::now();
        selectionSort(arr);
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Selection Sort Time for size " << size << ": "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << "\n";

        // Measure Quick Sort
        generate(arr.begin(), arr.end(), rand); // Regenerate random numbers
        start = std::chrono::high_resolution_clock::now();
        quickSort(arr, 0, arr.size() - 1);
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Quick Sort Time for size " << size << ": "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << "\n";
        
        /*
        Add your other sort functions here to
        measure the time complexity 

        CAUTION:
        You should add details of them just like what I did above

        */

        std::cout << "-----------------------------------" << "\n";
    }
}

int main()
{
    std::cout << "Sorting Algorithm Efficiency Comparison:" << "\n\n";
    measureSortingTime();

    // Example usage of Binary Search
    std::vector<std::int32_t> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::int32_t target = 5;
    std::int32_t result = binarySearch(sortedArray, target);
    if (result != -1)
        std::cout << "Element found at index: " << result << "\n\n";
    else
        std::cout << "Element not found." << "\n\n";

    return 0;
}
