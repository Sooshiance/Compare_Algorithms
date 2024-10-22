import java.util.Arrays;
import java.util.Random;

public class SortingComparison
{
    public static void bubbleSort(int[] arr)
    {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    // Swap arr[j] and arr[j+1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public static void selectionSort(int[] arr)
    {
        int n = arr.length;

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
            // Swap arr[i] and arr[minIndex]
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    public static void quickSort(int[] arr, int low, int high)
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
                    // Swap arr[i] and arr[j]
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }

            // Swap arr[i + 1] and arr[high]
            int temp = arr[i + 1];
            arr[i + 1] = arr[high];
            arr[high] = temp;

            int pi = i + 1;

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    public static int binarySearch(int[] arr, int target)
    {
        int left = 0;
        int right = arr.length - 1;

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

    public static void measureSortingTime()
    {
        int[] sizes = {1000, 5000, 10000}; // Different sizes to test
        Random rand = new Random();

        for (int size : sizes)
        {
            int[] arr;

            // Measure Bubble Sort
            arr = rand.ints(size).toArray();
            long startTime = System.nanoTime();
            bubbleSort(arr);
            long endTime = System.nanoTime();
            System.out.println("Bubble Sort Time for size " + size + ": " +
                    (endTime - startTime) / 1000 + " microseconds");

            // Measure Selection Sort
            arr = rand.ints(size).toArray();
            startTime = System.nanoTime();
            selectionSort(arr);
            endTime = System.nanoTime();
            System.out.println("Selection Sort Time for size " + size + ": " +
                    (endTime - startTime) / 1000 + " microseconds");

            // Measure Quick Sort
            arr = rand.ints(size).toArray();
            startTime = System.nanoTime();
            quickSort(arr, 0, arr.length - 1);
            endTime = System.nanoTime();
            System.out.println("Quick Sort Time for size " + size + ": " +
                    (endTime - startTime) / 1000 + " microseconds");

            System.out.println("--------------------------------------");
        }
    }

    public static void main(String[] args)
    {
        System.out.println("\n\n\n");
        System.out.println("Sorting Algorithm Efficiency Comparison:n");

        measureSortingTime();

        int[] sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int target = 5;
        int result = binarySearch(sortedArray, target);

        if (result != -1)
            System.out.println("Element found at index: " + result + "n");
        else
            System.out.println("Element not found.n");
    }
}