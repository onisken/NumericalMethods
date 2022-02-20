//
// Created by anisk on 21.02.2022.
//

#include <iostream>
#include <cmath>

float func(float x) {
    return x*x*x - 3*x*x + 6*x + 3;
}

float funcFirst(float x) {
    return 3*x*x - 6*x + 6;
}

int main() {
    float accuracy, M, x;

    accuracy = 0.000001;

    M = 6;

    x = 0;
    std::cout.precision(2);
    std::cout << "Xn = " << x << " \t\tf(Xn) = " << func(x) << " \t\tm = " << funcFirst(x) << " \t\t|f(Xi)|/m = " << (std::abs(func(x)) / M) << std::endl;
    while ((std::abs(func(x)) / M) > accuracy) {
        x = x - func(x) / funcFirst(x);
        std::cout << "Xn = " << x << " \tf(Xn) = " << func(x) << " \t\tm = " << funcFirst(x) << " \t\t|f(Xi)|/m = " << (std::abs(func(x)) / M) << std::endl;
    }

    std::cout << "Root value " << x << std::endl;
    std::cout << "Function value " << func(x) << std::endl;
    return 0;
}