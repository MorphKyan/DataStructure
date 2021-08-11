//
// Created by morph on 2021/5/4.
//

#include "string"
#include "vector"
#include "unordered_map"

using namespace std;

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> valToIdx;

    bool insert(int val) {
        // 存在
        if (valToIdx.count(val)) {
            return false;
        }
        // 不存在，插入
        valToIdx[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        // 不存在
        if (!valToIdx.count(val)) {
            return false;
        }
        // 存在，删除
        int idx = valToIdx[val];
        // 删除val索引
        valToIdx.erase(val);
        // 要删除的换到结尾，并删除
        swap(nums[idx], nums.back());
        nums.pop_back();
        // 换过来的末尾元素，修改map索引
        valToIdx[nums[idx]] = idx;
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};