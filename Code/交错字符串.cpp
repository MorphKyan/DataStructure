//
// Created by morph on 2021/8/12.
//

// 给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的
// 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// 输出：true
// 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// 输出：false

#include <vector>
#include <string>

using namespace std;

bool rec(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &memo) {
    // 这里注意！如果只是判断true false，那么在false的时候相当于没有memo，依然会做一系列操作
    if (memo[i][j] != -1)
        return memo[i][j];
    if (k == s3.size()) {
        memo[i][j] = true;
        return true;
    }
    bool ok = false;
    if (i < s1.size() && s1[i] == s3[k]) {
        ok = ok || rec(s1, s2, s3, i + 1, j, k + 1, memo);
    }
    if (j < s2.size() && s2[j] == s3[k]) {
        ok = ok || rec(s1, s2, s3, i, j + 1, k + 1, memo);
    }
    memo[i][j] = ok ? 1 : 0;
    return ok;
}

bool isInterleave(string s1, string s2, string s3) {
    vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    if (s1.size() + s2.size() != s3.size()) return false;
    return rec(s1, s2, s3, 0, 0, 0, memo);
}