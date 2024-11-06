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
  bundledCode: "#line 1 \"Graph/BFS.cpp\"\n//C\u1EA5u tr\xFAc d\u1EEF li\u1EC7u:\n\
    \n/*Bi\u1EBFn maxN - K\xEDch th\u01B0\u1EDBc m\u1EA3ng.\nM\u1EA3ng d[] - M\u1EA3\
    ng l\u01B0u l\u1EA1i kho\u1EA3ng c\xE1ch t\u1EEB \u0111\u1EC9nh ngu\u1ED3n \u0111\
    \u1EBFn m\u1ECDi \u0111\u1EC9nh.\nM\u1EA3ng par[] - M\u1EA3ng l\u01B0u l\u1EA1\
    i v\u1EBFt \u0111\u01B0\u1EDDng \u0111i.\nM\u1EA3ng visit[] - M\u1EA3ng \u0111\
    \xE1nh d\u1EA5u c\xE1c \u0111\u1EC9nh \u0111\xE3 th\u0103m.\nVector g[] - Danh\
    \ s\xE1ch c\u1EA1nh k\u1EC1 c\u1EE7a m\u1ED7i \u0111\u1EC9nh.\nH\xE0ng \u0111\u1EE3\
    i q - Ch\u1EE9a c\xE1c \u0111\u1EC9nh s\u1EBD \u0111\u01B0\u1EE3c duy\u1EC7t theo\
    \ th\u1EE9 t\u1EF1 \u01B0u ti\xEAn chi\u1EC1u r\u1ED9ng.*/\nint n; // S\u1ED1\
    \ l\u01B0\u1EE3ng \u0111\u1EC9nh c\u1EE7a \u0111\u1ED3 th\u1ECB\nint d[maxN],\
    \ par[maxN];\nbool visit[maxN];\nvector <int> g[maxN];\n\nvoid bfs(int s) { //\
    \ V\u1EDBi s l\xE0 \u0111\u1EC9nh xu\u1EA5t ph\xE1t (\u0111\u1EC9nh ngu\u1ED3\
    n)\n    fill_n(d, n + 1, 0);\n    fill_n(par, n + 1, -1);\n    fill_n(visit, n\
    \ + 1, false);\n\n    queue <int> q;\n    q.push(s);\n    visit[s] = true;\n \
    \   while (!q.empty()) {\n        int u = q.front();\n        q.pop();\n     \
    \   for (auto v : g[u]) {\n            if (!visit[v]) {\n                d[v]\
    \     = d[u] + 1;\n                par[v]   = u;\n                visit[v] = true;\n\
    \                q.push(v);\n            }\n        }\n    }\n}\n//Truy v\u1EBF\
    t\n//C\xE0i \u0111\u1EB7t truy v\u1EBFt \u0111\u01B0\u1EDDng \u0111i t\u1EEB \u0111\
    \u1EC9nh ngu\u1ED3n s \u0111\u1EBFn \u0111\u1EC9nh u:\nif (!visit[u]) cout <<\
    \ \"No path!\";\nelse {\n    vector <int> path;\n    for (int v = u; v != -1;\
    \ v = par[v])\n        path.push_back(v);\n    reverse(path.begin(), path.end());\n\
    \    \n    cout << \"Path: \";\n    for (auto v : path) cout << v << ' ';\n}\n"
  code: "//C\u1EA5u tr\xFAc d\u1EEF li\u1EC7u:\n\n/*Bi\u1EBFn maxN - K\xEDch th\u01B0\
    \u1EDBc m\u1EA3ng.\nM\u1EA3ng d[] - M\u1EA3ng l\u01B0u l\u1EA1i kho\u1EA3ng c\xE1\
    ch t\u1EEB \u0111\u1EC9nh ngu\u1ED3n \u0111\u1EBFn m\u1ECDi \u0111\u1EC9nh.\n\
    M\u1EA3ng par[] - M\u1EA3ng l\u01B0u l\u1EA1i v\u1EBFt \u0111\u01B0\u1EDDng \u0111\
    i.\nM\u1EA3ng visit[] - M\u1EA3ng \u0111\xE1nh d\u1EA5u c\xE1c \u0111\u1EC9nh\
    \ \u0111\xE3 th\u0103m.\nVector g[] - Danh s\xE1ch c\u1EA1nh k\u1EC1 c\u1EE7a\
    \ m\u1ED7i \u0111\u1EC9nh.\nH\xE0ng \u0111\u1EE3i q - Ch\u1EE9a c\xE1c \u0111\u1EC9\
    nh s\u1EBD \u0111\u01B0\u1EE3c duy\u1EC7t theo th\u1EE9 t\u1EF1 \u01B0u ti\xEA\
    n chi\u1EC1u r\u1ED9ng.*/\nint n; // S\u1ED1 l\u01B0\u1EE3ng \u0111\u1EC9nh c\u1EE7\
    a \u0111\u1ED3 th\u1ECB\nint d[maxN], par[maxN];\nbool visit[maxN];\nvector <int>\
    \ g[maxN];\n\nvoid bfs(int s) { // V\u1EDBi s l\xE0 \u0111\u1EC9nh xu\u1EA5t ph\xE1\
    t (\u0111\u1EC9nh ngu\u1ED3n)\n    fill_n(d, n + 1, 0);\n    fill_n(par, n + 1,\
    \ -1);\n    fill_n(visit, n + 1, false);\n\n    queue <int> q;\n    q.push(s);\n\
    \    visit[s] = true;\n    while (!q.empty()) {\n        int u = q.front();\n\
    \        q.pop();\n        for (auto v : g[u]) {\n            if (!visit[v]) {\n\
    \                d[v]     = d[u] + 1;\n                par[v]   = u;\n       \
    \         visit[v] = true;\n                q.push(v);\n            }\n      \
    \  }\n    }\n}\n//Truy v\u1EBFt\n//C\xE0i \u0111\u1EB7t truy v\u1EBFt \u0111\u01B0\
    \u1EDDng \u0111i t\u1EEB \u0111\u1EC9nh ngu\u1ED3n s \u0111\u1EBFn \u0111\u1EC9\
    nh u:\nif (!visit[u]) cout << \"No path!\";\nelse {\n    vector <int> path;\n\
    \    for (int v = u; v != -1; v = par[v])\n        path.push_back(v);\n    reverse(path.begin(),\
    \ path.end());\n    \n    cout << \"Path: \";\n    for (auto v : path) cout <<\
    \ v << ' ';\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BFS.cpp
  requiredBy: []
  timestamp: '2024-11-07 00:17:58+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BFS.cpp
layout: document
redirect_from:
- /library/Graph/BFS.cpp
- /library/Graph/BFS.cpp.html
title: Graph/BFS.cpp
---
