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
    - https://github.com/jaehyunp/stanfordacm/blob/master/code/Dinic.cc
  bundledCode: "#line 1 \"Algorithm/Dinic MaxFlow.cpp\"\n// Disclaimer: This code\
    \ is a hybrid between old CP1-2-3 implementation of\n// Edmonds Karp's algorithm\
    \ -- re-written in OOP fashion and the fast\n// Dinic's algorithm implementation\
    \ by\n// https://github.com/jaehyunp/stanfordacm/blob/master/code/Dinic.cc\n//\
    \ This code is written in modern C++17 standard\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntypedef long long ll;\ntypedef tuple<int, ll, ll> edge;\n\
    typedef vector<int> vi;\ntypedef pair<int, int> ii;\n\nconst ll INF = 1e18; //\
    \ large enough\n\nclass max_flow\n{\nprivate:\n    int V;\n    vector<edge> EL;\n\
    \    vector<vi> AL;\n    vi d, last;\n    vector<ii> p;\n\n    bool BFS(int s,\
    \ int t)\n    { // find augmenting path\n        d.assign(V, -1);\n        d[s]\
    \ = 0;\n        queue<int> q({s});\n        p.assign(V, {-1, -1}); // record BFS\
    \ sp tree\n        while (!q.empty())\n        {\n            int u = q.front();\n\
    \            q.pop();\n            if (u == t)\n                break; // stop\
    \ as sink t reached\n            for (auto &idx : AL[u])\n            {      \
    \                                              // explore neighbors of u\n   \
    \             auto &[v, cap, flow] = EL[idx];                  // stored in EL[idx]\n\
    \                if ((cap - flow > 0) && (d[v] == -1))            // positive\
    \ residual edge\n                    d[v] = d[u] + 1, q.push(v), p[v] = {u, idx};\
    \ // 3 lines in one!\n            }\n        }\n        return d[t] != -1; //\
    \ has an augmenting path\n    }\n\n    ll DFS(int u, int t, ll f = INF)\n    {\
    \ // traverse from s->t\n        if ((u == t) || (f == 0))\n            return\
    \ f;\n        for (int &i = last[u]; i < (int)AL[u].size(); ++i)\n        { //\
    \ from last edge\n            auto &[v, cap, flow] = EL[AL[u][i]];\n         \
    \   if (d[v] != d[u] + 1)\n                continue; // not part of layer graph\n\
    \            if (ll pushed = DFS(v, t, min(f, cap - flow)))\n            {\n \
    \               flow += pushed;\n                auto &rflow = get<2>(EL[AL[u][i]\
    \ ^ 1]); // back edge\n                rflow -= pushed;\n                return\
    \ pushed;\n            }\n        }\n        return 0;\n    }\n\npublic:\n   \
    \ max_flow(int initialV) : V(initialV)\n    {\n        EL.clear();\n        AL.assign(V,\
    \ vi());\n    }\n\n    // if you are adding a bidirectional edge u<->v with weight\
    \ w into your\n    // flow graph, set directed = false (default value is directed\
    \ = true)\n    void add_edge(int u, int v, ll w, bool directed = true)\n    {\n\
    \        if (u == v)\n            return;                              // safeguard:\
    \ no self loop\n        EL.emplace_back(v, w, 0);                // u->v, cap\
    \ w, flow 0\n        AL[u].push_back(EL.size() - 1);          // remember this\
    \ index\n        EL.emplace_back(u, directed ? 0 : w, 0); // back edge\n     \
    \   AL[v].push_back(EL.size() - 1);          // remember this index\n    }\n\n\
    \n    ll dinic(int s, int t)\n    {\n        ll mf = 0; // mf stands for max_flow\n\
    \        while (BFS(s, t))\n        {                            // an O(V^2*E)\
    \ algorithm\n            last.assign(V, 0);       // important speedup\n     \
    \       while (ll f = DFS(s, t)) // exhaust blocking flow\n                mf\
    \ += f;\n        }\n        return mf;\n    }\n};\n\nint main()\n{\n    /*\n \
    \   // Graph in Figure 8.11\n    4 0 3\n    2 1 8 2 8\n    2 2 1 3 8\n    1 3\
    \ 8\n    0\n    // the max flow value of that graph should be 16\n    */\n\n \
    \   freopen(\"maxflow_in.txt\", \"r\", stdin);\n\n    int V, s, t;\n    scanf(\"\
    %d %d %d\", &V, &s, &t);\n    max_flow mf(V);\n    for (int u = 0; u < V; ++u)\n\
    \    {\n        int k;\n        scanf(\"%d\", &k);\n        while (k--)\n    \
    \    {\n            int v, w;\n            scanf(\"%d %d\", &v, &w);\n       \
    \     mf.add_edge(u, v, w); // default: directed edge\n        }\n    }\n    printf(\"\
    %lld\\n\", mf.dinic(s, t));\n\n    return 0;\n}\n"
  code: "// Disclaimer: This code is a hybrid between old CP1-2-3 implementation of\n\
    // Edmonds Karp's algorithm -- re-written in OOP fashion and the fast\n// Dinic's\
    \ algorithm implementation by\n// https://github.com/jaehyunp/stanfordacm/blob/master/code/Dinic.cc\n\
    // This code is written in modern C++17 standard\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntypedef long long ll;\ntypedef tuple<int, ll, ll> edge;\n\
    typedef vector<int> vi;\ntypedef pair<int, int> ii;\n\nconst ll INF = 1e18; //\
    \ large enough\n\nclass max_flow\n{\nprivate:\n    int V;\n    vector<edge> EL;\n\
    \    vector<vi> AL;\n    vi d, last;\n    vector<ii> p;\n\n    bool BFS(int s,\
    \ int t)\n    { // find augmenting path\n        d.assign(V, -1);\n        d[s]\
    \ = 0;\n        queue<int> q({s});\n        p.assign(V, {-1, -1}); // record BFS\
    \ sp tree\n        while (!q.empty())\n        {\n            int u = q.front();\n\
    \            q.pop();\n            if (u == t)\n                break; // stop\
    \ as sink t reached\n            for (auto &idx : AL[u])\n            {      \
    \                                              // explore neighbors of u\n   \
    \             auto &[v, cap, flow] = EL[idx];                  // stored in EL[idx]\n\
    \                if ((cap - flow > 0) && (d[v] == -1))            // positive\
    \ residual edge\n                    d[v] = d[u] + 1, q.push(v), p[v] = {u, idx};\
    \ // 3 lines in one!\n            }\n        }\n        return d[t] != -1; //\
    \ has an augmenting path\n    }\n\n    ll DFS(int u, int t, ll f = INF)\n    {\
    \ // traverse from s->t\n        if ((u == t) || (f == 0))\n            return\
    \ f;\n        for (int &i = last[u]; i < (int)AL[u].size(); ++i)\n        { //\
    \ from last edge\n            auto &[v, cap, flow] = EL[AL[u][i]];\n         \
    \   if (d[v] != d[u] + 1)\n                continue; // not part of layer graph\n\
    \            if (ll pushed = DFS(v, t, min(f, cap - flow)))\n            {\n \
    \               flow += pushed;\n                auto &rflow = get<2>(EL[AL[u][i]\
    \ ^ 1]); // back edge\n                rflow -= pushed;\n                return\
    \ pushed;\n            }\n        }\n        return 0;\n    }\n\npublic:\n   \
    \ max_flow(int initialV) : V(initialV)\n    {\n        EL.clear();\n        AL.assign(V,\
    \ vi());\n    }\n\n    // if you are adding a bidirectional edge u<->v with weight\
    \ w into your\n    // flow graph, set directed = false (default value is directed\
    \ = true)\n    void add_edge(int u, int v, ll w, bool directed = true)\n    {\n\
    \        if (u == v)\n            return;                              // safeguard:\
    \ no self loop\n        EL.emplace_back(v, w, 0);                // u->v, cap\
    \ w, flow 0\n        AL[u].push_back(EL.size() - 1);          // remember this\
    \ index\n        EL.emplace_back(u, directed ? 0 : w, 0); // back edge\n     \
    \   AL[v].push_back(EL.size() - 1);          // remember this index\n    }\n\n\
    \n    ll dinic(int s, int t)\n    {\n        ll mf = 0; // mf stands for max_flow\n\
    \        while (BFS(s, t))\n        {                            // an O(V^2*E)\
    \ algorithm\n            last.assign(V, 0);       // important speedup\n     \
    \       while (ll f = DFS(s, t)) // exhaust blocking flow\n                mf\
    \ += f;\n        }\n        return mf;\n    }\n};\n\nint main()\n{\n    /*\n \
    \   // Graph in Figure 8.11\n    4 0 3\n    2 1 8 2 8\n    2 2 1 3 8\n    1 3\
    \ 8\n    0\n    // the max flow value of that graph should be 16\n    */\n\n \
    \   freopen(\"maxflow_in.txt\", \"r\", stdin);\n\n    int V, s, t;\n    scanf(\"\
    %d %d %d\", &V, &s, &t);\n    max_flow mf(V);\n    for (int u = 0; u < V; ++u)\n\
    \    {\n        int k;\n        scanf(\"%d\", &k);\n        while (k--)\n    \
    \    {\n            int v, w;\n            scanf(\"%d %d\", &v, &w);\n       \
    \     mf.add_edge(u, v, w); // default: directed edge\n        }\n    }\n    printf(\"\
    %lld\\n\", mf.dinic(s, t));\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/Dinic MaxFlow.cpp
  requiredBy: []
  timestamp: '2024-11-15 23:57:47+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/Dinic MaxFlow.cpp
layout: document
redirect_from:
- /library/Algorithm/Dinic MaxFlow.cpp
- /library/Algorithm/Dinic MaxFlow.cpp.html
title: Algorithm/Dinic MaxFlow.cpp
---
