//
// Created by morph on 2021/8/25.
//

#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int BinarySearch_LeftBound(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (left >= nums.size()) return -1;
    return nums[left] == target ? left : left - 1;
}

int BinarySearch_RightBound(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (right < 0) return -1;
    return nums[right] == target ? right : right + 1;
}

int main() {
    vector<int> nums = {1, 2, 6, 8, 9, 11, 66, 88, 97};
    auto res = BinarySearch_LeftBound(nums, 0);
    cout << res;
    res = BinarySearch_RightBound(nums, 0);
    cout << res;
    return 0;
}