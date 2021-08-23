//
// Created by morph on 2021/8/23.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void BuildMaxHeap(vector<int> &nums) {
    auto nums_size = nums.size();
    for (int i = (nums_size - 1) / 2; i >= 0; --i) {
        auto l = i * 2 + 1, r = l + 1;
        auto new_root = i;
        if (l < nums_size && nums[l] > nums[new_root]) {
            new_root = l;
        }
        if (r < nums_size && nums[r] > nums[new_root]) {
            new_root = r;
        }

        // the biggest is not the root
        if (new_root != i) {
            swap(nums[i], nums[new_root]);
        }
    }
}

void CheckAndMaintain(vector<int> &nums, int nums_size, int idx) {
    auto l = 2 * idx + 1, r = l + 1;
    auto new_root = idx;
    if (l < nums_size && nums[l] > nums[new_root]) {
        new_root = l;
    }
    if (r < nums_size && nums[r] > nums[new_root]) {
        new_root = r;
    }

    // the biggest is not the root
    if (new_root != idx) {
        swap(nums[idx], nums[new_root]);
        CheckAndMaintain(nums, nums_size, new_root);
    }
}

void MaxHeapSort(vector<int> &nums, int size) {
    for(;size>0;--size){
        swap(nums[0], nums[size]);
        // check and maintain
        CheckAndMaintain(nums, size - 1, 0);
    }
}

int main() {
    vector<int> nums = {7, 3, 8, 5, 1, 2};
    BuildMaxHeap(nums);
    MaxHeapSort(nums, nums.size() - 1);
    for (auto x:nums) {
        cout << x << " ";
    }
    return 0;
}