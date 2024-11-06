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
  bundledCode: "#line 1 \"Graph/Dijkstra.cpp\"\nconst long long INF = 2000000000000000000LL;\n\
    struct Edge{\n    int v;\n    long long w;\n};\nvoid dijkstra(int n, int S, vector<vector<Edge>>\
    \ E, vector<long long> &D, vector<int> &trace) {\n    D.resize(n, INF);\n    trace.resize(n,\
    \ -1);\n    \n    vector<bool> P(n, 0);\n    D[S] = 0;\n    \n    for (int i =\
    \ 0; i < n; i++) {\n        int uBest; // tim \u0111inh u ch\u01B0a dung, co khoang\
    \ cach nho nhat\n        long long Max = INF;\n        for (int u = 0; u < n;\
    \ u++) {\n            if(D[u] < Max && P[u] == false) {\n                uBest\
    \ = u;\n                Max = D[u];\n            }\n        }\n        \n    \
    \    // c\u1EA3i ti\u1EBFn c\xE1c \u0111\u01B0\u1EDDng \u0111i qua u\n       \
    \ int u = uBest;\n        P[u] = true;\n        for(auto x : E[u]) {\n       \
    \     int v = x.v;\n            long long w = x.w;\n            if(D[v] > D[u]\
    \ + w) {\n                D[v] = D[u] + w;\n                trace[v] = u;\n  \
    \          }\n        }\n    }\n}\nvector<int> trace_path(vector<int> &trace,\
    \ int S, int u) {\n    if (u != S && trace[u] == -1) return vector<int>(0); //\
    \ kh\xF4ng c\xF3 \u0111\u01B0\u1EDDng \u0111i\n\n    vector<int> path;\n    while\
    \ (u != -1) { // truy v\u1EBFt ng\u01B0\u1EE3c t\u1EEB u v\u1EC1 S\n        path.push_back(u);\n\
    \        u = trace[u];\n    }\n    reverse(path.begin(), path.end()); // c\u1EA7\
    n reverse v\xEC \u0111\u01B0\u1EDDng \u0111i l\xFAc n\xE0y l\xE0 t\u1EEB u v\u1EC1\
    \ S\n    \n    return path;\n}\n//Example Code\n    int n, m, S;\n    cin >> n\
    \ >> m >> S;\n    \n    vector<vector<Edge>> E(n);\n    for (int i = 0; i < m;\
    \ i++) {\n        int u, v;\n        long long w;\n        cin >> u >> v >> w;\n\
    \        u--,v--;\n        E[u].push_back({v, (long long)(pow(2,w))});\n    }\n\
    \    \n    vector<long long> D;\n    vector<int> trace;\n    dijkstra(n, S, E,\
    \ D, trace); // b\u1EAFt \u0111\u1EA7u t\u1EEB \u0111\u1EC9nh S\n    for(int i=0;i<n;i++)\
    \ cout << D[i] << \" \";\n"
  code: "const long long INF = 2000000000000000000LL;\nstruct Edge{\n    int v;\n\
    \    long long w;\n};\nvoid dijkstra(int n, int S, vector<vector<Edge>> E, vector<long\
    \ long> &D, vector<int> &trace) {\n    D.resize(n, INF);\n    trace.resize(n,\
    \ -1);\n    \n    vector<bool> P(n, 0);\n    D[S] = 0;\n    \n    for (int i =\
    \ 0; i < n; i++) {\n        int uBest; // tim \u0111inh u ch\u01B0a dung, co khoang\
    \ cach nho nhat\n        long long Max = INF;\n        for (int u = 0; u < n;\
    \ u++) {\n            if(D[u] < Max && P[u] == false) {\n                uBest\
    \ = u;\n                Max = D[u];\n            }\n        }\n        \n    \
    \    // c\u1EA3i ti\u1EBFn c\xE1c \u0111\u01B0\u1EDDng \u0111i qua u\n       \
    \ int u = uBest;\n        P[u] = true;\n        for(auto x : E[u]) {\n       \
    \     int v = x.v;\n            long long w = x.w;\n            if(D[v] > D[u]\
    \ + w) {\n                D[v] = D[u] + w;\n                trace[v] = u;\n  \
    \          }\n        }\n    }\n}\nvector<int> trace_path(vector<int> &trace,\
    \ int S, int u) {\n    if (u != S && trace[u] == -1) return vector<int>(0); //\
    \ kh\xF4ng c\xF3 \u0111\u01B0\u1EDDng \u0111i\n\n    vector<int> path;\n    while\
    \ (u != -1) { // truy v\u1EBFt ng\u01B0\u1EE3c t\u1EEB u v\u1EC1 S\n        path.push_back(u);\n\
    \        u = trace[u];\n    }\n    reverse(path.begin(), path.end()); // c\u1EA7\
    n reverse v\xEC \u0111\u01B0\u1EDDng \u0111i l\xFAc n\xE0y l\xE0 t\u1EEB u v\u1EC1\
    \ S\n    \n    return path;\n}\n//Example Code\n    int n, m, S;\n    cin >> n\
    \ >> m >> S;\n    \n    vector<vector<Edge>> E(n);\n    for (int i = 0; i < m;\
    \ i++) {\n        int u, v;\n        long long w;\n        cin >> u >> v >> w;\n\
    \        u--,v--;\n        E[u].push_back({v, (long long)(pow(2,w))});\n    }\n\
    \    \n    vector<long long> D;\n    vector<int> trace;\n    dijkstra(n, S, E,\
    \ D, trace); // b\u1EAFt \u0111\u1EA7u t\u1EEB \u0111\u1EC9nh S\n    for(int i=0;i<n;i++)\
    \ cout << D[i] << \" \";"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2024-11-07 00:17:58+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Dijkstra.cpp
layout: document
redirect_from:
- /library/Graph/Dijkstra.cpp
- /library/Graph/Dijkstra.cpp.html
title: Graph/Dijkstra.cpp
---
