#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int> &nums) {
    int n = nums.size();
    int end = 0, farthest = 0;
    // 跳跃次数
    int jumps = 0;

    for (int i = 0; i < n - 1; ++i) {
        // 找到目前所能达到的最远的地方
        farthest = max(nums[i] + i, farthest);
        // 如果到达了end说明必须要跳一次了
        if (end == i) {
            jumps++;
            end = farthest;
        }
    }
    return jumps;
}

int main() {

    return 0;
}
