//
// Created by anisk on 06.03.2022.
//

#include <iostream>
#include <cmath>

float func(float x) {
    return std::sqrt(x + 1) - (1 / x);
}

int main() {
    float accuracy = 0.001;

    float a = 1; // x in [a, b]
    float b = func(a);

    while ((std::abs(b - a)) > accuracy && b >= 1) {
        a = b;
        b = func(a);
    }

    std::cout << "x = " << b << std::endl;
    std::cout << "f(x) = " << func(b) - b << std::endl;
    return 0;
}