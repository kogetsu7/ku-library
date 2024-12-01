---
title: Binomial (二項係数)
documentation_of: ../../math/binomial.hpp
---

## 概要
二項係数を前計算する

## コンストラクタ
```cpp
Binomial<T>(unsigned n)
```
- サイズnのテーブルを作成する

### 計算量
逆元の計算を$O(\log{M})$，その他の演算を$O(1)$として<br>
- $O(n+\log{M})$

## p
```cpp
T p(int a, int b)
```
順列の総数${}_a P_b$を返す
### 計算量
- $O(1)$

## c
```cpp
T c(int a, int b)
```
組み合わせの総数${}_a C_b$を返す
### 計算量
- $O(1)$

## h
```cpp
T h(int a, int b)
```
重複組み合わせの総数${}_a H_b$を返す
### 計算量
- $O(1)$
