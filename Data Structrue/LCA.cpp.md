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
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: RMQ.h: line -1:\
    \ no such header\n"
  code: "// LCA\n// Notes:\n// - Index from 0\n// - Cannot use for queries like min\
    \ edge in path u -> v\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/lca\n\
    #include \"RMQ.h\"\nstruct LCA {\n    const int n;\n    vector<vector<int>> adj;\n\
    \    const int root;\n    using P = pair<int,int>;\n    static P f(P x, P y) {\
    \ return std::min(x, y); }\n\n    LCA(int _n, const vector<vector<int>>& _adj,\
    \ int _root)\n            : n(_n), adj(_adj), root(_root) {\n        assert(0\
    \ <= root && root < n);\n        id.resize(n);\n        depth.resize(n);\n   \
    \     order.reserve(2 * n);\n        dfs(root, -1, 0);\n        rmq = RMQ<P, f>(order);\n\
    \    }\n\n    int lca(int u, int v) {\n        assert(0 <= u && u < n);\n    \
    \    assert(0 <= v && v < n);\n\n        int x = id[u], y = id[v];\n        if\
    \ (x > y) std::swap(x, y);\n        return rmq.get(x, y+1).second;\n    }\n\n\
    // private:\n    vector<int> id, depth;\n    vector<P> order;\n    RMQ<P, f> rmq;\n\
    \n    void dfs(int u, int fu, int d) {\n        id[u] = order.size();\n      \
    \  depth[u] = d;\n        order.emplace_back(d, u);\n        for (int v : adj[u])\
    \ {\n            if (v == fu) continue;\n            dfs(v, u, d + 1);\n     \
    \       order.emplace_back(d, u);\n        }\n    }\n};\n\n//Example Code\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../LCA.h\"\n#include \"../../buffered_reader.h\"\
    \n\n#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)\n\nint32_t\
    \ main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n = IO::get<int>();\n\
    \    int q = IO::get<int>();\n    vector<vector<int>> adj(n);\n    FOR(i,1,n-1)\
    \ {\n        int pi = IO::get<int>();\n        adj[i].push_back(pi);\n       \
    \ adj[pi].push_back(i);\n    }\n\n    LCA lca(n, adj, 0);\n\n    while (q--) {\n\
    \        int u = IO::get<int>();\n        int v = IO::get<int>();\n\n        cout\
    \ << lca.lca(u, v) << '\\n';\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Data Structrue/LCA.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structrue/LCA.cpp
layout: document
redirect_from:
- /library/Data Structrue/LCA.cpp
- /library/Data Structrue/LCA.cpp.html
title: Data Structrue/LCA.cpp
---
