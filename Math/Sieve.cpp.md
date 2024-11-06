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
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Prime/Sieve.h:\
    \ line -1: no such header\n"
  code: "// F is called for each prime\n// Sieve (odd only + segmented) {{{\ntemplate<typename\
    \ F>\nvoid sieve(int MAX, F func) {\n\n    const int S = sqrt(MAX + 0.5);\n  \
    \  vector<char> sieve(S + 1, true);\n    vector<array<int, 2>> cp;\n    for (int\
    \ i = 3; i <= S; i += 2) {\n        if (!sieve[i])\n            continue;\n  \
    \      cp.push_back({i, (i * i - 1) / 2});\n        for (int j = i * i; j <= S;\
    \ j += 2 * i)\n            sieve[j] = false;\n    }\n    func(2);\n    vector<char>\
    \ block(S);\n    int high = (MAX - 1) / 2;\n    for (int low = 0; low <= high;\
    \ low += S) {\n        fill(block.begin(), block.end(), true);\n        for (auto\
    \ &i : cp) {\n            int p = i[0], idx = i[1];\n            for (; idx <\
    \ S; idx += p)\n                block[idx] = false;\n            i[1] = idx -\
    \ S;\n        }\n        if (low == 0)\n            block[0] = false;\n      \
    \  for (int i = 0; i < S && low + i <= high; i++)\n            if (block[i]) {\n\
    \                func((low + i) * 2 + 1);\n            }\n    };\n}\n// }}}\n\
    //Example Code\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../Prime/Sieve.h\"\
    \n\nint n, a, b, cnt = 0, cnt_mod = 0;\nvector<int> ps;\nvoid newPrime(int p)\
    \ {\n    if (p > n) {\n        cout << cnt << ' ' << ps.size() << '\\n';\n   \
    \     for (int x : ps) cout << x << ' ';\n        exit(0);\n    }\n    if (cnt_mod\
    \ == b) ps.push_back(p);\n    ++cnt;\n    ++cnt_mod;\n    if (cnt_mod == a) cnt_mod\
    \ = 0;\n}\n\nint32_t main() {\n    cin >> n >> a >> b;\n    sieve(1'000'000'000,\
    \ newPrime);\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Sieve.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Sieve.cpp
layout: document
redirect_from:
- /library/Math/Sieve.cpp
- /library/Math/Sieve.cpp.html
title: Math/Sieve.cpp
---
