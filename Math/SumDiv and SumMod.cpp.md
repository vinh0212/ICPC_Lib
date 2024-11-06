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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../SumDiv_SumMod.h:\
    \ line -1: no such header\n"
  code: "// Copied from https://judge.yosupo.jp/submission/15864\n// Tested:\n// -\
    \ https://judge.yosupo.jp/problem/sum_of_floor_of_linear\n\nusing ll = long long;\n\
    ll sum(ll n) {\n    return n * (n-1) / 2;\n}\n// sum( (a + d*i) / m ) for i in\
    \ [0, n-1]\nll sum_div(ll a, ll d, ll m, ll n) {\n    ll res = d / m * sum(n)\
    \ + a / m * n;\n    d %= m, a %= m;\n    if (!d) return res;\n    ll to = (n *\
    \ d + a) / m;\n    return res + (n - 1) * to - sum_div(m - 1 - a, m, d, to);\n\
    }\n// sum( (a + d*i) % m ) for i in [0, n-1]\nll sum_mod(ll a, ll d, ll m, ll\
    \ n) {\n  a = ((a % m) + m) % m, d = ((d % m) + m) % m;\n  return n * a + d *\
    \ sum(n) - m * sum_div(a, d, m, n);\n}\n//Example Code\n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../SumDiv_SumMod.h\"\
    \n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int ntest;\
    \ cin >> ntest;\n    while (ntest--) {\n        ll n, m, a, b; cin >> n >> m >>\
    \ a >> b;\n        cout << sum_div(b, a, m, n) << '\\n';\n    }\n    return 0;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Math/SumDiv and SumMod.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/SumDiv and SumMod.cpp
layout: document
redirect_from:
- /library/Math/SumDiv and SumMod.cpp
- /library/Math/SumDiv and SumMod.cpp.html
title: Math/SumDiv and SumMod.cpp
---
