//
// Created by morph on 2021/5/4.
//

#include <iostream> // 先找设定目录
#include <functional>
#include "random" // 先找当前目录

using namespace std;

int main() {
    random_device rd;
    default_random_engine gen = default_random_engine(rd());
    uniform_int_distribution<> distribution(1, 10);
    uniform_real_distribution<> dis(0, 10);

    for (int i = 0; i < 10; ++i) {
        cout << distribution(gen) << " ";
    }
    cout << endl;
    return 0;
}

int main1() {
    random_device rd;
    mt19937 gen = mt19937(rd());
    uniform_real_distribution<double> dis(-1, 1);

    // 合成函数的模板 bind()
    auto rand_fun = bind(dis, gen);

    cout << rand_fun() << " " << rand_fun() << endl;
}