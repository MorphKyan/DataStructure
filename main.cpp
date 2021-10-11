//
// Created by morph on 2021/8/25.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;
int sum = 0;
int target = 0;

void dfs(vector<int> &prices, int idx, int k) {
    if (k == 0 && sum == target) {
        ++ans;
        return;
    }
    if (k == 0 || idx + k > prices.size() || sum > target) return;
    // 选
    if (sum > target)
        return;
    dfs(prices, idx + 1, k - 1);
    // 不选
    sum -= prices[idx];
    dfs(prices, idx + 1, k);
}

class A {
public:
    static int y;

    A() : x(0) {

    }

    const int x;
};

int A::y = 0;

int main() {
    // auto total_num = 0, total_price = 0, num = 0;
    // cin >> total_num >> total_price >> num;
    // target = total_price;
    int a = 1;
    const int b = a;
    static int c = a;
    A a1;
    A a2;


    // vector<int> prices(num, 0);
    // for (int i = 0; i < num; ++i) {
    //     cin >> prices[i];
    // }
    // dfs(prices, 0, total_num);
    //
    // cout << ans;

    return 0;
}