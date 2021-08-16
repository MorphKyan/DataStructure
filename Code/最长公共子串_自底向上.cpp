//
// Created by morph on 2021/8/16.
//
#include <iostream>
#include <vector>
#include <string>
#include "MyUtility.cpp"

using namespace std;

int main() {
    string s1 = "";
    string s2 = "";

    while (getline(cin, s1)) {
        getline(cin, s2);
        if (s1.length() > s2.length())
            swap(s1, s2); // s1用于保存较短的子串
        vector<vector<int>> memo(s1.size(), vector<int>(s2.size(), 0));
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

int main1() {
    string s1 = "";
    string s2 = "";

    while (getline(cin, s1)) {
        getline(cin, s2);
        if (s1.length() > s2.length())
            swap(s1, s2); // s1用于保存较短的子串
        // 不单独列出base case就有偏移
        vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, 0));

        auto max_end = 0;
        auto max_size = 0;
        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                    if (memo[i][j] > max_size) {
                        max_end = i - 1;
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