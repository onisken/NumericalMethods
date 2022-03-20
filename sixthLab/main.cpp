//
// Created by anisk on 20.03.2022.
//

#include <iostream>

const int N = 4;

float teta(float *matrix) {
    float t, s;
    t = 0;
    for (int i = 0; i < N; i++) {
        s = 0;
        for (int j = 0; j < N; j++) {
            s += std::abs(matrix[i + j * N]);
            std::cout << "S = " << s << std::endl;
        }
        s /= std::abs(matrix[i + i * N]);
        if (t < s) {
            t = s;
        }
    }
    return t - 1;
}

float norma(float *vectX, float *vectY) {
    float s, d;
    d = 0;
    for (int  i = 0; i < N; i++) {
        s = std::abs(vectX[i] - vectY[i]);
        if (s > d) {
            d = s;
        }
    }
    return d;
}

void step(float *vectX, float *vectY, float *matrix, float *vectB) {
    for (int i = 0; i < N; i++) {
        vectY[i] = -vectB[i];
        for (int j = 0; j < N; j++) {
            vectY[i] += matrix[i + j * N] * vectX[j];
        }
        vectY[i] = vectX[i] - vectY[i] / matrix[i + i * N];
    }
}

void checking(float *vectX2, float *matrix, float *vectB) {
    float s;
    for (int i = 0; i < N; i++) {
        s = 0;
        for (int j = 0; j < N; j++) {
            s += matrix[i + j * N] * vectX2[j];
        }
        std::cout << s << " " << vectB[i] << std::endl;
    }
}

int main() {
    float *matrix;
    float *vectB;
    float *vectX;
    float *vectX2;
    float accuracy, t;

    accuracy = 0.0001f;

    matrix = new float[N * N] {
            14.72,  -3.16,  -4.62,  1.03,
            1.45,  -12.79,  2.93,  3.85,
            3.88,  3.49,  -15.95, -1.18,
            -4.17,  4.28,  3.26,  -11.95
    };

    vectB = new float[N] {
            -35.70,11.04,10.37,-6.85
    };

    vectX = new float[N];
    vectX2 = new float[N];

    t = teta(matrix);
    std::cout << "Teta= " << t << std::endl;
    for (int  i = 0; i < N; i++) {
        vectX2[i] = 0;
    }

    while(true) {
        for (int i = 0; i < N; i++) {
            vectX[i] = vectX2[i];
        }

        step(vectX, vectX2, matrix, vectB);
        if (norma(vectX, vectX2) <= (accuracy * (1 - t) / t)) break;
    }

    for (int i = 0; i < N; i++) {
        std::cout << "x(" << i + 1 << ")= " << vectX2[i] << std::endl;
    }

    checking(vectX2, matrix, vectB);
    return 0;
}


