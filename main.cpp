#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 任意类型pair的hash方法
struct hash_pair {
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

// k个鸡蛋 n层楼
int dp(int k, int n, unordered_map<pair<int, int>, int, hash_pair> &map) {
    // base case
    if (k == 1) return n; // 只有一个蛋了，只能线性搜索
    if (n == 0) return 0; // 没有楼层不需要扔鸡蛋

    // 备忘录
    auto p = make_pair(k, n);
    if (map.find(p) != map.end())
        return map[p];

    int res = INT_MAX;
    // 这里是遍历每个楼层的情况，跟线性搜索没关系
    for (int i = 0; i < n; ++i) {
        // 求最坏情况下，最少的扔鸡蛋次数
        res = min(res,
                  max(
                          // 这里n只是一个楼层的数量，不论是在当前层上面还是下面，只要求这个结果就行
                          dp(k - 1, i - 1, map), // 碎了
                          dp(k, n - 1, map) // 没碎
                  ) + 1
        );
    }
    return res;
}

int egg(int k, int n) {
    unordered_map<pair<int, int>, int, hash_pair> map;
    return dp(k, n, map);
}

int main() {

    return 0;
}
