//
// Created by morph on 2021/8/11.
//

// 辗转相除法
int gcd(const int x, const int y) {
    if (x == 0 || y == 0) return -1;
    if (x == y) return x;
    auto remainder = 1;
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

// 相减法
int gcd1(int x, int y) {
    if (x == 0 || y == 0) return -1;
    if (x == y) return x;
    while (x % 2 == 0) {
        x /= 2;
    }
    while (y % 2 == 0) {
        y /= 2;
    }
    auto tmp = 0;
    while (1) {
        if (x > y) {
            tmp = x - y;
            if (tmp == y) break;
            x = tmp;
        } else {
            tmp = y - x;
            if (tmp == x) break;
            y = tmp;
        }
    }

    return tmp;
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}