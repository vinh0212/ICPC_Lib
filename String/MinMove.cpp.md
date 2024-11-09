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
    - https://cses.fi/problemset/task/1110/
  bundledCode: "#line 1 \"String/MinMove.cpp\"\n// T\xEDnh v\u1ECB tr\xED c\u1EE7\
    a x\xE2u xoay v\xF2ng c\xF3 th\u1EE9 t\u1EF1 t\u1EEB \u0111i\u1EC3n nh\u1ECF nh\u1EA5\
    t c\u1EE7a x\xE2u s[]\n// Tested:\n// - https://cses.fi/problemset/task/1110/\n\
    int minmove(string s) {\n    int n = s.length();\n    int x, y, i, j, u, v; //\
    \ x is the smallest string before string y\n    for (x = 0, y = 1; y < n; ++ y)\
    \ {\n        i = u = x;\n        j = v = y;\n        while (s[i] == s[j]) {\n\
    \            ++ u; ++ v;\n            if (++ i == n) i = 0;\n            if (++\
    \ j == n) j = 0;\n            if (i == x) break; // All strings are equal\n  \
    \      }\n        if (s[i] <= s[j]) y = v;\n        else {\n            x = y;\n\
    \            if (u > y) y = u;\n        }\n    }\n    return x;\n}\n"
  code: "// T\xEDnh v\u1ECB tr\xED c\u1EE7a x\xE2u xoay v\xF2ng c\xF3 th\u1EE9 t\u1EF1\
    \ t\u1EEB \u0111i\u1EC3n nh\u1ECF nh\u1EA5t c\u1EE7a x\xE2u s[]\n// Tested:\n\
    // - https://cses.fi/problemset/task/1110/\nint minmove(string s) {\n    int n\
    \ = s.length();\n    int x, y, i, j, u, v; // x is the smallest string before\
    \ string y\n    for (x = 0, y = 1; y < n; ++ y) {\n        i = u = x;\n      \
    \  j = v = y;\n        while (s[i] == s[j]) {\n            ++ u; ++ v;\n     \
    \       if (++ i == n) i = 0;\n            if (++ j == n) j = 0;\n           \
    \ if (i == x) break; // All strings are equal\n        }\n        if (s[i] <=\
    \ s[j]) y = v;\n        else {\n            x = y;\n            if (u > y) y =\
    \ u;\n        }\n    }\n    return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/MinMove.cpp
  requiredBy: []
  timestamp: '2024-11-09 21:40:45+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/MinMove.cpp
layout: document
redirect_from:
- /library/String/MinMove.cpp
- /library/String/MinMove.cpp.html
title: String/MinMove.cpp
---
