#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include "../../math/matrix.hpp"
#include "../../math/static_mod_int.hpp"

#include <iostream>
#include <vector>

int main() {
    int N;
    long long K;
    std::cin >> N >> K;
    std::vector A(N, std::vector<ku::StaticModInt<998244353>>(N));
    ku::Matrix<ku::StaticModInt<998244353>> mat(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            unsigned a;
            std::cin >> a;
            A[i][j] = ku::StaticModInt<998244353>(a);
            mat.set(i, j, A[i][j]);
        }
    }

    ku::Matrix<ku::StaticModInt<998244353>> mat2(A);
    assert(mat == mat2);
    assert(!(mat != mat2));

    mat = mat.pow(K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (0 < j) {
                std::cout << " ";
            }

            std::cout << mat.get(i, j).val();
        }
        std::cout << "\n";
    }

    return 0;
}
