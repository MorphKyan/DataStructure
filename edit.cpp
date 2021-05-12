//
// Created by morph on 2021/4/26.
//

#include "string"
#include "vector"
#include "unordered_map"
#include "random"

using namespace std;

// 索引从1开始，W是重量，n是物品
int backPack(int m, int n, vector<int> &prices, vector<int> &val) {
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));
    // 不动，卖出
    for (int k = 1; k < max_k; ++k) {
        if (i - 1 = -1) {
            // 处理base case
        }
        dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
        dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
    }
    dp[-1][k][b] = 0;
    dp[i][0][b] = 0;
}