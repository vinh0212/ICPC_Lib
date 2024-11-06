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
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
    - https://oj.vnoi.info/problem/icpc21_mt_d
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Polynomial/NTT_chemthan.h:\
    \ line -1: no such header\n"
  code: "// CRT {{{\n// Tested:\n// - https://oj.vnoi.info/problem/icpc21_mt_d\n//\
    \ - (__int128_t) https://judge.yosupo.jp/problem/convolution_mod_1000000007\n\
    template<typename T>\nstruct CRT {\n    T res;\n\n    CRT() {\n        res = 0,\
    \ prd = 1;\n    }\n    \n    // Add condition: res % p == r\n    void add(T p,\
    \ T r) {\n        res += mul(r - res % p + p, euclid(prd, p).first + p, p) * prd;\n\
    \        prd *= p;\n        if (res >= prd) res -= prd;\n    }\n\nprivate:\n \
    \   T prd;\n    T mul(T a, T b, T p) {\n        a %= p, b %= p;\n        T q =\
    \ (T) ((long double) a * b / p);\n        T r = a * b - q * p;\n        while\
    \ (r < 0) r += p;\n        while (r >= p) r -= p;\n        return r;\n    }\n\
    \    pair<T, T> euclid(T a, T b) {\n        if (!b) return make_pair(1, 0);\n\
    \        pair<T, T> r = euclid(b, a % b);\n        return make_pair(r.second,\
    \ r.first - a / b * r.second);\n    }\n};\n// }}}\n//Example Code\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../Polynomial/NTT_chemthan.h\"\n#include \"\
    ../NumberTheory/CRT_chemthan.h\"\n\nconst int MOD0 = 167772161;\nconst int MOD1\
    \ = 469762049;\nconst int MOD2 = 754974721;\nNTT<MOD0, 1 << 20> ntt0;\nNTT<MOD1,\
    \ 1 << 20> ntt1;\nNTT<MOD2, 1 << 20> ntt2;\n\n#define REP(i, a) for (int i = 0,\
    \ _##i = (a); i < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    int n, m; cin >> n >> m;\n    vector<int> a(n); REP(i,n) cin\
    \ >> a[i];\n    vector<int> b(m); REP(i,m) cin >> b[i];\n\n    auto c0 = ntt0.multiply(a,\
    \ b);\n    auto c1 = ntt1.multiply(a, b);\n    auto c2 = ntt2.multiply(a, b);\n\
    \n    const int MOD = 1e9 + 7;\n    REP(i,n+m-1) {\n        CRT<__int128_t> crt;\n\
    \        crt.add(MOD0, c0[i]);\n        crt.add(MOD1, c1[i]);\n        crt.add(MOD2,\
    \ c2[i]);\n        cout << (int) (crt.res % MOD) << ' ';\n    }\n    cout << endl;\n\
    \    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/CRT of chemthan.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/CRT of chemthan.cpp
layout: document
redirect_from:
- /library/Math/CRT of chemthan.cpp
- /library/Math/CRT of chemthan.cpp.html
title: Math/CRT of chemthan.cpp
---
