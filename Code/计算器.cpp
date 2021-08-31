//
// Created by morph on 2021/8/23.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calculator(string s, int &idx) {
    stack<int> stk;
    auto tmp = 0;
    auto sign = '+';
    for (; idx < s.size(); ++idx) {
        char c = s[idx];
        if (isdigit(c)) {
            tmp = tmp * 10 + c - '0';
        }
        if (c == '(') {
            idx++;
            tmp = calculator(s, idx);
        }

        if ((!isdigit(c) && c != ' ') || idx == s.size() - 1) {
            auto pre = 0;
            switch (sign) {
                case '+':
                    stk.push(tmp);
                    break;
                case '-':
                    stk.push(-tmp);
                    break;
                case '*':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre * tmp);
                    break;
                case '/':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre / tmp);
                    break;
            }
            sign = c;
            tmp = 0;
        }
        if (c == ')') {
            break;
        }
    }
    auto ans = 0;
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}

int main() {
    string s = "1+((2+3)*2)/2+1";
    int idx = 0;
    auto ans = calculator(s, idx);
    cout << ans;
    return 0;
