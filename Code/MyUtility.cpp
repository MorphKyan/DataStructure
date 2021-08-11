//
// Created by morph on 2021/5/24.
//
#include <iostream>
#include <vector>

using namespace std;


// 打印矩阵
template<typename T>
void printMatrix(vector<vector<T>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << to_string(matrix[i][j]) << " ";
        }
        std::cout << "\n";
    }
}