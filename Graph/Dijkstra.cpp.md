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
  bundledCode: "#line 1 \"Graph/Dijkstra.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#define ii pair<int,int>\n#define vi vector<int>\n\nconst int INF = 1e9;\n\
    \nvi dist(0, INF);\nvector<vector<ii>> AL;\n\nvoid dijkstra(int s)\n{\n    priority_queue<ii,\
    \ vector<ii>, greater<ii>> pq;\n    pq.push({0,s}); //multi-source: for(auto u\
    \ : sources) pq.push({0,u});\n\n    while(!pq.empty())\n    {\n        auto [d,u]\
    \ = pq.top(); pq.pop();\n        if (d > dist[u]) continue;\n        for (auto\
    \ &[v,w] : AL[u])\n        {\n            if(dist[u] + w >= dist[v]) continue;\n\
    \            dist[v] = dist[u] + w;\n            pq.push({dist[v], v});\n    \
    \    }\n    }\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n#define ii pair<int,int>\n\
    #define vi vector<int>\n\nconst int INF = 1e9;\n\nvi dist(0, INF);\nvector<vector<ii>>\
    \ AL;\n\nvoid dijkstra(int s)\n{\n    priority_queue<ii, vector<ii>, greater<ii>>\
    \ pq;\n    pq.push({0,s}); //multi-source: for(auto u : sources) pq.push({0,u});\n\
    \n    while(!pq.empty())\n    {\n        auto [d,u] = pq.top(); pq.pop();\n  \
    \      if (d > dist[u]) continue;\n        for (auto &[v,w] : AL[u])\n       \
    \ {\n            if(dist[u] + w >= dist[v]) continue;\n            dist[v] = dist[u]\
    \ + w;\n            pq.push({dist[v], v});\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2024-11-08 23:54:49+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Dijkstra.cpp
layout: document
redirect_from:
- /library/Graph/Dijkstra.cpp
- /library/Graph/Dijkstra.cpp.html
title: Graph/Dijkstra.cpp
---
