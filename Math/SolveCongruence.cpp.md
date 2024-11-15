---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/SolveCongruence.cpp\"\n// Gi\u1EA3i ph\u01B0\u01A1\
    ng tr\xECnh: a1x1 + a2x2 + \u2026 + anxn \u2261 b (modul m)\n// Trong \u0111\xF3\
    \ a1, a2, \u2026, an, b, m l\xE0 c\xE1c s\u1ED1 nguy\xEAn d\u01B0\u01A1ng.\n\n\
    int g[MAXN], x[MAXN];\n\nbool congruenceEquation(vector<int> a, int b, int m,\
    \ vector<int> &ret) {\n    int n = sz(a);\n    a.pb(m);\n    g[0] = a[0];\n  \
    \  For(i, 1, n) g[i] = gcd(g[i - 1], a[i]);\n    ret.clear();\n    if (b % g[n])\
    \ return false;\n    int val = b / g[n];\n    Ford(i, n, 1) {\n        pair<ll,\
    \ ll> p = extgcd(g[i - 1], a[i]);\n        x[i] = p.se * val % m;\n        val\
    \ = p.fi * val % m;\n    }\n    x[0] = val;\n    For(i, 0, n) x[i] = (x[i] + m)\
    \ % m;\n    Rep(i, n) ret.pb(x[i]);\n    return true;\n}\n"
  code: "// Gi\u1EA3i ph\u01B0\u01A1ng tr\xECnh: a1x1 + a2x2 + \u2026 + anxn \u2261\
    \ b (modul m)\n// Trong \u0111\xF3 a1, a2, \u2026, an, b, m l\xE0 c\xE1c s\u1ED1\
    \ nguy\xEAn d\u01B0\u01A1ng.\n\nint g[MAXN], x[MAXN];\n\nbool congruenceEquation(vector<int>\
    \ a, int b, int m, vector<int> &ret) {\n    int n = sz(a);\n    a.pb(m);\n   \
    \ g[0] = a[0];\n    For(i, 1, n) g[i] = gcd(g[i - 1], a[i]);\n    ret.clear();\n\
    \    if (b % g[n]) return false;\n    int val = b / g[n];\n    Ford(i, n, 1) {\n\
    \        pair<ll, ll> p = extgcd(g[i - 1], a[i]);\n        x[i] = p.se * val %\
    \ m;\n        val = p.fi * val % m;\n    }\n    x[0] = val;\n    For(i, 0, n)\
    \ x[i] = (x[i] + m) % m;\n    Rep(i, n) ret.pb(x[i]);\n    return true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/SolveCongruence.cpp
  requiredBy: []
  timestamp: '2024-11-15 23:57:47+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/SolveCongruence.cpp
layout: document
redirect_from:
- /library/Math/SolveCongruence.cpp
- /library/Math/SolveCongruence.cpp.html
title: Math/SolveCongruence.cpp
---
