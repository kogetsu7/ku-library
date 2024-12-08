---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/matrix.test.cpp
    title: test/math/matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Matrix (\u884C\u5217)"
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
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
    \ ku\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \nnamespace ku {\n/**\n * @brief Matrix (\u884C\u5217)\n */\ntemplate <class T>\
    \ class Matrix {\n  private:\n    size_t h;\n    size_t w;\n    std::vector<std::vector<T>>\
    \ d;\n\n  public:\n    Matrix() noexcept : Matrix(0) {}\n    explicit Matrix(const\
    \ size_t _h) noexcept : Matrix(_h, _h) {}\n    explicit Matrix(const size_t _h,\
    \ const size_t _w) noexcept\n        : Matrix(std::vector<std::vector<T>>(_h,\
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
    \ ku\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2024-12-08 15:33:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/matrix.test.cpp
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: "Matrix (\u884C\u5217)"
---
