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
  bundledCode: "#line 1 \"Dynamic Programming/Convex hull.cpp\"\n// Original Recurrence:\n\
    //   dp[i] = min( dp[j] + b[j]*a[i] )  for j < i\n// Condition:\n//   b[j] >=\
    \ b[j+1]\n//   a[i] <= a[i+1]\n// To solve:\n// Hull hull;\n// FOR(i,1,n) {\n\
    //   dp[i] = hull.get(a[i]);\n//   hull.add(b[i], dp[i]);\n// }\n\nconst int MAXN\
    \ = 100100;\n\nstruct Hull {\n    long long a[MAXN], b[MAXN];\n    double x[MAXN];\n\
    \    int head, tail;\n\n    Hull(): head(1), tail(0) {}\n\n    long long get(long\
    \ long xQuery) {\n        if (head > tail) return 0;\n        while (head < tail\
    \ && x[head + 1] <= xQuery) head++;\n        x[head] = xQuery;\n        return\
    \ a[head] * xQuery + b[head];\n    }\n\n    void add(long long aNew, long long\
    \ bNew) {\n        double xNew = -1e18;\n        while (head <= tail) {\n    \
    \        if (aNew == a[tail]) return;\n            xNew = 1.0 * (b[tail] - bNew)\
    \ / (aNew - a[tail]);\n            if (head == tail || xNew >= x[tail]) break;\n\
    \            tail--;\n        }\n        a[++tail] = aNew;\n        b[tail] =\
    \ bNew;\n        x[tail] = xNew;\n    }\n};\n"
  code: "// Original Recurrence:\n//   dp[i] = min( dp[j] + b[j]*a[i] )  for j < i\n\
    // Condition:\n//   b[j] >= b[j+1]\n//   a[i] <= a[i+1]\n// To solve:\n// Hull\
    \ hull;\n// FOR(i,1,n) {\n//   dp[i] = hull.get(a[i]);\n//   hull.add(b[i], dp[i]);\n\
    // }\n\nconst int MAXN = 100100;\n\nstruct Hull {\n    long long a[MAXN], b[MAXN];\n\
    \    double x[MAXN];\n    int head, tail;\n\n    Hull(): head(1), tail(0) {}\n\
    \n    long long get(long long xQuery) {\n        if (head > tail) return 0;\n\
    \        while (head < tail && x[head + 1] <= xQuery) head++;\n        x[head]\
    \ = xQuery;\n        return a[head] * xQuery + b[head];\n    }\n\n    void add(long\
    \ long aNew, long long bNew) {\n        double xNew = -1e18;\n        while (head\
    \ <= tail) {\n            if (aNew == a[tail]) return;\n            xNew = 1.0\
    \ * (b[tail] - bNew) / (aNew - a[tail]);\n            if (head == tail || xNew\
    \ >= x[tail]) break;\n            tail--;\n        }\n        a[++tail] = aNew;\n\
    \        b[tail] = bNew;\n        x[tail] = xNew;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Dynamic Programming/Convex hull.cpp
  requiredBy: []
  timestamp: '2024-11-09 09:36:42+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dynamic Programming/Convex hull.cpp
layout: document
redirect_from:
- /library/Dynamic Programming/Convex hull.cpp
- /library/Dynamic Programming/Convex hull.cpp.html
title: Dynamic Programming/Convex hull.cpp
---
