//
// Created by anisk on 06.03.2022.
//

#include <iostream>
#include <cmath>
#include <iomanip>

#define e 2.7182818284590452354

float func(float x) {
    return pow(e, x) + 2.45 * x + 0.57;
}

int main() {
    float a = -1; // x in [a, b]
    float b = 0;

    float accuracy = 0.00001f;

    float m = 2.82;
    float x0 = -1;

    if (x0 == b) {
        b = a;
    }
    while (std::abs(func(x0) / m) > accuracy) {
        x0 -= func(x0) / (func(x0) - func(b)) * (x0 - b);
    }

    std::cout << std::fixed << std::setprecision(10) << std::endl;
    std::cout << "x= " << x0 << std::endl;
    std::cout << "f(x)= " << func(x0) << std::endl;

    return 0;
}
