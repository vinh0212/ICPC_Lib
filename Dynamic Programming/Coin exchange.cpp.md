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
  bundledCode: "#line 1 \"Dynamic Programming/Coin exchange.cpp\"\n// Returns number\
    \ of ways we can exchange k using set of coins {{{\ntemplate<typename T>\nT coin_exchange(int\
    \ k, std::vector<int> coins) {\n    std::vector<T> f(k + 1);\n    f[0] = 1;\n\
    \    for (int coin : coins) {\n        for (int i = coin; i <= k; ++i) {\n   \
    \         f[i] += f[i-coin];\n        }\n    }\n    return f.back();\n}\n// }}}\n"
  code: "// Returns number of ways we can exchange k using set of coins {{{\ntemplate<typename\
    \ T>\nT coin_exchange(int k, std::vector<int> coins) {\n    std::vector<T> f(k\
    \ + 1);\n    f[0] = 1;\n    for (int coin : coins) {\n        for (int i = coin;\
    \ i <= k; ++i) {\n            f[i] += f[i-coin];\n        }\n    }\n    return\
    \ f.back();\n}\n// }}}"
  dependsOn: []
  isVerificationFile: false
  path: Dynamic Programming/Coin exchange.cpp
  requiredBy: []
  timestamp: '2024-11-10 11:18:59+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dynamic Programming/Coin exchange.cpp
layout: document
redirect_from:
- /library/Dynamic Programming/Coin exchange.cpp
- /library/Dynamic Programming/Coin exchange.cpp.html
title: Dynamic Programming/Coin exchange.cpp
---
