---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
    - https://judge.yosupo.jp/problem/matrix_det
    - https://judge.yosupo.jp/problem/matrix_product
    - https://judge.yosupo.jp/submission/54653
    - https://oj.vnoi.info/problem/dtl_lsr
    - https://oj.vnoi.info/problem/icpc21_mb_h
    - https://oj.vnoi.info/problem/icpc21_mt_k
    - https://oj.vnoi.info/problem/vmrook
  bundledCode: "#line 1 \"Math/Matrix.cpp\"\n// Matrix, which works for both double\
    \ and int {{{\n// Copied partially from https://judge.yosupo.jp/submission/54653\n\
    //\n// Tested:\n// - (mat mul): https://judge.yosupo.jp/problem/matrix_product\n\
    // - (mat pow): https://oj.vnoi.info/problem/icpc21_mt_k\n// - (mat pow): https://oj.vnoi.info/problem/icpc21_mb_h\n\
    // - (gauss): https://oj.vnoi.info/problem/vmrook\n// - (inverse): https://oj.vnoi.info/problem/dtl_lsr\n\
    // - (inverse): https://judge.yosupo.jp/problem/inverse_matrix\n// - (det): https://judge.yosupo.jp/problem/matrix_det\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n// Define a type alias for\
    \ clarity\ntypedef long long ll;\n\n// Matrix Class\ntemplate<typename T>\nstruct\
    \ Matrix {\n    int n_row, n_col;\n    vector<vector<T>> mat;\n\n    // Constructor:\
    \ Initialize n_row x n_col matrix with all elements as zero\n    Matrix(int _n_row,\
    \ int _n_col) : n_row(_n_row), n_col(_n_col), mat(_n_row, vector<T>(_n_col, 0))\
    \ {}\n\n    // Constructor: Initialize from a 2D vector\n    Matrix(const vector<vector<T>>&\
    \ d) : n_row(d.size()), n_col(d.empty() ? 0 : d[0].size()), mat(d) {}\n\n    //\
    \ Static method to create an identity matrix\n    static Matrix identity(int size)\
    \ {\n        Matrix I(size, size);\n        for(int i = 0; i < size; ++i) {\n\
    \            I.mat[i][i] = 1;\n        }\n        return I;\n    }\n\n    // Matrix\
    \ multiplication\n    Matrix operator* (const Matrix& other) const {\n       \
    \ assert(n_col == other.n_row);\n        Matrix result(n_row, other.n_col);\n\
    \        for(int i = 0; i < n_row; ++i) {\n            for(int k = 0; k < n_col;\
    \ ++k) {\n                if (mat[i][k] == 0) continue; // Optimization for sparse\
    \ matrices\n                for(int j = 0; j < other.n_col; ++j) {\n         \
    \           result.mat[i][j] += mat[i][k] * other.mat[k][j];\n               \
    \ }\n            }\n        }\n        return result;\n    }\n\n    // Matrix\
    \ exponentiation\n    Matrix pow(long long power) const {\n        assert(n_row\
    \ == n_col); // Only square matrices can be exponentiated\n        Matrix result\
    \ = Matrix::identity(n_row);\n        Matrix base = *this;\n        long long\
    \ p = power;\n        while(p > 0) {\n            if(p & 1) {\n              \
    \  result = result * base;\n            }\n            base = base * base;\n \
    \           p >>= 1;\n        }\n        return result;\n    }\n\n    // Determinant\
    \ using Gaussian Elimination\n    T determinant() const {\n        assert(n_row\
    \ == n_col);\n        int N = n_row;\n        Matrix<T> mat_copy = *this;\n  \
    \      T det = 1;\n        for(int i = 0; i < N; ++i){\n            // Find pivot\n\
    \            int pivot = i;\n            for(int j = i; j < N; ++j){\n       \
    \         if(abs(mat_copy.mat[j][i]) > abs(mat_copy.mat[pivot][i])){\n       \
    \             pivot = j;\n                }\n            }\n            if(mat_copy.mat[pivot][i]\
    \ == 0){\n                return 0;\n            }\n            if(pivot != i){\n\
    \                swap(mat_copy.mat[i], mat_copy.mat[pivot]);\n               \
    \ det *= -1;\n            }\n            det *= mat_copy.mat[i][i];\n        \
    \    // Eliminate below\n            for(int j = i + 1; j < N; ++j){\n       \
    \         T factor = mat_copy.mat[j][i] / mat_copy.mat[i][i];\n              \
    \  for(int k = i; k < N; ++k){\n                    mat_copy.mat[j][k] -= factor\
    \ * mat_copy.mat[i][k];\n                }\n            }\n        }\n       \
    \ return det;\n    }\n\n    // Inversion using Gaussian Elimination (for floating\
    \ points)\n    // Returns true if inverse exists, false otherwise\n    bool inverse(Matrix&\
    \ inv) const {\n        assert(n_row == n_col);\n        int N = n_row;\n    \
    \    Matrix<T> mat_copy = *this;\n        inv = Matrix<T>::identity(N);\n\n  \
    \      for(int i = 0; i < N; ++i){\n            // Find pivot\n            int\
    \ pivot = i;\n            for(int j = i; j < N; ++j){\n                if(abs(mat_copy.mat[j][i])\
    \ > abs(mat_copy.mat[pivot][i])){\n                    pivot = j;\n          \
    \      }\n            }\n            if(mat_copy.mat[pivot][i] == 0){\n      \
    \          return false; // Singular matrix\n            }\n            if(pivot\
    \ != i){\n                swap(mat_copy.mat[i], mat_copy.mat[pivot]);\n      \
    \          swap(inv.mat[i], inv.mat[pivot]);\n            }\n            // Normalize\
    \ pivot row\n            T factor = mat_copy.mat[i][i];\n            for(int k\
    \ = 0; k < N; ++k){\n                mat_copy.mat[i][k] /= factor;\n         \
    \       inv.mat[i][k] /= factor;\n            }\n            // Eliminate other\
    \ rows\n            for(int j = 0; j < N; ++j){\n                if(j == i) continue;\n\
    \                T factor = mat_copy.mat[j][i];\n                for(int k = 0;\
    \ k < N; ++k){\n                    mat_copy.mat[j][k] -= factor * mat_copy.mat[i][k];\n\
    \                    inv.mat[j][k] -= factor * inv.mat[i][k];\n              \
    \  }\n            }\n        }\n        return true;\n    }\n};\n"
  code: "// Matrix, which works for both double and int {{{\n// Copied partially from\
    \ https://judge.yosupo.jp/submission/54653\n//\n// Tested:\n// - (mat mul): https://judge.yosupo.jp/problem/matrix_product\n\
    // - (mat pow): https://oj.vnoi.info/problem/icpc21_mt_k\n// - (mat pow): https://oj.vnoi.info/problem/icpc21_mb_h\n\
    // - (gauss): https://oj.vnoi.info/problem/vmrook\n// - (inverse): https://oj.vnoi.info/problem/dtl_lsr\n\
    // - (inverse): https://judge.yosupo.jp/problem/inverse_matrix\n// - (det): https://judge.yosupo.jp/problem/matrix_det\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n// Define a type alias for\
    \ clarity\ntypedef long long ll;\n\n// Matrix Class\ntemplate<typename T>\nstruct\
    \ Matrix {\n    int n_row, n_col;\n    vector<vector<T>> mat;\n\n    // Constructor:\
    \ Initialize n_row x n_col matrix with all elements as zero\n    Matrix(int _n_row,\
    \ int _n_col) : n_row(_n_row), n_col(_n_col), mat(_n_row, vector<T>(_n_col, 0))\
    \ {}\n\n    // Constructor: Initialize from a 2D vector\n    Matrix(const vector<vector<T>>&\
    \ d) : n_row(d.size()), n_col(d.empty() ? 0 : d[0].size()), mat(d) {}\n\n    //\
    \ Static method to create an identity matrix\n    static Matrix identity(int size)\
    \ {\n        Matrix I(size, size);\n        for(int i = 0; i < size; ++i) {\n\
    \            I.mat[i][i] = 1;\n        }\n        return I;\n    }\n\n    // Matrix\
    \ multiplication\n    Matrix operator* (const Matrix& other) const {\n       \
    \ assert(n_col == other.n_row);\n        Matrix result(n_row, other.n_col);\n\
    \        for(int i = 0; i < n_row; ++i) {\n            for(int k = 0; k < n_col;\
    \ ++k) {\n                if (mat[i][k] == 0) continue; // Optimization for sparse\
    \ matrices\n                for(int j = 0; j < other.n_col; ++j) {\n         \
    \           result.mat[i][j] += mat[i][k] * other.mat[k][j];\n               \
    \ }\n            }\n        }\n        return result;\n    }\n\n    // Matrix\
    \ exponentiation\n    Matrix pow(long long power) const {\n        assert(n_row\
    \ == n_col); // Only square matrices can be exponentiated\n        Matrix result\
    \ = Matrix::identity(n_row);\n        Matrix base = *this;\n        long long\
    \ p = power;\n        while(p > 0) {\n            if(p & 1) {\n              \
    \  result = result * base;\n            }\n            base = base * base;\n \
    \           p >>= 1;\n        }\n        return result;\n    }\n\n    // Determinant\
    \ using Gaussian Elimination\n    T determinant() const {\n        assert(n_row\
    \ == n_col);\n        int N = n_row;\n        Matrix<T> mat_copy = *this;\n  \
    \      T det = 1;\n        for(int i = 0; i < N; ++i){\n            // Find pivot\n\
    \            int pivot = i;\n            for(int j = i; j < N; ++j){\n       \
    \         if(abs(mat_copy.mat[j][i]) > abs(mat_copy.mat[pivot][i])){\n       \
    \             pivot = j;\n                }\n            }\n            if(mat_copy.mat[pivot][i]\
    \ == 0){\n                return 0;\n            }\n            if(pivot != i){\n\
    \                swap(mat_copy.mat[i], mat_copy.mat[pivot]);\n               \
    \ det *= -1;\n            }\n            det *= mat_copy.mat[i][i];\n        \
    \    // Eliminate below\n            for(int j = i + 1; j < N; ++j){\n       \
    \         T factor = mat_copy.mat[j][i] / mat_copy.mat[i][i];\n              \
    \  for(int k = i; k < N; ++k){\n                    mat_copy.mat[j][k] -= factor\
    \ * mat_copy.mat[i][k];\n                }\n            }\n        }\n       \
    \ return det;\n    }\n\n    // Inversion using Gaussian Elimination (for floating\
    \ points)\n    // Returns true if inverse exists, false otherwise\n    bool inverse(Matrix&\
    \ inv) const {\n        assert(n_row == n_col);\n        int N = n_row;\n    \
    \    Matrix<T> mat_copy = *this;\n        inv = Matrix<T>::identity(N);\n\n  \
    \      for(int i = 0; i < N; ++i){\n            // Find pivot\n            int\
    \ pivot = i;\n            for(int j = i; j < N; ++j){\n                if(abs(mat_copy.mat[j][i])\
    \ > abs(mat_copy.mat[pivot][i])){\n                    pivot = j;\n          \
    \      }\n            }\n            if(mat_copy.mat[pivot][i] == 0){\n      \
    \          return false; // Singular matrix\n            }\n            if(pivot\
    \ != i){\n                swap(mat_copy.mat[i], mat_copy.mat[pivot]);\n      \
    \          swap(inv.mat[i], inv.mat[pivot]);\n            }\n            // Normalize\
    \ pivot row\n            T factor = mat_copy.mat[i][i];\n            for(int k\
    \ = 0; k < N; ++k){\n                mat_copy.mat[i][k] /= factor;\n         \
    \       inv.mat[i][k] /= factor;\n            }\n            // Eliminate other\
    \ rows\n            for(int j = 0; j < N; ++j){\n                if(j == i) continue;\n\
    \                T factor = mat_copy.mat[j][i];\n                for(int k = 0;\
    \ k < N; ++k){\n                    mat_copy.mat[j][k] -= factor * mat_copy.mat[i][k];\n\
    \                    inv.mat[j][k] -= factor * inv.mat[i][k];\n              \
    \  }\n            }\n        }\n        return true;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Matrix.cpp
  requiredBy: []
  timestamp: '2024-11-15 23:57:47+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Matrix.cpp
layout: document
redirect_from:
- /library/Math/Matrix.cpp
- /library/Math/Matrix.cpp.html
title: Math/Matrix.cpp
---
