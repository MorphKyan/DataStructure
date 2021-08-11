//
// Created by morph on 2021/8/11.
//

// 辗转相除法
int gcd(const int x, const int y) {
    if (x == 0 || y == 0) return -1;
    if (x == y) return x;
    auto remainder=1;
    auto left = 0, right = 0;
    if (x > y) {
        left = x;
        right = y;
    } else {
        left = y;
        right = x;
    }
    while (remainder != 0) {
        remainder = left % right;
        left = right;
        right = remainder;
    }
    return left;
}