#include <iostream>
#include <vector>
#include <string>
#include "Code/MyUtility.cpp"

using namespace std;

auto x = 0, y = 0, len = 0;

int dp(string s1, int i, string s2, int j, vector<vector<int>> &memo) {
    // base
    if (i == s1.size() || j == s2.size())
        return 0;
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (s1[i] == s2[j]) {
        memo[i][j] = 1 + dp(s1, i - 1, s2, j - 1, memo);
    } else {
        memo[i][j] = 0;
    }
    len = memo[i][j];
    return memo[i][j];
}

int main() {
    string s1 = "";
    string s2 = "";

    while (getline(cin, s1)) {
        getline(cin, s2);
        if (s1.length() > s2.length())
            swap(s1, s2); // s1用于保存较短的子串
        vector<vector<int>> memo(s1.size(), vector<int>(s2.size(), -1));
        for (int i = 0; i < s1.size(); ++i) {
            memo[i][0] = s1[i] == s2[0] ? 1 : 0;
        }
        for (int i = 0; i < s2.size(); ++i) {
            memo[0][i] = s1[0] == s2[i] ? 1 : 0;
        }

        auto max_end = 0;
        auto max_size = 0;
        for (int i = 0; i < s1.size(); ++i) {
            for (int j = 0; j < s2.size(); ++j) {
                if (i == 0 || j == 0)continue;
                if (s1[i] == s2[j]) {
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                    if (memo[i][j] > max_size) {
                        max_end = i;
                        max_size = memo[i][j];
                    }
                } else {
                    memo[i][j] = 0;
                }
            }
        }
        printMatrix(memo);
        cout << s1.substr(max_end - max_size + 1, max_size) << endl;
    }
    return 0;
}