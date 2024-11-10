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
  bundledCode: "#line 1 \"Math/EulerPhi.cpp\"\nint _gcd(int a, int b)\n{\n    if (b\
    \ == 0)\n        return a;\n    else\n        return _gcd(b, a % b);\n}\nvector<int>\
    \ phi_1_to_n(int n) {\n    vector<int> phi(n + 1);\n    for (int i = 0; i <= n;\
    \ i++)\n        phi[i] = i;\n\n    for (int i = 2; i <= n; i++) {\n        if\
    \ (phi[i] == i) {\n            for (int j = i; j <= n; j += i)\n             \
    \   phi[j] -= phi[j] / i;\n        }\n    }\n    return phi;\n}\n"
  code: "int _gcd(int a, int b)\n{\n    if (b == 0)\n        return a;\n    else\n\
    \        return _gcd(b, a % b);\n}\nvector<int> phi_1_to_n(int n) {\n    vector<int>\
    \ phi(n + 1);\n    for (int i = 0; i <= n; i++)\n        phi[i] = i;\n\n    for\
    \ (int i = 2; i <= n; i++) {\n        if (phi[i] == i) {\n            for (int\
    \ j = i; j <= n; j += i)\n                phi[j] -= phi[j] / i;\n        }\n \
    \   }\n    return phi;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/EulerPhi.cpp
  requiredBy: []
  timestamp: '2024-11-10 11:18:59+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/EulerPhi.cpp
layout: document
redirect_from:
- /library/Math/EulerPhi.cpp
- /library/Math/EulerPhi.cpp.html
title: Math/EulerPhi.cpp
---
