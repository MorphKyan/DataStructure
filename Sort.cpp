//
// Created by morph on 2021/4/28.
//

#include <algorithm>

template<typename T>

void quickSortRecursive(T arr[], int start, int end) {
    if (start >= end)
        return;
    T mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] > mid && left < right)
            right--;
        std::swap(arr[left], arr[right]);
    }
    // 应对right没动只有left动了的情况，即有序情况
    if (arr[left] >= arr[end])
        std::swap(arr[left], arr[end]);
    else
        left++;
    quickSortRecursive(arr, start, left - 1);
    quickSortRecursive(arr, left + 1, end);
}

void quickSort(T arr[], int len) {
    quickSortRecursive(arr, 0, len - 1);
}
