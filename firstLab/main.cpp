#include <iostream>
#include <cmath>

float func(float x) {
    return std::exp(-2 * x) - 2 * x + 1;
}

int main() {
    float first, second; // gap = [first, second]
    std::cout << "First end:";
    std::cin >> first;
    std::cout << "Second end:";
    std::cin >> second;

    float accuracy;
    std::cout << "Accuracy:";
    std::cin >> accuracy;

    float middle;
    while((second - first) > 2 * accuracy) {
        middle = (first + second) / 2;
        if (func(first) * func(middle) > 0) {
            first = middle;
        } else {
            second = middle;
        }
        std::cout << "[" << first <<  ", " << second << "]" << std::endl;
    }
    float result = (first + second) / 2;
    std::cout << "Accuracy = " << accuracy << ", x = " << result << std::endl;
    return 0;
}

/*
First end:0
Second end:1
Accuracy:0.01
[0.5, 1]
[0.5, 0.75]
[0.625, 0.75]
[0.625, 0.6875]
[0.625, 0.65625]
[0.625, 0.640625]
Accuracy = 0.01, x = 0.632812
*/
