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
    - https://codeforces.com/problemsets/acmsguru/problem/99999/101
    - https://oj.vnoi.info/problem/tour2509
    - https://oj.vnoi.info/problem/vnoicup22_final_c
    - https://open.kattis.com/problems/eulerianpath
  bundledCode: "#line 1 \"Graph/EulerPath.cpp\"\n// NOTES:\n// - For directed -> see\
    \ EulerPathDirected.h\n// - Here we assume that we only need to draw every edges\
    \ (and not every\n//   vertices). So for graph with 0 edges, it returns true\n\
    //\n// Tested:\n// - SGU 101: https://codeforces.com/problemsets/acmsguru/problem/99999/101\n\
    // - https://oj.vnoi.info/problem/tour2509\nstruct EulerUndirected {\n    EulerUndirected(int\
    \ _n) : n(_n), m(0), adj(_n), deg(_n, 0) {}\n\n    void add_edge(int u, int v)\
    \ {\n        adj[u].push_front(Edge(v));\n        auto it1 = adj[u].begin();\n\
    \        adj[v].push_front(Edge(u));\n        auto it2 = adj[v].begin();\n\n \
    \       it1->rev = it2;\n        it2->rev = it1;\n\n        ++deg[u];\n      \
    \  ++deg[v];\n        ++m;\n    }\n\n    std::pair<bool, std::vector<int>> solve()\
    \ {\n        int cntOdd = 0;\n        int start = -1;\n        for (int i = 0;\
    \ i < n; i++) {\n            if (deg[i] % 2) {\n                ++cntOdd;\n  \
    \              if (cntOdd > 2) return {false, {}};\n\n                if (start\
    \ < 0) start = i;\n            }\n        }\n\n        // no odd vertex -> start\
    \ from any vertex with positive degree\n        if (start < 0) {\n           \
    \ for (int i = 0; i < n; i++) {\n                if (deg[i]) {\n             \
    \       start = i;\n                    break;\n                }\n          \
    \  }\n            if (start < 0) {\n                // no edge -> empty path\n\
    \                return {true, {}};\n            }\n        }\n\n        std::vector<int>\
    \ path;\n        find_path(start, path);\n\n        if (m + 1 != static_cast<int>\
    \ (path.size())) {\n            return {false, {}};\n        }\n\n        return\
    \ {true, path};\n    }\n\n    struct Edge {\n        int to;\n        std::list<Edge>::iterator\
    \ rev;\n\n        Edge(int _to) : to(_to) {}\n    };\n\n//private:\n    int n,\
    \ m;\n    std::vector<std::list<Edge>> adj;\n    std::vector<int> deg;\n\n   \
    \ void find_path(int v, std::vector<int>& path) {\n        while (adj[v].size()\
    \ > 0) {\n            int next = adj[v].front().to;\n            adj[next].erase(adj[v].front().rev);\n\
    \            adj[v].pop_front();\n            find_path(next, path);\n       \
    \ }\n        path.push_back(v);\n    }\n};\n\n\n////Directed:\n// Tested:\n//\
    \ - https://open.kattis.com/problems/eulerianpath\n// - https://oj.vnoi.info/problem/vnoicup22_final_c\n\
    struct EulerDirected {\n    EulerDirected(int _n) : n(_n), adj(n), in_deg(n, 0),\
    \ out_deg(n, 0) {}\n\n    void add_edge(int u, int v) {  // directed edge\n  \
    \      assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        adj[u].push_front(v);\n\
    \        in_deg[v]++;\n        out_deg[u]++;\n    }\n\n    std::pair<bool, std::vector<int>>\
    \ solve() {\n        int start = -1, last = -1;\n        for (int i = 0; i < n;\
    \ i++) {\n            // for all u, |in_deg(u) - out_deg(u)| <= 1\n          \
    \  if (std::abs(in_deg[i] - out_deg[i]) > 1) return {false, {}};\n\n         \
    \   if (out_deg[i] > in_deg[i]) {\n                // At most 1 vertex with out_deg[u]\
    \ - in_deg[u] = 1 (start vertex)\n                if (start >= 0) return {false,\
    \ {}};\n                start = i;\n            }\n\n            if (in_deg[i]\
    \ > out_deg[i]) {\n                // At most 1 vertex with in_deg[u] - out_deg[u]\
    \ = 1 (last vertex)\n                if (last >= 0) return {false, {}};\n    \
    \            last = i;\n            }\n        }\n\n        // can start at any\
    \ vertex with degree > 0\n        if (start < 0) {\n            for (int i = 0;\
    \ i < n; i++) {\n                if (in_deg[i]) {\n                    start =\
    \ i;\n                    break;\n                }\n            }\n         \
    \   // no start vertex --> all vertices have degree == 0\n            if (start\
    \ < 0) return {true, {}};\n        }\n\n        std::vector<int> path;\n     \
    \   find_path(start, path);\n        std::reverse(path.begin(), path.end());\n\
    \n        // check that we visited all vertices with degree > 0\n        std::vector<bool>\
    \ visited(n, false);\n        for (int u : path) visited[u] = true;\n\n      \
    \  for (int u = 0; u < n; u++) {\n            if (in_deg[u] && !visited[u]) {\n\
    \                return {false, {}};\n            }\n        }\n\n        return\
    \ {true, path};\n    }\n\nprivate:\n    int n;\n    std::vector<std::list<int>>\
    \ adj;\n    std::vector<int> in_deg, out_deg;\n\n    void find_path(int v, std::vector<int>&\
    \ path) {\n        while (adj[v].size() > 0) {\n            int next = adj[v].front();\n\
    \            adj[v].pop_front();\n            find_path(next, path);\n       \
    \ }\n        path.push_back(v);\n    }\n};\n"
  code: "// NOTES:\n// - For directed -> see EulerPathDirected.h\n// - Here we assume\
    \ that we only need to draw every edges (and not every\n//   vertices). So for\
    \ graph with 0 edges, it returns true\n//\n// Tested:\n// - SGU 101: https://codeforces.com/problemsets/acmsguru/problem/99999/101\n\
    // - https://oj.vnoi.info/problem/tour2509\nstruct EulerUndirected {\n    EulerUndirected(int\
    \ _n) : n(_n), m(0), adj(_n), deg(_n, 0) {}\n\n    void add_edge(int u, int v)\
    \ {\n        adj[u].push_front(Edge(v));\n        auto it1 = adj[u].begin();\n\
    \        adj[v].push_front(Edge(u));\n        auto it2 = adj[v].begin();\n\n \
    \       it1->rev = it2;\n        it2->rev = it1;\n\n        ++deg[u];\n      \
    \  ++deg[v];\n        ++m;\n    }\n\n    std::pair<bool, std::vector<int>> solve()\
    \ {\n        int cntOdd = 0;\n        int start = -1;\n        for (int i = 0;\
    \ i < n; i++) {\n            if (deg[i] % 2) {\n                ++cntOdd;\n  \
    \              if (cntOdd > 2) return {false, {}};\n\n                if (start\
    \ < 0) start = i;\n            }\n        }\n\n        // no odd vertex -> start\
    \ from any vertex with positive degree\n        if (start < 0) {\n           \
    \ for (int i = 0; i < n; i++) {\n                if (deg[i]) {\n             \
    \       start = i;\n                    break;\n                }\n          \
    \  }\n            if (start < 0) {\n                // no edge -> empty path\n\
    \                return {true, {}};\n            }\n        }\n\n        std::vector<int>\
    \ path;\n        find_path(start, path);\n\n        if (m + 1 != static_cast<int>\
    \ (path.size())) {\n            return {false, {}};\n        }\n\n        return\
    \ {true, path};\n    }\n\n    struct Edge {\n        int to;\n        std::list<Edge>::iterator\
    \ rev;\n\n        Edge(int _to) : to(_to) {}\n    };\n\n//private:\n    int n,\
    \ m;\n    std::vector<std::list<Edge>> adj;\n    std::vector<int> deg;\n\n   \
    \ void find_path(int v, std::vector<int>& path) {\n        while (adj[v].size()\
    \ > 0) {\n            int next = adj[v].front().to;\n            adj[next].erase(adj[v].front().rev);\n\
    \            adj[v].pop_front();\n            find_path(next, path);\n       \
    \ }\n        path.push_back(v);\n    }\n};\n\n\n////Directed:\n// Tested:\n//\
    \ - https://open.kattis.com/problems/eulerianpath\n// - https://oj.vnoi.info/problem/vnoicup22_final_c\n\
    struct EulerDirected {\n    EulerDirected(int _n) : n(_n), adj(n), in_deg(n, 0),\
    \ out_deg(n, 0) {}\n\n    void add_edge(int u, int v) {  // directed edge\n  \
    \      assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        adj[u].push_front(v);\n\
    \        in_deg[v]++;\n        out_deg[u]++;\n    }\n\n    std::pair<bool, std::vector<int>>\
    \ solve() {\n        int start = -1, last = -1;\n        for (int i = 0; i < n;\
    \ i++) {\n            // for all u, |in_deg(u) - out_deg(u)| <= 1\n          \
    \  if (std::abs(in_deg[i] - out_deg[i]) > 1) return {false, {}};\n\n         \
    \   if (out_deg[i] > in_deg[i]) {\n                // At most 1 vertex with out_deg[u]\
    \ - in_deg[u] = 1 (start vertex)\n                if (start >= 0) return {false,\
    \ {}};\n                start = i;\n            }\n\n            if (in_deg[i]\
    \ > out_deg[i]) {\n                // At most 1 vertex with in_deg[u] - out_deg[u]\
    \ = 1 (last vertex)\n                if (last >= 0) return {false, {}};\n    \
    \            last = i;\n            }\n        }\n\n        // can start at any\
    \ vertex with degree > 0\n        if (start < 0) {\n            for (int i = 0;\
    \ i < n; i++) {\n                if (in_deg[i]) {\n                    start =\
    \ i;\n                    break;\n                }\n            }\n         \
    \   // no start vertex --> all vertices have degree == 0\n            if (start\
    \ < 0) return {true, {}};\n        }\n\n        std::vector<int> path;\n     \
    \   find_path(start, path);\n        std::reverse(path.begin(), path.end());\n\
    \n        // check that we visited all vertices with degree > 0\n        std::vector<bool>\
    \ visited(n, false);\n        for (int u : path) visited[u] = true;\n\n      \
    \  for (int u = 0; u < n; u++) {\n            if (in_deg[u] && !visited[u]) {\n\
    \                return {false, {}};\n            }\n        }\n\n        return\
    \ {true, path};\n    }\n\nprivate:\n    int n;\n    std::vector<std::list<int>>\
    \ adj;\n    std::vector<int> in_deg, out_deg;\n\n    void find_path(int v, std::vector<int>&\
    \ path) {\n        while (adj[v].size() > 0) {\n            int next = adj[v].front();\n\
    \            adj[v].pop_front();\n            find_path(next, path);\n       \
    \ }\n        path.push_back(v);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/EulerPath.cpp
  requiredBy: []
  timestamp: '2024-11-07 00:17:58+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/EulerPath.cpp
layout: document
redirect_from:
- /library/Graph/EulerPath.cpp
- /library/Graph/EulerPath.cpp.html
title: Graph/EulerPath.cpp
---
