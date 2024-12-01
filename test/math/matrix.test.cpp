#define PROBLEM "https://yukicoder.me/problems/no/2441"

#include <iostream>

#include "../../math/matrix.hpp"

int main() {
    std::vector M(2, std::vector<int>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cin >> M[i][j];
        }
    }

    Ku::Matrix<int> mat1(M), mat2(2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mat2.set(i, j, M[i][j]);
        }
    }

    assert(mat1 == mat2);

    mat1 = mat1.pow(3);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (0 < j) {
                std::cout << " ";
            }

            std::cout << mat1.get(i, j);
        }
        std::cout << "\n";
    }

    return 0;
}
