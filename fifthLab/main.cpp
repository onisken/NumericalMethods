//
// Created by anisk on 13.03.2022.
//
#include <iostream>

const int N = 4;

void reverse(float *matrix, float *vectB, int k, int r) {
    float c;
    for (int j = k; j < N; j++) {
        c = matrix[k + j * N];
        matrix[k + j * N] = matrix[r + j * N];
        matrix[r + j * N] = c;
    }
    c = vectB[k];
    vectB[k] = vectB[r];
    vectB[r] = c;
}

void divide(float *matrix, float *vectB, int k) {
    for (int j = k + 1; j < N; j++) {
        matrix[k + j * N] /= matrix[k + k * N];
    }
    vectB[k] /= matrix[k + k * N];
}

void clear(float *matrix, float *vectB, int k, int r) {
    for (int j = k + 1; j < N; j++) {
        matrix[r + j * N] -= matrix[k + j * N] * matrix[r + k * N];
    }
    vectB[r] -= vectB[k] * matrix[r + k * N];
}

int main() {
    float *matrix;
    float *vectB;
    float vectX[N];
    int i, j, k;

    matrix = new float[N * N] {
            -0.96, -2.00,  1.00,  1.55,
            3.53,  -2.64,  2.75,  -0.99,
            -3.34,  3.95,  2.20, -1.48,
            2.56,3.68,  -3.74,  -0.43
    };



    /*
    matrix = new float[N * N] {
            -0.96, 3.53,  -3.34,  2.56,
            -2.0,  -2.64,  3.95,  3.68,
            1.00,  2.75,  2.20, -3.74,
            1.55,-0.99,  -1.48,  -0.43
    };

    float temp;
    int counter = 1;
    for (int m = 0; m < N * N - N; m++) {
        m += counter;
        for (k = counter; k < N - 1; k++) {
            if (m != k) {
                temp = matrix[m];
                matrix[m] = matrix[m + k * (N - 1)];
                matrix[m + k * (N - 1)] = temp;
            }
        }
        counter++;
    }
    */

    for (int D = 0; D < N; D++) {
        for (int G = 0; G < N; G++) {
            std::cout << " " << matrix[G + D * N] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;

    vectB = new float[N] {
            8.85,1.13,7.39,3.60
    };

    for (k = 0; k < N - 1; k++) {
        if (matrix[k + k * N] == 0) {
            i = k + 1;
            while(matrix[i + k * N] == 0) {
                i++;
            }
            reverse(matrix, vectB, k, i);
        }
        divide(matrix, vectB, k);
        for (i = k + 1; i < N; i++) {
            clear(matrix, vectB, k, i);
        }
    }
    divide(matrix, vectB, N - 1);

    for (int D = 0; D < N; D++) {
        for (int G = 0; G < N; G++) {
            std::cout << " " << matrix[G + D * N] << " ";
        }
        std::cout << std::endl;
    }

    for (i = N - 1; i >= 0; i--) {
        vectX[i] = vectB[i];
        for (j = i + 1; j < N; j++) {
            vectX[i] -= matrix[i + j * N] * vectX[j];
        }
        std::cout << "x(" << i + 1 << ") = " << vectX[i] << std::endl;
    }
    return 0;
}

