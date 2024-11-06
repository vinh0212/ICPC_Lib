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
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Data Structrue/RMQ.cpp\"\n// RMQ {{{\n//\n// Sparse table\n\
    // Usage:\n// RMQ<int, _min> st(v);\n//\n// Note:\n// - doesn't work for empty\
    \ range\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/staticrmq\ntemplate<class\
    \ T, T (*op) (T, T)> struct RMQ {\n    RMQ() = default;\n    RMQ(const vector<T>&\
    \ v) : t{v}, n{(int) v.size()} {\n        for (int k = 1; (1<<k) <= n; ++k) {\n\
    \            t.emplace_back(n - (1<<k) + 1);\n            for (int i = 0; i +\
    \ (1<<k) <= n; ++i) {\n                t[k][i] = op(t[k-1][i], t[k-1][i + (1<<(k-1))]);\n\
    \            }\n        }\n    }\n\n    // get range [l, r-1]\n    // doesn't\
    \ work for empty range\n    T get(int l, int r) const {\n        assert(0 <= l\
    \ && l < r && r <= n);\n        int k = __lg(r - l);\n        return op(t[k][l],\
    \ t[k][r - (1<<k)]);\n    }\n\nprivate:\n    vector<vector<T>> t;\n    int n;\n\
    };\ntemplate<class T> T _min(T a, T b) { return b < a ? b : a; }\ntemplate<class\
    \ T> T _max(T a, T b) { return a < b ? b : a; }\n// }}}\n"
  code: "// RMQ {{{\n//\n// Sparse table\n// Usage:\n// RMQ<int, _min> st(v);\n//\n\
    // Note:\n// - doesn't work for empty range\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/staticrmq\n\
    template<class T, T (*op) (T, T)> struct RMQ {\n    RMQ() = default;\n    RMQ(const\
    \ vector<T>& v) : t{v}, n{(int) v.size()} {\n        for (int k = 1; (1<<k) <=\
    \ n; ++k) {\n            t.emplace_back(n - (1<<k) + 1);\n            for (int\
    \ i = 0; i + (1<<k) <= n; ++i) {\n                t[k][i] = op(t[k-1][i], t[k-1][i\
    \ + (1<<(k-1))]);\n            }\n        }\n    }\n\n    // get range [l, r-1]\n\
    \    // doesn't work for empty range\n    T get(int l, int r) const {\n      \
    \  assert(0 <= l && l < r && r <= n);\n        int k = __lg(r - l);\n        return\
    \ op(t[k][l], t[k][r - (1<<k)]);\n    }\n\nprivate:\n    vector<vector<T>> t;\n\
    \    int n;\n};\ntemplate<class T> T _min(T a, T b) { return b < a ? b : a; }\n\
    template<class T> T _max(T a, T b) { return a < b ? b : a; }\n// }}}"
  dependsOn: []
  isVerificationFile: false
  path: Data Structrue/RMQ.cpp
  requiredBy: []
  timestamp: '2024-11-07 00:17:58+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structrue/RMQ.cpp
layout: document
redirect_from:
- /library/Data Structrue/RMQ.cpp
- /library/Data Structrue/RMQ.cpp.html
title: Data Structrue/RMQ.cpp
---
