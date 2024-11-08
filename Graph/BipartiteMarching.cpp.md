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
  bundledCode: "#line 1 \"Graph/BipartiteMarching.cpp\"\n#include <bits/stdc++.h>>\n\
    using namespace std;\n\ntypedef vector<int> vi;\nvector<vi> AL;\nvi match, vis;\
    \ // match: stores pairings; vis: marks visited nodes\n\nbool AugmentPath(int\
    \ L) {\n    if (vis[L]) return false;\n    vis[L] = 1;\n    for (int R : AL[L])\
    \ {\n        if (match[R] == -1 || AugmentPath(match[R])) {\n            match[R]\
    \ = L; // Pair R with L\n            return true; // Return true if an augmenting\
    \ path is found\n        }\n    }\n    return false; \n}\n\nint findMCBM(int Vleft,\
    \ int Vright) {\n    int MCBM = 0;\n    match.assign(Vleft + Vright, -1);\n  \
    \  \n    for (int L = 0; L < Vleft; ++L) { \n        vis.assign(Vleft, 0); //\
    \ Reset visited state for each iteration\n        if (AugmentPath(L)) MCBM++;\
    \ \n    }\n    return MCBM; \n}\n\nint main() {\n    int Vleft, Vright, E;\n \
    \   cin >> Vleft >> Vright >> E; //number of left nodes, right nodes, and edges\n\
    \n    AL.assign(Vleft, vi()); // Initialize adjacency list for left nodes\n  \
    \  for (int i = 0; i < E; ++i) {\n        int u, v;\n        cin >> u >> v; \n\
    \        AL[u].push_back(v);\n    }\n\n    int MCBM = findMCBM(Vleft, Vright);\n\
    \    return 0;\n}\n"
  code: "#include <bits/stdc++.h>>\nusing namespace std;\n\ntypedef vector<int> vi;\n\
    vector<vi> AL;\nvi match, vis; // match: stores pairings; vis: marks visited nodes\n\
    \nbool AugmentPath(int L) {\n    if (vis[L]) return false;\n    vis[L] = 1;\n\
    \    for (int R : AL[L]) {\n        if (match[R] == -1 || AugmentPath(match[R]))\
    \ {\n            match[R] = L; // Pair R with L\n            return true; // Return\
    \ true if an augmenting path is found\n        }\n    }\n    return false; \n\
    }\n\nint findMCBM(int Vleft, int Vright) {\n    int MCBM = 0;\n    match.assign(Vleft\
    \ + Vright, -1);\n    \n    for (int L = 0; L < Vleft; ++L) { \n        vis.assign(Vleft,\
    \ 0); // Reset visited state for each iteration\n        if (AugmentPath(L)) MCBM++;\
    \ \n    }\n    return MCBM; \n}\n\nint main() {\n    int Vleft, Vright, E;\n \
    \   cin >> Vleft >> Vright >> E; //number of left nodes, right nodes, and edges\n\
    \n    AL.assign(Vleft, vi()); // Initialize adjacency list for left nodes\n  \
    \  for (int i = 0; i < E; ++i) {\n        int u, v;\n        cin >> u >> v; \n\
    \        AL[u].push_back(v);\n    }\n\n    int MCBM = findMCBM(Vleft, Vright);\n\
    \    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BipartiteMarching.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:09:26+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BipartiteMarching.cpp
layout: document
redirect_from:
- /library/Graph/BipartiteMarching.cpp
- /library/Graph/BipartiteMarching.cpp.html
title: Graph/BipartiteMarching.cpp
---
