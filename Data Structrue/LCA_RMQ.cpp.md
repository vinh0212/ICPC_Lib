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
  bundledCode: "#line 1 \"Data Structrue/LCA_RMQ.cpp\"\n// L[i] = level\n// L[root]\
    \ = -1\n// LCA[0][root] = -1\nconst int MN = 100111;\nint V, LCA[22][MN], L[MN];\n\
    long long Rmax[22][MN];\n#define LL long long\nvoid initLCA () {\n    FOR (lg,\
    \ 1, 19) {\n        REP (i, V) {\n            if (LCA[lg - 1][i] == -1) continue;\n\
    \            LCA[lg][i] = LCA[lg - 1][LCA[lg - 1][i]];\n            Rmax[lg][i]\
    \ = max (Rmax[lg - 1][LCA[lg - 1][i]], Rmax[lg - 1][i]);\n        }\n    }\n}\n\
    \nLL query (LL a, LL b) {\n    LL ret = 0;\n    if (L[a] < L[b]) swap (a, b);\n\
    \n    FORD(lg,19,0) {\n        if (LCA[lg][a] != -1 && L[LCA[lg][a]] >= L[b])\
    \ {\n            ret = max (ret, Rmax[lg][a]);\n            a = LCA[lg][a];\n\
    \        }\n    }\n    if (a == b) return ret; // if LCA, return a\n    FORD(lg,19,0)\
    \ {\n        if (LCA[lg][a] != LCA[lg][b]) {\n            ret = max (ret, Rmax[lg][a]);\n\
    \            ret = max (ret, Rmax[lg][b]);\n            a = LCA[lg][a];\n    \
    \        b = LCA[lg][b];\n        }\n    }\n    ret = max (ret, Rmax[0][a]);\n\
    \    ret = max (ret, Rmax[0][b]);\n    return ret; // if LCA, return LCA[0][a]\n\
    }\n"
  code: "// L[i] = level\n// L[root] = -1\n// LCA[0][root] = -1\nconst int MN = 100111;\n\
    int V, LCA[22][MN], L[MN];\nlong long Rmax[22][MN];\n#define LL long long\nvoid\
    \ initLCA () {\n    FOR (lg, 1, 19) {\n        REP (i, V) {\n            if (LCA[lg\
    \ - 1][i] == -1) continue;\n            LCA[lg][i] = LCA[lg - 1][LCA[lg - 1][i]];\n\
    \            Rmax[lg][i] = max (Rmax[lg - 1][LCA[lg - 1][i]], Rmax[lg - 1][i]);\n\
    \        }\n    }\n}\n\nLL query (LL a, LL b) {\n    LL ret = 0;\n    if (L[a]\
    \ < L[b]) swap (a, b);\n\n    FORD(lg,19,0) {\n        if (LCA[lg][a] != -1 &&\
    \ L[LCA[lg][a]] >= L[b]) {\n            ret = max (ret, Rmax[lg][a]);\n      \
    \      a = LCA[lg][a];\n        }\n    }\n    if (a == b) return ret; // if LCA,\
    \ return a\n    FORD(lg,19,0) {\n        if (LCA[lg][a] != LCA[lg][b]) {\n   \
    \         ret = max (ret, Rmax[lg][a]);\n            ret = max (ret, Rmax[lg][b]);\n\
    \            a = LCA[lg][a];\n            b = LCA[lg][b];\n        }\n    }\n\
    \    ret = max (ret, Rmax[0][a]);\n    ret = max (ret, Rmax[0][b]);\n    return\
    \ ret; // if LCA, return LCA[0][a]\n}"
  dependsOn: []
  isVerificationFile: false
  path: Data Structrue/LCA_RMQ.cpp
  requiredBy: []
  timestamp: '2024-11-10 11:32:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structrue/LCA_RMQ.cpp
layout: document
redirect_from:
- /library/Data Structrue/LCA_RMQ.cpp
- /library/Data Structrue/LCA_RMQ.cpp.html
title: Data Structrue/LCA_RMQ.cpp
---
