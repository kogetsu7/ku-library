---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: "Matrix (\u884C\u5217)"
  - icon: ':heavy_check_mark:'
    path: math/static_mod_int.hpp
    title: Static Mod Int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_matrix
    links:
    - https://judge.yosupo.jp/problem/pow_of_matrix
  bundledCode: "#line 1 \"test/math/matrix.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_matrix\"\
    \n\n#line 2 \"math/matrix.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\nnamespace ku {\n/**\n * @brief Matrix (\u884C\u5217)\n */\n\
    template <class T> class Matrix {\n  private:\n    size_t h;\n    size_t w;\n\
    \    std::vector<std::vector<T>> d;\n\n  public:\n    Matrix() noexcept : Matrix(0)\
    \ {}\n    explicit Matrix(const size_t _h) noexcept : Matrix(_h, _h) {}\n    explicit\
    \ Matrix(const size_t _h, const size_t _w) noexcept\n        : Matrix(std::vector<std::vector<T>>(_h,\
    \ std::vector<T>(_w))) {}\n    explicit Matrix(const std::vector<std::vector<T>>&\
    \ _d) noexcept\n        : h(_d.size()), w(_d.empty() ? 0 : _d[0].size()), d(_d)\
    \ {\n        assert(std::all_of(\n            d.begin(), d.end(),\n          \
    \  [&](const std::vector<T>& r) -> bool { return r.size() == w; }));\n    }\n\n\
    \    //! \u5358\u4F4D\u884C\u5217\n    static Matrix identity(const size_t s)\
    \ noexcept {\n        Matrix res(s);\n\n        for (size_t i = 0; i < s; i++)\
    \ {\n            res.set(i, i, T(1));\n        }\n\n        return res;\n    }\n\
    \n    size_t height() const noexcept { return h; }\n    size_t width() const noexcept\
    \ { return w; }\n\n    T get(const size_t i, const size_t j) const noexcept {\n\
    \        assert(i < h);\n        assert(j < w);\n\n        return d[i][j];\n \
    \   }\n\n    T set(const size_t i, const size_t j, const T& v) noexcept {\n  \
    \      assert(i < h);\n        assert(j < w);\n\n        return d[i][j] = v;\n\
    \    }\n\n    friend bool operator==(const Matrix& lhs, const Matrix& rhs) noexcept\
    \ {\n        return lhs.d == rhs.d;\n    }\n\n    friend bool operator!=(const\
    \ Matrix& lhs, const Matrix& rhs) noexcept {\n        return lhs.d != rhs.d;\n\
    \    }\n\n    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) noexcept\
    \ {\n        assert(lhs.width() == rhs.height());\n\n        Matrix res(lhs.height(),\
    \ rhs.width());\n        for (size_t i = 0; i < lhs.height(); i++) {\n       \
    \     for (size_t j = 0; j < rhs.width(); j++) {\n                for (size_t\
    \ k = 0; k < lhs.width(); k++) {\n                    res.set(i, j,\n        \
    \                    res.get(i, j) + lhs.get(i, k) * rhs.get(k, j));\n       \
    \         }\n            }\n        }\n\n        return res;\n    }\n\n    Matrix&\
    \ operator*=(const Matrix& rhs) noexcept {\n        assert(height() == width());\n\
    \        assert(rhs.height() == rhs.width());\n\n        return *this = *this\
    \ * rhs;\n    }\n\n    Matrix pow(unsigned long long y) const noexcept {\n   \
    \     assert(height() == width());\n\n        Matrix res = identity(height());\n\
    \        Matrix x = *this;\n\n        while (0 < y) {\n            if (y & 1U)\
    \ {\n                res *= x;\n            }\n\n            x *= x;\n       \
    \     y >>= 1U;\n        }\n\n        return res;\n    }\n};\n};  // namespace\
    \ ku\n#line 2 \"math/static_mod_int.hpp\"\n\nnamespace ku {\n/**\n * @brief Static\
    \ Mod Int\n */\ntemplate <unsigned M> class StaticModInt {\n    static_assert(0\
    \ < M, \"M must be positive.\");\n\n  private:\n    unsigned v;\n\n  public:\n\
    \    constexpr StaticModInt() noexcept : v(0) {}\n    explicit constexpr StaticModInt(const\
    \ unsigned long long _v) noexcept\n        : v(static_cast<unsigned>(_v % M))\
    \ {}\n\n    static constexpr StaticModInt raw(const unsigned _v) noexcept {\n\
    \        StaticModInt res;\n        res.v = _v;\n\n        return res;\n    }\n\
    \n    static constexpr unsigned mod() noexcept { return M; }\n\n    constexpr\
    \ unsigned val() const noexcept { return v; }\n\n    friend constexpr bool operator==(const\
    \ StaticModInt& lhs,\n                                     const StaticModInt&\
    \ rhs) noexcept {\n        return lhs.v == rhs.v;\n    }\n\n    friend constexpr\
    \ bool operator!=(const StaticModInt& lhs,\n                                 \
    \    const StaticModInt& rhs) noexcept {\n        return lhs.v != rhs.v;\n   \
    \ }\n\n    constexpr StaticModInt& operator+=(const StaticModInt& rhs) noexcept\
    \ {\n        v += rhs.val();\n        if (M <= v) {\n            v -= M;\n   \
    \     }\n\n        return *this;\n    }\n\n    constexpr StaticModInt& operator-=(const\
    \ StaticModInt& rhs) noexcept {\n        if (v < rhs.val()) {\n            v +=\
    \ M;\n        }\n        v -= rhs.val();\n\n        return *this;\n    }\n\n \
    \   constexpr StaticModInt& operator*=(const StaticModInt& rhs) noexcept {\n \
    \       v = static_cast<unsigned>(\n            (static_cast<unsigned long long>(v)\
    \ * rhs.val()) % M);\n\n        return *this;\n    }\n\n    constexpr StaticModInt&\
    \ operator/=(const StaticModInt& rhs) noexcept {\n        assert(rhs.val() !=\
    \ 0);\n\n        return *this *= rhs.inv();\n    }\n\n    friend constexpr StaticModInt\
    \ operator+(const StaticModInt& lhs,\n                                       \
    \     const StaticModInt& rhs) noexcept {\n        return StaticModInt(lhs) +=\
    \ rhs;\n    }\n\n    friend constexpr StaticModInt operator-(const StaticModInt&\
    \ lhs,\n                                            const StaticModInt& rhs) noexcept\
    \ {\n        return StaticModInt(lhs) -= rhs;\n    }\n\n    friend constexpr StaticModInt\
    \ operator*(const StaticModInt& lhs,\n                                       \
    \     const StaticModInt& rhs) noexcept {\n        return StaticModInt(lhs) *=\
    \ rhs;\n    }\n\n    friend constexpr StaticModInt operator/(const StaticModInt&\
    \ lhs,\n                                            const StaticModInt& rhs) noexcept\
    \ {\n        return StaticModInt(lhs) /= rhs;\n    }\n\n    constexpr StaticModInt\
    \ pow(unsigned y) const noexcept {\n        StaticModInt res = raw(1);\n     \
    \   StaticModInt x = *this;\n\n        while (0 < y) {\n            if (y & 1U)\
    \ {\n                res *= x;\n            }\n\n            x *= x;\n       \
    \     y >>= 1U;\n        }\n\n        return res;\n    }\n\n    constexpr StaticModInt\
    \ inv() const noexcept { return pow(M - 2); }\n};\n};  // namespace ku\n#line\
    \ 5 \"test/math/matrix.test.cpp\"\n\n#include <iostream>\n#line 8 \"test/math/matrix.test.cpp\"\
    \n\nint main() {\n    int N;\n    long long K;\n    std::cin >> N >> K;\n    std::vector\
    \ A(N, std::vector<ku::StaticModInt<998244353>>(N));\n    ku::Matrix<ku::StaticModInt<998244353>>\
    \ mat(N);\n    for (int i = 0; i < N; i++) {\n        for (int j = 0; j < N; j++)\
    \ {\n            unsigned a;\n            std::cin >> a;\n            A[i][j]\
    \ = ku::StaticModInt<998244353>(a);\n            mat.set(i, j, A[i][j]);\n   \
    \     }\n    }\n\n    ku::Matrix<ku::StaticModInt<998244353>> mat2(A);\n    assert(mat\
    \ == mat2);\n    assert(!(mat != mat2));\n\n    mat = mat.pow(K);\n\n    for (int\
    \ i = 0; i < N; i++) {\n        for (int j = 0; j < N; j++) {\n            if\
    \ (0 < j) {\n                std::cout << \" \";\n            }\n\n          \
    \  std::cout << mat.get(i, j).val();\n        }\n        std::cout << \"\\n\"\
    ;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_matrix\"\n\n#include\
    \ \"../../math/matrix.hpp\"\n#include \"../../math/static_mod_int.hpp\"\n\n#include\
    \ <iostream>\n#include <vector>\n\nint main() {\n    int N;\n    long long K;\n\
    \    std::cin >> N >> K;\n    std::vector A(N, std::vector<ku::StaticModInt<998244353>>(N));\n\
    \    ku::Matrix<ku::StaticModInt<998244353>> mat(N);\n    for (int i = 0; i <\
    \ N; i++) {\n        for (int j = 0; j < N; j++) {\n            unsigned a;\n\
    \            std::cin >> a;\n            A[i][j] = ku::StaticModInt<998244353>(a);\n\
    \            mat.set(i, j, A[i][j]);\n        }\n    }\n\n    ku::Matrix<ku::StaticModInt<998244353>>\
    \ mat2(A);\n    assert(mat == mat2);\n    assert(!(mat != mat2));\n\n    mat =\
    \ mat.pow(K);\n\n    for (int i = 0; i < N; i++) {\n        for (int j = 0; j\
    \ < N; j++) {\n            if (0 < j) {\n                std::cout << \" \";\n\
    \            }\n\n            std::cout << mat.get(i, j).val();\n        }\n \
    \       std::cout << \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - math/matrix.hpp
  - math/static_mod_int.hpp
  isVerificationFile: true
  path: test/math/matrix.test.cpp
  requiredBy: []
  timestamp: '2024-12-08 15:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/matrix.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix.test.cpp
- /verify/test/math/matrix.test.cpp.html
title: test/math/matrix.test.cpp
---
