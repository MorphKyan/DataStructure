//
// Created by morph on 2021/4/26.
//

#include "string"
#include "vector"

using namespace std;


// 自底向上
int minDistance(string s1, string s2) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
}