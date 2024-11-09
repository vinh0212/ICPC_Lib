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
    - https://open.kattis.com/problems/knightstrip
  bundledCode: "#line 1 \"Misc/KnightMove.cpp\"\n// Knight\u2019s shortest path (from\
    \ (0, 0))\n// Tested:\n// - https://open.kattis.com/problems/knightstrip\n\n//\
    \  the minimum number of moves required for a knight (0,0) to get to some other\
    \ arbitrary location (x,y)\nint KSP(int x, int y) {\n    if (x < 0) x = -x;\n\
    \    if (y < 0) y = -y;\n    if (x < y) swap(x, y);\n    if (x == 1 && y == 0)\
    \ return 3;\n    if (x == 2 && y == 2) return 4;\n    int d = x - y;\n    if (y\
    \ > d) return 2 * ((y - d + 2) / 3) + d;\n    return d - 2 * ((d - y) / 4);\n\
    } \n"
  code: "// Knight\u2019s shortest path (from (0, 0))\n// Tested:\n// - https://open.kattis.com/problems/knightstrip\n\
    \n//  the minimum number of moves required for a knight (0,0) to get to some other\
    \ arbitrary location (x,y)\nint KSP(int x, int y) {\n    if (x < 0) x = -x;\n\
    \    if (y < 0) y = -y;\n    if (x < y) swap(x, y);\n    if (x == 1 && y == 0)\
    \ return 3;\n    if (x == 2 && y == 2) return 4;\n    int d = x - y;\n    if (y\
    \ > d) return 2 * ((y - d + 2) / 3) + d;\n    return d - 2 * ((d - y) / 4);\n\
    } "
  dependsOn: []
  isVerificationFile: false
  path: Misc/KnightMove.cpp
  requiredBy: []
  timestamp: '2024-11-09 21:40:45+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/KnightMove.cpp
layout: document
redirect_from:
- /library/Misc/KnightMove.cpp
- /library/Misc/KnightMove.cpp.html
title: Misc/KnightMove.cpp
---
