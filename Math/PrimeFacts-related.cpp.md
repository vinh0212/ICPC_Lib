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
  bundledCode: "#line 1 \"Math/PrimeFacts-related.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntypedef long long ll;\n\nvector<ll> p;\n\nint numPF(ll\
    \ N) // Number of prime factors of N\n{\n    int ans = 0;\n    for (int i = 0;\
    \ (i < (int)p.size()) && (p[i] * p[i] <= N); ++i)\n        while (N % p[i] ==\
    \ 0)\n        {\n            N /= p[i];\n            ++ans;\n        }\n    return\
    \ ans + (N != 1);\n} //Bigger N and mod -- rho_pollard -  ans is size of fact(x)\n\
    \nint numDiv(ll N) // Number of divisors of N\n{\n    int ans = 1; // start from\
    \ ans = 1\n    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= N); ++i)\n\
    \    {\n        int power = 0; // count the power\n        while (N % p[i] ==\
    \ 0)\n        {\n            N /= p[i];\n            ++power;\n        }\n   \
    \     ans *= power + 1;   // follow the formula\n    }\n    return (N != 1) ?\
    \ 2 * ans : ans; // last factor = N^1\n}\n\nll sumDiv(ll N) // Sum of divisors\
    \ of N\n{ \n    ll ans = 1;  // Start with 1, as we will multiply each prime's\
    \ sum.\n    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= N); ++i) {\n\
    \        ll multiplier = p[i], total = 1;\n        while (N % p[i] == 0) {\n \
    \           N /= p[i];\n            total += multiplier;\n            multiplier\
    \ *= p[i];\n        }\n        ans *= total;  // Multiply sum for this prime factor\n\
    \    }\n    if (N != 1) ans *= (N + 1);  // Handle last prime factor\n    return\
    \ ans;\n}\n\nll EulerPhi(ll N)  // Euler's Totient Function\n{ \n    ll ans =\
    \ N;\n    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= N); ++i) {\n\
    \        if (N % p[i] == 0) ans -= ans / p[i];\n        while (N % p[i] == 0)\
    \ N /= p[i];\n    }\n    if (N != 1) ans -= ans / N;\n    return ans;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntypedef long long ll;\n\
    \nvector<ll> p;\n\nint numPF(ll N) // Number of prime factors of N\n{\n    int\
    \ ans = 0;\n    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= N); ++i)\n\
    \        while (N % p[i] == 0)\n        {\n            N /= p[i];\n          \
    \  ++ans;\n        }\n    return ans + (N != 1);\n} //Bigger N and mod -- rho_pollard\
    \ -  ans is size of fact(x)\n\nint numDiv(ll N) // Number of divisors of N\n{\n\
    \    int ans = 1; // start from ans = 1\n    for (int i = 0; (i < (int)p.size())\
    \ && (p[i] * p[i] <= N); ++i)\n    {\n        int power = 0; // count the power\n\
    \        while (N % p[i] == 0)\n        {\n            N /= p[i];\n          \
    \  ++power;\n        }\n        ans *= power + 1;   // follow the formula\n  \
    \  }\n    return (N != 1) ? 2 * ans : ans; // last factor = N^1\n}\n\nll sumDiv(ll\
    \ N) // Sum of divisors of N\n{ \n    ll ans = 1;  // Start with 1, as we will\
    \ multiply each prime's sum.\n    for (int i = 0; (i < (int)p.size()) && (p[i]\
    \ * p[i] <= N); ++i) {\n        ll multiplier = p[i], total = 1;\n        while\
    \ (N % p[i] == 0) {\n            N /= p[i];\n            total += multiplier;\n\
    \            multiplier *= p[i];\n        }\n        ans *= total;  // Multiply\
    \ sum for this prime factor\n    }\n    if (N != 1) ans *= (N + 1);  // Handle\
    \ last prime factor\n    return ans;\n}\n\nll EulerPhi(ll N)  // Euler's Totient\
    \ Function\n{ \n    ll ans = N;\n    for (int i = 0; (i < (int)p.size()) && (p[i]\
    \ * p[i] <= N); ++i) {\n        if (N % p[i] == 0) ans -= ans / p[i];\n      \
    \  while (N % p[i] == 0) N /= p[i];\n    }\n    if (N != 1) ans -= ans / N;\n\
    \    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/PrimeFacts-related.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:09:26+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/PrimeFacts-related.cpp
layout: document
redirect_from:
- /library/Math/PrimeFacts-related.cpp
- /library/Math/PrimeFacts-related.cpp.html
title: Math/PrimeFacts-related.cpp
---
