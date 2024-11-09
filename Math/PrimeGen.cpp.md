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
  bundledCode: "#line 1 \"Math/PrimeGen.cpp\"\n// CPP program to print prime numbers\
    \ from 1 to N\n// using Sieve of Eratosthenes\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n \nvoid sieve_of_eratosthenes(int n)\n{\n    bool is_prime[n\
    \ + 1];\n    memset(is_prime, true, sizeof(is_prime));\n    is_prime[0] = is_prime[1]\
    \ = false;\n    for (int p = 2; p * p <= n; p++) {\n        if (is_prime[p]) {\n\
    \            for (int i = p * p; i <= n; i += p) {\n                is_prime[i]\
    \ = false;\n            }\n        }\n    }\n    for (int i = 2; i <= n; i++)\
    \ {\n        if (is_prime[i]) {\n            cout << i << \" \";\n        }\n\
    \    }\n}\n \nint main()\n{\n    sieve_of_eratosthenes(100);\n    return 0;\n\
    }\n \n// This code is contributed by Susobhan Akhuli\n"
  code: "// CPP program to print prime numbers from 1 to N\n// using Sieve of Eratosthenes\n\
    #include <bits/stdc++.h>\nusing namespace std;\n \nvoid sieve_of_eratosthenes(int\
    \ n)\n{\n    bool is_prime[n + 1];\n    memset(is_prime, true, sizeof(is_prime));\n\
    \    is_prime[0] = is_prime[1] = false;\n    for (int p = 2; p * p <= n; p++)\
    \ {\n        if (is_prime[p]) {\n            for (int i = p * p; i <= n; i +=\
    \ p) {\n                is_prime[i] = false;\n            }\n        }\n    }\n\
    \    for (int i = 2; i <= n; i++) {\n        if (is_prime[i]) {\n            cout\
    \ << i << \" \";\n        }\n    }\n}\n \nint main()\n{\n    sieve_of_eratosthenes(100);\n\
    \    return 0;\n}\n \n// This code is contributed by Susobhan Akhuli"
  dependsOn: []
  isVerificationFile: false
  path: Math/PrimeGen.cpp
  requiredBy: []
  timestamp: '2024-11-09 09:36:42+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/PrimeGen.cpp
layout: document
redirect_from:
- /library/Math/PrimeGen.cpp
- /library/Math/PrimeGen.cpp.html
title: Math/PrimeGen.cpp
---
