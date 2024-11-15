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
  bundledCode: "#line 1 \"Data Structrue/LCA.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// Constants\nconst int MAXN = 100005;\nconst int LOG = 20;\n\
    \n// LCA Class using Euler Tour and Sparse Table (RMQ)\nstruct LCA {\n    int\
    \ n, root;\n    vector<vector<int>> adj;            // Adjacency list\n    vector<int>\
    \ depth;                  // Depth of each node\n    vector<int> first;      \
    \            // First occurrence in Euler Tour\n    vector<int> euler;       \
    \           // Euler Tour\n    vector<vector<pair<int, int>>> st;  // Sparse Table\
    \ for RMQ\n\n    // Constructor\n    LCA(int _n, const vector<vector<int>>& _adj,\
    \ int _root = 0)\n        : n(_n), adj(_adj), root(_root), depth(_n, 0), first(_n,\
    \ -1) {\n        dfs(root, -1, 0);\n        build_sparse_table();\n    }\n\n \
    \   // DFS to perform Euler Tour\n    void dfs(int u, int fu, int d){\n      \
    \  depth[u] = d;\n        first[u] = euler.size();\n        euler.emplace_back(u);\n\
    \        for(auto &v : adj[u]){\n            if(v != fu){\n                dfs(v,\
    \ u, d + 1);\n                euler.emplace_back(u);\n            }\n        }\n\
    \    }\n\n    // Build Sparse Table for RMQ\n    void build_sparse_table(){\n\
    \        int m = euler.size();\n        int log_m = log2(m) + 1;\n        st.assign(log_m,\
    \ vector<pair<int, int>>(m));\n\n        // Initialize level 0\n        for(int\
    \ i = 0; i < m; ++i){\n            st[0][i] = {depth[euler[i]], euler[i]};\n \
    \       }\n\n        // Build Sparse Table\n        for(int k = 1; (1 << k) <=\
    \ m; ++k){\n            for(int i = 0; i + (1 << k) <= m; ++i){\n            \
    \    st[k][i] = min(st[k-1][i], st[k-1][i + (1 << (k-1))]);\n            }\n \
    \       }\n    }\n\n    // Query Sparse Table for RMQ in range [L, R]\n    pair<int,\
    \ int> query(int L, int R){\n        int k = log2(R - L + 1);\n        return\
    \ min(st[k][L], st[k][R - (1 << k) + 1]);\n    }\n\n    // Function to compute\
    \ LCA of u and v\n    int lca_query(int u, int v){\n        if(first[u] > first[v])\
    \ swap(u, v);\n        pair<int, int> res = query(first[u], first[v]);\n     \
    \   return res.second;\n    }\n};\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    // Read number of nodes and queries\n    int n, q;\n \
    \   cin >> n >> q;\n\n    // Initialize adjacency list\n    vector<vector<int>>\
    \ adj(n, vector<int>());\n\n    // Read tree edges (assuming 0-based indexing\
    \ and node 0 is root)\n    // Typically, for n nodes, there are n-1 edges\n  \
    \  for(int i = 1; i < n; ++i){\n        int parent_node;\n        cin >> parent_node;\n\
    \        // If nodes are 1-based, uncomment the next line\n        // parent_node--;\n\
    \        adj[i].push_back(parent_node);\n        adj[parent_node].push_back(i);\n\
    \    }\n\n    // Initialize LCA structure\n    LCA lca(n, adj, 0); // Assuming\
    \ root is node 0\n\n    // Process queries\n    while(q--){\n        int u, v;\n\
    \        cin >> u >> v;\n        // If inputs are 1-based, convert to 0-based\n\
    \        // u--; v--;\n        int ancestor = lca.lca_query(u, v);\n        cout\
    \ << ancestor << '\\n';\n    }\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// Constants\nconst int\
    \ MAXN = 100005;\nconst int LOG = 20;\n\n// LCA Class using Euler Tour and Sparse\
    \ Table (RMQ)\nstruct LCA {\n    int n, root;\n    vector<vector<int>> adj;  \
    \          // Adjacency list\n    vector<int> depth;                  // Depth\
    \ of each node\n    vector<int> first;                  // First occurrence in\
    \ Euler Tour\n    vector<int> euler;                  // Euler Tour\n    vector<vector<pair<int,\
    \ int>>> st;  // Sparse Table for RMQ\n\n    // Constructor\n    LCA(int _n, const\
    \ vector<vector<int>>& _adj, int _root = 0)\n        : n(_n), adj(_adj), root(_root),\
    \ depth(_n, 0), first(_n, -1) {\n        dfs(root, -1, 0);\n        build_sparse_table();\n\
    \    }\n\n    // DFS to perform Euler Tour\n    void dfs(int u, int fu, int d){\n\
    \        depth[u] = d;\n        first[u] = euler.size();\n        euler.emplace_back(u);\n\
    \        for(auto &v : adj[u]){\n            if(v != fu){\n                dfs(v,\
    \ u, d + 1);\n                euler.emplace_back(u);\n            }\n        }\n\
    \    }\n\n    // Build Sparse Table for RMQ\n    void build_sparse_table(){\n\
    \        int m = euler.size();\n        int log_m = log2(m) + 1;\n        st.assign(log_m,\
    \ vector<pair<int, int>>(m));\n\n        // Initialize level 0\n        for(int\
    \ i = 0; i < m; ++i){\n            st[0][i] = {depth[euler[i]], euler[i]};\n \
    \       }\n\n        // Build Sparse Table\n        for(int k = 1; (1 << k) <=\
    \ m; ++k){\n            for(int i = 0; i + (1 << k) <= m; ++i){\n            \
    \    st[k][i] = min(st[k-1][i], st[k-1][i + (1 << (k-1))]);\n            }\n \
    \       }\n    }\n\n    // Query Sparse Table for RMQ in range [L, R]\n    pair<int,\
    \ int> query(int L, int R){\n        int k = log2(R - L + 1);\n        return\
    \ min(st[k][L], st[k][R - (1 << k) + 1]);\n    }\n\n    // Function to compute\
    \ LCA of u and v\n    int lca_query(int u, int v){\n        if(first[u] > first[v])\
    \ swap(u, v);\n        pair<int, int> res = query(first[u], first[v]);\n     \
    \   return res.second;\n    }\n};\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    // Read number of nodes and queries\n    int n, q;\n \
    \   cin >> n >> q;\n\n    // Initialize adjacency list\n    vector<vector<int>>\
    \ adj(n, vector<int>());\n\n    // Read tree edges (assuming 0-based indexing\
    \ and node 0 is root)\n    // Typically, for n nodes, there are n-1 edges\n  \
    \  for(int i = 1; i < n; ++i){\n        int parent_node;\n        cin >> parent_node;\n\
    \        // If nodes are 1-based, uncomment the next line\n        // parent_node--;\n\
    \        adj[i].push_back(parent_node);\n        adj[parent_node].push_back(i);\n\
    \    }\n\n    // Initialize LCA structure\n    LCA lca(n, adj, 0); // Assuming\
    \ root is node 0\n\n    // Process queries\n    while(q--){\n        int u, v;\n\
    \        cin >> u >> v;\n        // If inputs are 1-based, convert to 0-based\n\
    \        // u--; v--;\n        int ancestor = lca.lca_query(u, v);\n        cout\
    \ << ancestor << '\\n';\n    }\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Data Structrue/LCA.cpp
  requiredBy: []
  timestamp: '2024-11-15 23:57:47+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structrue/LCA.cpp
layout: document
redirect_from:
- /library/Data Structrue/LCA.cpp
- /library/Data Structrue/LCA.cpp.html
title: Data Structrue/LCA.cpp
---
