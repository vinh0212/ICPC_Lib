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
  bundledCode: "#line 1 \"String/KMP.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n//Time complexity: O(n + m)\nconst int MAX_N = 200010;\n\nchar T[MAX_N],\
    \ P[MAX_N];                         // T = text, P = pattern\nint n, m;      \
    \                                  // n = |T|, m = |P|\nint b[MAX_N]; \n\nvoid\
    \ kmpPreprocess() {                           // call this first\n  int i = 0,\
    \ j = -1; b[0] = -1;                  // starting values\n  while (i < m) {  \
    \                              // pre-process P\n    while ((j >= 0) && (P[i]\
    \ != P[j])) j = b[j]; // different, reset j\n    ++i; ++j;                   \
    \                 // same, advance both\n    b[i] = j;\n  }\n}\n\nint kmpSearch()\
    \ {                               // similar as above\n  int freq = 0;\n  int\
    \ i = 0, j = 0;                              // starting values\n  while (i <\
    \ n) {                                // search through T\n    while ((j >= 0)\
    \ && (T[i] != P[j])) j = b[j]; // if different, reset j\n    ++i; ++j;       \
    \                             // if same, advance both\n    if (j == m) {    \
    \                            // a match is found\n      ++freq;\n      // printf(\"\
    P is found at index %d in T\\n\", i-j);\n      j = b[j];                     \
    \             // prepare j for the next\n    }\n  }\n  return freq;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n//Time complexity: O(n +\
    \ m)\nconst int MAX_N = 200010;\n\nchar T[MAX_N], P[MAX_N];                  \
    \       // T = text, P = pattern\nint n, m;                                  \
    \      // n = |T|, m = |P|\nint b[MAX_N]; \n\nvoid kmpPreprocess() {         \
    \                  // call this first\n  int i = 0, j = -1; b[0] = -1;       \
    \           // starting values\n  while (i < m) {                            \
    \    // pre-process P\n    while ((j >= 0) && (P[i] != P[j])) j = b[j]; // different,\
    \ reset j\n    ++i; ++j;                                    // same, advance both\n\
    \    b[i] = j;\n  }\n}\n\nint kmpSearch() {                               // similar\
    \ as above\n  int freq = 0;\n  int i = 0, j = 0;                             \
    \ // starting values\n  while (i < n) {                                // search\
    \ through T\n    while ((j >= 0) && (T[i] != P[j])) j = b[j]; // if different,\
    \ reset j\n    ++i; ++j;                                    // if same, advance\
    \ both\n    if (j == m) {                                // a match is found\n\
    \      ++freq;\n      // printf(\"P is found at index %d in T\\n\", i-j);\n  \
    \    j = b[j];                                  // prepare j for the next\n  \
    \  }\n  }\n  return freq;\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/KMP.cpp
  requiredBy: []
  timestamp: '2024-11-10 11:18:59+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/KMP.cpp
layout: document
redirect_from:
- /library/String/KMP.cpp
- /library/String/KMP.cpp.html
title: String/KMP.cpp
---
