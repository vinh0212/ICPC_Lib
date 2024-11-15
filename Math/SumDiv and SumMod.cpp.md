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
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    - https://judge.yosupo.jp/submission/15864
  bundledCode: "#line 1 \"Math/SumDiv and SumMod.cpp\"\n// Copied from https://judge.yosupo.jp/submission/15864\n\
    // Tested:\n// - https://judge.yosupo.jp/problem/sum_of_floor_of_linear\n\nusing\
    \ ll = long long;\nll sum(ll n) {\n    return n * (n-1) / 2;\n}\n// sum( (a +\
    \ d*i) / m ) for i in [0, n-1]\nll sum_div(ll a, ll d, ll m, ll n) {\n    ll res\
    \ = d / m * sum(n) + a / m * n;\n    d %= m, a %= m;\n    if (!d) return res;\n\
    \    ll to = (n * d + a) / m;\n    return res + (n - 1) * to - sum_div(m - 1 -\
    \ a, m, d, to);\n}\n// sum( (a + d*i) % m ) for i in [0, n-1]\nll sum_mod(ll a,\
    \ ll d, ll m, ll n) {\n  a = ((a % m) + m) % m, d = ((d % m) + m) % m;\n  return\
    \ n * a + d * sum(n) - m * sum_div(a, d, m, n);\n}\n//Example Code\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n"
  code: "// Copied from https://judge.yosupo.jp/submission/15864\n// Tested:\n// -\
    \ https://judge.yosupo.jp/problem/sum_of_floor_of_linear\n\nusing ll = long long;\n\
    ll sum(ll n) {\n    return n * (n-1) / 2;\n}\n// sum( (a + d*i) / m ) for i in\
    \ [0, n-1]\nll sum_div(ll a, ll d, ll m, ll n) {\n    ll res = d / m * sum(n)\
    \ + a / m * n;\n    d %= m, a %= m;\n    if (!d) return res;\n    ll to = (n *\
    \ d + a) / m;\n    return res + (n - 1) * to - sum_div(m - 1 - a, m, d, to);\n\
    }\n// sum( (a + d*i) % m ) for i in [0, n-1]\nll sum_mod(ll a, ll d, ll m, ll\
    \ n) {\n  a = ((a % m) + m) % m, d = ((d % m) + m) % m;\n  return n * a + d *\
    \ sum(n) - m * sum_div(a, d, m, n);\n}\n//Example Code\n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\""
  dependsOn: []
  isVerificationFile: false
  path: Math/SumDiv and SumMod.cpp
  requiredBy: []
  timestamp: '2024-11-15 23:57:47+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/SumDiv and SumMod.cpp
layout: document
redirect_from:
- /library/Math/SumDiv and SumMod.cpp
- /library/Math/SumDiv and SumMod.cpp.html
title: Math/SumDiv and SumMod.cpp
---
