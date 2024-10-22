import random
import time


def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]


def quick_sort(arr, low, high):
    if low < high:
        pivot = arr[high]
        i = low - 1
        for j in range(low, high):
            if arr[j] < pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        pi = i + 1
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)


# TODO: You can add more algorithms to compare later on


def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1


def measure_sorting_time():
    sizes = [1000, 5000, 10000]  # Different sizes to test

    for size in sizes:
        arr = [random.randint(0, 10000) for _ in range(size)]

        # Measure Bubble Sort
        start = time.perf_counter()
        bubble_sort(arr.copy())
        end = time.perf_counter()
        print(f"Bubble Sort Time for size {size}: {(end - start) * 1e6:.2f} microseconds")

        # Measure Selection Sort
        start = time.perf_counter()
        selection_sort(arr.copy())
        end = time.perf_counter()
        print(f"Selection Sort Time for size {size}: {(end - start) * 1e6:.2f} microseconds")

        # Measure Quick Sort
        start = time.perf_counter()
        quick_sort(arr.copy(), 0, len(arr) - 1)
        end = time.perf_counter()
        print(f"Quick Sort Time for size {size}: {(end - start) * 1e6:.2f} microseconds")

        print("-----------------------------------")


if __name__ == "__main__":
    print("\n\n\n\n\n\n")
    print("Sorting Algorithm Efficiency Comparison:")
    measure_sorting_time()

    sorted_array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    target = 5
    result = binary_search(sorted_array, target)
    if result != -1:
        print(f"Element found at index: {result}")
    else:
        print("Element not found")
