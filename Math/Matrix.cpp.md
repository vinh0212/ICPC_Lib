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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../atcoder/modint.hpp:\
    \ line -1: no such header\n"
  code: "// Matrix, which works for both double and int {{{\n// Copied partially from\
    \ https://judge.yosupo.jp/submission/54653\n//\n// Tested:\n// - (mat mul): https://judge.yosupo.jp/problem/matrix_product\n\
    // - (mat pow): https://oj.vnoi.info/problem/icpc21_mt_k\n// - (mat pow): https://oj.vnoi.info/problem/icpc21_mb_h\n\
    // - (gauss): https://oj.vnoi.info/problem/vmrook\n// - (inverse): https://oj.vnoi.info/problem/dtl_lsr\n\
    // - (inverse): https://judge.yosupo.jp/problem/inverse_matrix\n// - (det): https://judge.yosupo.jp/problem/matrix_det\n\
    \ntemplate<typename T>\nstruct Matrix {\n    int n_row, n_col;\n    vector<T>\
    \ x;\n\n    // accessors\n    typename vector<T>::iterator operator [] (int r)\
    \ {\n        return x.begin() + r * n_col;\n    }\n    inline T get(int i, int\
    \ j) const { return x[i * n_col + j]; }\n    vector<T> at(int r) const {\n   \
    \     return vector<T> { x.begin() + r * n_col, x.begin() + (r+1) * n_col };\n\
    \    }\n\n    // constructors\n    Matrix() = default;\n    Matrix(int _n_row,\
    \ int _n_col) : n_row(_n_row), n_col(_n_col), x(n_row * n_col) {}\n    Matrix(const\
    \ vector<vector<T>>& d) : n_row(d.size()), n_col(d.size() ? d[0].size() : 0) {\n\
    \        for (auto& row : d) std::copy(row.begin(), row.end(), std::back_inserter(x));\n\
    \    }\n\n    // convert to 2d vec\n    vector<vector<T>> vecvec() const {\n \
    \       vector<vector<T>> ret(n_row);\n        for (int i = 0; i < n_row; i++)\
    \ {\n            std::copy(x.begin() + i*n_col,\n                    x.begin()\
    \ + (i+1)*n_col,\n                    std::back_inserter(ret[i]));\n        }\n\
    \        return ret;\n    }\n    operator vector<vector<T>>() const { return vecvec();\
    \ }\n\n    static Matrix identity(int n) {\n        Matrix res(n, n);\n      \
    \  for (int i = 0; i < n; i++) {\n            res[i][i] = 1;\n        }\n    \
    \    return res;\n    }\n\n    Matrix transpose() const {\n        Matrix res(n_col,\
    \ n_row);\n        for (int i = 0; i < n_row; i++) {\n            for (int j =\
    \ 0; j < n_col; j++) {\n                res[j][i] = this->get(i, j);\n       \
    \     }\n        }\n        return res;\n    }\n\n    Matrix& operator *= (const\
    \ Matrix& r) { return *this = *this * r; }\n    Matrix operator * (const Matrix&\
    \ r) const {\n        assert(n_col == r.n_row);\n        Matrix res(n_row, r.n_col);\n\
    \n        for (int i = 0; i < n_row; i++) {\n            for (int k = 0; k < n_col;\
    \ k++) {\n                for (int j = 0; j < r.n_col; j++) {\n              \
    \      res[i][j] += this->get(i, k) * r.get(k, j);\n                }\n      \
    \      }\n        }\n        return res;\n    }\n\n    Matrix pow(long long n)\
    \ const {\n        assert(n_row == n_col);\n        Matrix res = identity(n_row);\n\
    \        if (n == 0) return res;\n\n        bool res_is_id = true;\n        for\
    \ (int i = 63 - __builtin_clzll(n); i >= 0; i--) {\n            if (!res_is_id)\
    \ res *= res;\n            if ((n >> i) & 1) res *= (*this), res_is_id = false;\n\
    \        }\n        return res;\n    }\n\n    // Gauss\n    template <typename\
    \ T2, typename std::enable_if<std::is_floating_point<T2>::value>::type * = nullptr>\n\
    \    static int choose_pivot(const Matrix<T2> &mtr, int h, int c) noexcept {\n\
    \        int piv = -1;\n        for (int j = h; j < mtr.n_row; j++) {\n      \
    \      if (mtr.get(j, c) and (piv < 0 or std::abs(mtr.get(j, c)) > std::abs(mtr.get(piv,\
    \ c)))) piv = j;\n        }\n        return piv;\n    }\n    template <typename\
    \ T2, typename std::enable_if<!std::is_floating_point<T2>::value>::type * = nullptr>\n\
    \    static int choose_pivot(const Matrix<T2> &mtr, int h, int c) noexcept {\n\
    \        for (int j = h; j < mtr.n_row; j++) {\n            if (mtr.get(j, c)\
    \ != T(0)) return j;\n        }\n        return -1;\n    }\n\n    // return upper\
    \ triangle matrix\n    [[nodiscard]] Matrix gauss() const {\n        int c = 0;\n\
    \        Matrix mtr(*this);\n        vector<int> ws;\n        ws.reserve(n_col);\n\
    \n        for (int h = 0; h < n_row; h++) {\n            if (c == n_col) break;\n\
    \            int piv = choose_pivot(mtr, h, c);\n            if (piv == -1) {\n\
    \                c++;\n                h--;\n                continue;\n     \
    \       }\n            if (h != piv) {\n                for (int w = 0; w < n_col;\
    \ w++) {\n                    swap(mtr[piv][w], mtr[h][w]);\n                \
    \    mtr[piv][w] *= -1; // for determinant\n                }\n            }\n\
    \            ws.clear();\n            for (int w = c; w < n_col; w++) {\n    \
    \            if (mtr[h][w] != 0) ws.emplace_back(w);\n            }\n        \
    \    const T hcinv = T(1) / mtr[h][c];\n            for (int hh = 0; hh < n_row;\
    \ hh++) {\n                if (hh != h) {\n                    const T coeff =\
    \ mtr[hh][c] * hcinv;\n                    for (auto w : ws) mtr[hh][w] -= mtr[h][w]\
    \ * coeff;\n                    mtr[hh][c] = 0;\n                }\n         \
    \   }\n            c++;\n        }\n        return mtr;\n    }\n\n    // For upper\
    \ triangle matrix\n    T det() const {\n        T ret = 1;\n        for (int i\
    \ = 0; i < n_row; i++) {\n            ret *= get(i, i);\n        }\n        return\
    \ ret;\n    }\n\n    // return rank of inverse matrix. If rank < n -> not invertible\n\
    \    int inverse() {\n        assert(n_row == n_col);\n        vector<vector<T>>\
    \ ret = identity(n_row), tmp = *this;\n        int rank = 0;\n\n        for (int\
    \ i = 0; i < n_row; i++) {\n            int ti = i;\n            while (ti < n_row\
    \ && tmp[ti][i] == 0) ++ti;\n            if (ti == n_row) continue;\n        \
    \    else ++rank;\n\n            ret[i].swap(ret[ti]);\n            tmp[i].swap(tmp[ti]);\n\
    \n            T inv = T(1) / tmp[i][i];\n            for (int j = 0; j < n_col;\
    \ j++) ret[i][j] *= inv;\n            for (int j = i+1; j < n_col; j++) tmp[i][j]\
    \ *= inv;\n\n            for (int h = 0; h < n_row; h++) {\n                if\
    \ (i == h) continue;\n                const T c = -tmp[h][i];\n              \
    \  for (int j = 0; j < n_col; j++) ret[h][j] += ret[i][j] * c;\n             \
    \   for (int j = i+1; j < n_col; j++) tmp[h][j] += tmp[i][j] * c;\n          \
    \  }\n        }\n\n        *this = ret;\n        return rank;\n    }\n\n    //\
    \ sum of all elements in this matrix\n    T sum_all() {\n        return submatrix_sum(0,\
    \ 0, n_row, n_col);\n    }\n\n    // sum of [r1, r2) x [c1, c2)\n    T submatrix_sum(int\
    \ r1, int c1, int r2, int c2) {\n        T res {0};\n        for (int r = r1;\
    \ r < r2; ++r) {\n            res += std::accumulate(\n                    x.begin()\
    \ + r * n_col + c1,\n                    x.begin() + r * n_col + c2,\n       \
    \             T{0});\n        }\n        return res;\n    }\n};\ntemplate<typename\
    \ T>\nostream& operator << (ostream& cout, const Matrix<T>& m) {\n    cout <<\
    \ m.n_row << ' ' << m.n_col << endl;\n    for (int i = 0; i < m.n_row; ++i) {\n\
    \        cout << \"row [\" << i << \"] = \" << m.at(i) << endl;\n    }\n    return\
    \ cout;\n}\n// }}}\n//Example Code\n#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\
    \n\n#include <bits/stdc++.h>\n#include \"../../atcoder/modint.hpp\"\nusing namespace\
    \ std;\nusing namespace atcoder;\n\n#include \"../Matrix.h\"\n#include \"../../buffered_reader.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n = IO::get<int>();\n \
    \   Matrix<modint998244353> a(n, n);\n    REP(i,n) REP(j,n) {\n        int x =\
    \ IO::get<int>();\n        a[i][j] = x;\n    }\n    int rank = a.inverse();\n\
    \    if (rank < n) cout << -1 << '\\n';\n    else {\n        REP(i,n) {\n    \
    \        REP(j,n) cout << a[i][j].val() << ' ';\n            cout << '\\n';\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Matrix.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Matrix.cpp
layout: document
redirect_from:
- /library/Math/Matrix.cpp
- /library/Math/Matrix.cpp.html
title: Math/Matrix.cpp
---
