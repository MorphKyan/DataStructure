#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Code/MyUtility.cpp"

using namespace std;

string multi(string s1, string s2) {
    vector<int> ans(s1.size() + s2.size(), 0);
    for (int i = s1.size() - 1; i >= 0; --i) {
        for (int j = s2.size() - 1; j >= 0; --j) {
            int tmp = (s1[i] - '0') * (s2[j] - '0') + ans[i + j + 1];
            ans[i + j] += tmp / 10;
            if (ans[i + j] > 10)
                cout << ans[i + j] << endl;
            ans[i + j + 1] = tmp % 10;
        }
    }
    int i = 0;
    while (i < ans.size() && ans[i] == 0) i++;
    string res = "";
    for (; i < ans.size(); ++i) {
        res += ans[i] + '0';
    }
    return res;
}

int main() {
    string s1 = "9999";
    string s2 = "99";
    cout << multi(s1, s2);
    return 0;
}