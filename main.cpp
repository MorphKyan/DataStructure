//
// Created by morph on 2021/8/25.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

int main() {
    unordered_map<pair<int, int>, int, function<size_t(const pair<int, int> &p)>> ids(100, [](const pair<int, int> &p) {
        auto hash1 = hash<int>{}(p.first);
        auto hash2 = hash<int>{}(p.second);
        return hash1 ^ hash2;
    });

    return 0;
}