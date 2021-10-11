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
vector<int> memo;

void dfs(vector<int> &prices, int idx, int k) {
    if (k == 0 && sum == target) {
        ++ans;
        return;
    }
    if (k == 0 || idx + k > prices.size() || sum > target) return;
    // 不选
    dfs(prices, idx + 1, k);
    // 选
    sum += prices[idx];
    if(sum>target)
        return;
    dfs(prices, idx + 1, k - 1);
}

int main() {
    auto total_num = 0, total_price = 0, num = 0;
    cin >> total_num >> total_price >> num;
    target = total_price;

    vector<int> prices(num, 0);
    for (int i = 0; i < num; ++i) {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end(), less<int>());
    for(auto x:prices){
        cout<<x;
    }

    dfs(prices, 0, total_num);

    cout << ans;

    return 0;
}