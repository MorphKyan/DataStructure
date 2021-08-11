//
// Created by morph on 2021/8/11.
//
// 题目：
// 有n堆石子，每堆有a[i]个石子。男、女两个人轮流取，每次从任意一个堆中取一个石子。
// 当一个人取之前所有堆都是空的，或者取之后存在两个堆的石子数量相同(可能都为空)，则这个人输。
// 男的先取，两人取石子都使用对自己最有利的策略，输出最后的赢家。

// 首先，先手有三种情况不能动
// 之后，计算移动成递增序列的次数
// 最后，判断谁赢

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    auto n = 0;
    cin >> n;
    while (n) {
        --n;
        auto stone_size = 0;
        cin >> stone_size;
        map<int, int> data;
        auto cnt0 = 0, cnt2 = 0, sum = 0, tmp = 0;
        bool flag = false;
        for (auto i = 0; i < stone_size; ++i) {
            cin >> tmp;
            data[tmp]++;
            if (tmp == 0) cnt0++;
            if (data[tmp] == 2) cnt2++;
            if (data[tmp] == 3) flag = true;
            sum += tmp;

        }
        if (flag || cnt0 == stone_size || cnt2 >= 2) {
            cout << "woman\n";
            continue;

        }
        auto step = sum - (stone_size - 1) * stone_size / 2;
        step % 2 ? cout << "man\n" : cout << "woman\n";

    }
    return 0;
}