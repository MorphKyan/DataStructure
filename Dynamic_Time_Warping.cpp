//
// Created by morph on 2021/5/19.
//
#include <vector>

using namespace std;

// 输入类型为 int float double
template<typename T>
T DTW(vector<T> &A, vector<T> &B) {
    int m = A.size();
    int n = B.size();
    if (m == 0 || n == 0) return T();
    vector<vector<T>> dp(m, vector<T>(n, 0));

    // base case
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = abs(A[i] - B[j]);
        }
    }

    // DP
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                dp[i][j] += dp[i - 1][j];
            } else {
                dp[i][j] += min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    return dp[m - 1][n - 1];
}