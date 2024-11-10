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
  bundledCode: "#line 1 \"Graph/BFS-DFS.cpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nenum { UNVISITED = -1, VISITED = -2 };\n#define INF (int)1e9\n#define\
    \ ii pair<int, int>\n#define vi vector<int>\n#define vii vector<ii>\n\nvector<vii>\
    \ AL;\nvi dist, p, dfs_num, num, low, av, visited,ts; //dfs_num only for visited\
    \ or not, num for dfs numbering\nint V, E, dfs_cnt, dfsRoot, rootChildren;\n\n\
    void bfs(int s)\n{\n    dist[s] = 0;\n    queue<int> q; q.push(s);\n    p.assign(V,\
    \ -1);\n\n\n    bool isBi = true;\n\n    while (!q.empty())\n    {\n        int\
    \ u = q.front(); q.pop();\n        for (auto &[v, w] : AL[u])\n        {\n   \
    \         if (dist[v] == INF)\n            {\n                dist[v] = dist[u]\
    \ + 1;\n                p[v] = u;\n                q.push(v);\n            }\n\
    \            else if (dist[v] % 2 == dist[u] % 2) //same parity\n            \
    \    isBi = false;\n        }\n    }\n}\n\nvoid dfs(int u)\n{\n    //cout << u;\n\
    \    dfs_num[u] = VISITED;\n    for (auto &[v, w] : AL[u])\n    {\n        if\
    \ (dfs_num[v] == UNVISITED)\n            dfs(v);\n    }\n    //ts.push_back(u);\
    \ //topological sort\n}\n\n//DFS application\nvoid findAV(int u) //find articulation\
    \ points and bridges\n{\n    num[u] = dfs_cnt++;\n    low[u] = num[u]; \n    for\
    \ (auto &[v, w] : AL[u])\n    {\n        if (num[u] == UNVISITED)\n        {\n\
    \            p[v] = u;\n            if (u == dfsRoot) ++rootChildren;\n      \
    \      findAV(v);\n\n            if (low[v] >= num[u]) av[u] = 1; //av here\n\n\
    \            if (low[v] > num[u]) // --> bridge (u,v)\n            {}\n\n    \
    \        low[u] = min(low[u], low[v]);\n\n        }\n        else if (v != p[u])\n\
    \            low[u] = min(low[u], num[v]);\n    }\n}\nint countCC() //for counting\
    \ connected components\n{\n    int numCC = 0;\n    for (int u = 0; u <= V; u++)\n\
    \    {\n        if (dfs_num[u] == UNVISITED)\n        {\n            numCC++;\n\
    \            dfs(u);\n        }\n    }\n}\n\nstack<int> St;\nint numSCC = 0;\n\
    void tarjanSCC(int u) //for finding strongly connected components\n{\n    low[u]\
    \ = num[u] = dfs_cnt; dfs_cnt++;\n    St.push(u);\n    visited[u] = 1;\n    for\
    \ (auto &[v, w] : AL[u])\n    {\n        if (num[v] == UNVISITED)\n          \
    \  tarjanSCC(v);\n        if (visited[v])\n            low[u] = min(low[u], low[v]);\n\
    \    }\n\n    if(low[u] == num[u]) //u is the root of SCC\n    {\n        numSCC++;\n\
    \        while (1)\n        {\n            int v = St.top(); St.pop(); \n    \
    \        visited[v] = 0;\n            if (u == v) break;\n        }\n    }\n\n\
    \    /* in main:\n    for (int u = 0; u < V; u++)\n        if (num[u] == UNVISITED)\n\
    \            tarjanSCC(u);\n    */\n}\n\nint main()\n{\n    //find Bridges and\
    \ AVs\n    for (int u = 0; u < V; ++u)\n        if (dfs_num[u] == UNVISITED) {\n\
    \            dfsRoot = u; rootChildren = 0;\n            findAV(u);\n        \
    \    av[dfsRoot] = (rootChildren > 1); // special case\n        }\n    //printf(\"\
    Articulation Points:\\n\");\n    for (int u = 0; u < V; ++u)\n        if (av[u])\n\
    \            cout << u;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nenum { UNVISITED = -1,\
    \ VISITED = -2 };\n#define INF (int)1e9\n#define ii pair<int, int>\n#define vi\
    \ vector<int>\n#define vii vector<ii>\n\nvector<vii> AL;\nvi dist, p, dfs_num,\
    \ num, low, av, visited,ts; //dfs_num only for visited or not, num for dfs numbering\n\
    int V, E, dfs_cnt, dfsRoot, rootChildren;\n\nvoid bfs(int s)\n{\n    dist[s] =\
    \ 0;\n    queue<int> q; q.push(s);\n    p.assign(V, -1);\n\n\n    bool isBi =\
    \ true;\n\n    while (!q.empty())\n    {\n        int u = q.front(); q.pop();\n\
    \        for (auto &[v, w] : AL[u])\n        {\n            if (dist[v] == INF)\n\
    \            {\n                dist[v] = dist[u] + 1;\n                p[v] =\
    \ u;\n                q.push(v);\n            }\n            else if (dist[v]\
    \ % 2 == dist[u] % 2) //same parity\n                isBi = false;\n        }\n\
    \    }\n}\n\nvoid dfs(int u)\n{\n    //cout << u;\n    dfs_num[u] = VISITED;\n\
    \    for (auto &[v, w] : AL[u])\n    {\n        if (dfs_num[v] == UNVISITED)\n\
    \            dfs(v);\n    }\n    //ts.push_back(u); //topological sort\n}\n\n\
    //DFS application\nvoid findAV(int u) //find articulation points and bridges\n\
    {\n    num[u] = dfs_cnt++;\n    low[u] = num[u]; \n    for (auto &[v, w] : AL[u])\n\
    \    {\n        if (num[u] == UNVISITED)\n        {\n            p[v] = u;\n \
    \           if (u == dfsRoot) ++rootChildren;\n            findAV(v);\n\n    \
    \        if (low[v] >= num[u]) av[u] = 1; //av here\n\n            if (low[v]\
    \ > num[u]) // --> bridge (u,v)\n            {}\n\n            low[u] = min(low[u],\
    \ low[v]);\n\n        }\n        else if (v != p[u])\n            low[u] = min(low[u],\
    \ num[v]);\n    }\n}\nint countCC() //for counting connected components\n{\n \
    \   int numCC = 0;\n    for (int u = 0; u <= V; u++)\n    {\n        if (dfs_num[u]\
    \ == UNVISITED)\n        {\n            numCC++;\n            dfs(u);\n      \
    \  }\n    }\n}\n\nstack<int> St;\nint numSCC = 0;\nvoid tarjanSCC(int u) //for\
    \ finding strongly connected components\n{\n    low[u] = num[u] = dfs_cnt; dfs_cnt++;\n\
    \    St.push(u);\n    visited[u] = 1;\n    for (auto &[v, w] : AL[u])\n    {\n\
    \        if (num[v] == UNVISITED)\n            tarjanSCC(v);\n        if (visited[v])\n\
    \            low[u] = min(low[u], low[v]);\n    }\n\n    if(low[u] == num[u])\
    \ //u is the root of SCC\n    {\n        numSCC++;\n        while (1)\n      \
    \  {\n            int v = St.top(); St.pop(); \n            visited[v] = 0;\n\
    \            if (u == v) break;\n        }\n    }\n\n    /* in main:\n    for\
    \ (int u = 0; u < V; u++)\n        if (num[u] == UNVISITED)\n            tarjanSCC(u);\n\
    \    */\n}\n\nint main()\n{\n    //find Bridges and AVs\n    for (int u = 0; u\
    \ < V; ++u)\n        if (dfs_num[u] == UNVISITED) {\n            dfsRoot = u;\
    \ rootChildren = 0;\n            findAV(u);\n            av[dfsRoot] = (rootChildren\
    \ > 1); // special case\n        }\n    //printf(\"Articulation Points:\\n\");\n\
    \    for (int u = 0; u < V; ++u)\n        if (av[u])\n            cout << u;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BFS-DFS.cpp
  requiredBy: []
  timestamp: '2024-11-10 11:18:59+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BFS-DFS.cpp
layout: document
redirect_from:
- /library/Graph/BFS-DFS.cpp
- /library/Graph/BFS-DFS.cpp.html
title: Graph/BFS-DFS.cpp
---
