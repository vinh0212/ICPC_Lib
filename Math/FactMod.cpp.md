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
  bundledCode: "#line 1 \"Math/FactMod.cpp\"\nint factmod (int n, int p) { // n!,\
    \ excluding p^k of course\n    int res = 1;\n    while (n > 1) {\n        res\
    \ = (res * ((n/p) % 2 ? p-1 : 1)) % p;\n        for (int i=2; i<=n%p; ++i)\n \
    \           res = (res * i) % p;\n        n /= p;\n    }\n    return res % p;\n\
    }\n"
  code: "int factmod (int n, int p) { // n!, excluding p^k of course\n    int res\
    \ = 1;\n    while (n > 1) {\n        res = (res * ((n/p) % 2 ? p-1 : 1)) % p;\n\
    \        for (int i=2; i<=n%p; ++i)\n            res = (res * i) % p;\n      \
    \  n /= p;\n    }\n    return res % p;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/FactMod.cpp
  requiredBy: []
  timestamp: '2024-11-08 23:54:49+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/FactMod.cpp
layout: document
redirect_from:
- /library/Math/FactMod.cpp
- /library/Math/FactMod.cpp.html
title: Math/FactMod.cpp
---
