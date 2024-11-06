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
    - https://judge.yosupo.jp/problem/enumerate_triangles
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../find_triangles.h:\
    \ line -1: no such header\n"
  code: "// Find all cycles of length 3 (a.k.a. triangles)\n// Complexity: O(N + M*sqrt(M))\n\
    //\n// Index from 0\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/enumerate_triangles\n\
    vector< tuple<int,int,int> > find_all_triangles(\n        int n,\n        vector<pair<int,int>>\
    \ edges) {\n    // Remove duplicated edges\n    sort(edges.begin(), edges.end());\n\
    \    edges.erase(unique(edges.begin(), edges.end()), edges.end());\n\n    // Compute\
    \ degs\n    vector<int> deg(n, 0);\n    for (const auto& [u, v] : edges) {\n \
    \       if (u == v) continue;\n        ++deg[u], ++deg[v];\n    }\n\n    // Add\
    \ edge (u, v) where u is 'lower' than v\n    vector<vector<int>> adj(n);\n   \
    \ for (auto [u, v] : edges) {\n        if (u == v) continue;\n        if (deg[u]\
    \ > deg[v] || (deg[u] == deg[v] && u > v)) swap(u, v);\n        adj[u].push_back(v);\n\
    \    }\n\n    // Find all triplets.\n    // If it's too slow, remove vector res\
    \ and compute answer directly\n    vector<tuple<int,int,int>> res;\n    vector<bool>\
    \ good(n, false);\n    for (int i = 0; i < n; i++) {\n        for (auto j : adj[i])\
    \ good[j] = true;\n        for (auto j : adj[i]) {\n            for (auto k :\
    \ adj[j]) {\n                if (good[k]) {\n                    res.emplace_back(i,\
    \ j, k);\n                }\n            }\n        }\n        for (auto j : adj[i])\
    \ good[j] = false;\n    }\n    return res;\n}\n//Example Code\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../find_triangles.h\"\n\n#define REP(i, a)\
    \ for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    int n, m; cin >> n >> m;\n    vector<long long> xs(n);\n  \
    \  REP(i,n) cin >> xs[i];\n\n    vector<pair<int,int>> edges(m);\n    for (auto&\
    \ [u, v] : edges) {\n        cin >> u >> v;\n    }\n\n    auto res = find_all_triangles(n,\
    \ edges);\n    long long sum = 0;\n    const int MOD = 998244353;\n    for (auto\
    \ [i, j, k] : res) {\n        sum = (sum + xs[i] * xs[j] % MOD * xs[k]) % MOD;\n\
    \    }\n    cout << sum << endl;\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/findTriangles.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/findTriangles.cpp
layout: document
redirect_from:
- /library/Graph/findTriangles.cpp
- /library/Graph/findTriangles.cpp.html
title: Graph/findTriangles.cpp
---
