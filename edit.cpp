//
// Created by morph on 2021/4/26.
//

#include "string"
#include "vector"

using namespace std;


// 自底向上
int minDistance(string s, string s1, string s2) {
    if (s[i] == s[j])
        dp[i][j] = dp[i + 1][j - 1] + 2;
    else
        // 把左边包进来后最长回文 或 右边包进来最长回文 的最大值
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void QuickSort(vector<int>& nums, int l, int r) {
        if (l < r)
        {
            int mid = partition(nums, l, r);
            QuickSort(nums, l, mid - 1);//注意点，l和r的值自己写错
            QuickSort(nums, mid + 1, r);//注意点,l和r的值自己写错
        }
    }
    int partition(vector<int>& nums, int l, int r)
    {
        int pivot = nums[l];
        int i = l + 1, j = r;
        while (true)
        {
            while (i <= j && nums[i] <= pivot) i++;//寻找比pivot大的元素
            while (i <= j && nums[j] >= pivot) j--;//寻找比pivot小的元素
            if(i>j) break;
            swap(nums[i], nums[j]);
        }
        //把arr[j]和主元交换
        swap(nums[j], nums[l]);
        return j;//为什么返回j而不是i，因为swap是先执行i++的while语句，如果和下面的替换顺序，则返回i
    }
};