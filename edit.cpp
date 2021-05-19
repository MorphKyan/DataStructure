//
// Created by morph on 2021/4/26.
//

#include "string"
#include "vector"
#include "unordered_map"
#include "random"

using namespace std;

float DTW(vector<float> &A,vector<float> &B){
    int m=A.size();
    int n=B.size();
    vector<vector<float>> dp(m,vector<float>(n,0));

    // base case
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i][j]= abs(A[i]-B[j]);
        }
    }

    // DP
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            if(j==0){
                dp[i][j]+=dp[i-1][j];
            } else {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }

    return dp[m-1][n-1];
}