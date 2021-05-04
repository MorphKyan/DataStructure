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

void bubbleSort(T arr[]) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size() - i; ++j) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

auto selectionSort(T arr[]){
    int minIdx=0;
    for(int i=0;i<arr.size();++i){
        minIdx=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]>arr[i]){
                minIdx=j;
            }
        }
        swap(arr[i],arr[j]);
    }
}