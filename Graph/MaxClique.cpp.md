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
    - https://judge.yosupo.jp/problem/maximum_independent_set
    - https://judge.yosupo.jp/submission/15825
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../MaxClique.h:\
    \ line -1: no such header\n"
  code: "// MaxClique\n// Copied from https://judge.yosupo.jp/submission/15825\n//\n\
    // 0-based index\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/maximum_independent_set\n\
    struct MaxClique {\n    static const int MN = 64; // change to bitset for n >\
    \ 64\n    int n, deg[MN];\n    uint64_t g[MN], ans;\n    vector<pair<int,int>>\
    \ edges;\n\n    MaxClique(int _n) : n(_n) {\n        fill(g, g+n, 0ull);\n   \
    \     fill(deg, deg+n, 0);\n        edges.clear();\n    }\n\n    // Add bi-directional\
    \ edge\n    // 0-based index\n    void addEdge(int u, int v) {\n        edges.emplace_back(u,\
    \ v);\n        ++deg[u]; ++deg[v];\n    }\n\n    vector<int> solve() {\n     \
    \   vector<int> ord(n);\n        iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(),\
    \ ord.end(), [&] (int u, int v) { return deg[u] < deg[v]; });\n        vector<int>\
    \ id(n);\n        for (int i = 0; i < n; i++) id[ord[i]] = i;\n\n        for (const\
    \ auto& e : edges) {\n            int u = id[e.first], v = id[e.second];\n   \
    \         g[u] |= 1ull << v;\n            g[v] |= 1ull << u;\n        }\n    \
    \    uint64_t r = 0, p = (1ull << n) - 1;\n        ans = 0;\n        dfs(r, p);\n\
    \        vector<int> res;\n        for (int i = 0; i < n; i++) {\n           \
    \ if ((ans >> i) & 1) res.push_back(ord[i]);\n        }\n        return res;\n\
    \    }\n\n#define cnt __builtin_popcountll\n    void dfs(uint64_t r, uint64_t\
    \ p) {\n        if (p == 0) {\n            if (cnt(r) > cnt(ans)) ans = r;\n \
    \           return;\n        }\n        if (cnt(r | p) <= cnt(ans)) return;\n\
    \        int x = __builtin_ctzll(p & -p);\n        uint64_t c = p;\n        while\
    \ (c > 0) {\n            x = __builtin_ctzll(c & -c);\n            r |= 1ull <<\
    \ x;\n            dfs(r, p & g[x]);\n            r &= ~(1ull << x);\n        \
    \    p &= ~(1ull << x);\n            c ^= 1ull << x;\n        }\n    }\n};\n\n\
    //Example Code\n#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../MaxClique.h\"\
    \n\nbool edge[44][44];\n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i;\
    \ ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int\
    \ n, m; cin >> n >> m;\n\n    REP(i,m) {\n        int u, v; cin >> u >> v;\n \
    \       edge[u][v] = edge[v][u] = 1;\n    }\n\n    MaxClique g(n);\n    REP(i,n)\
    \ REP(j,n) if (!edge[i][j] && i != j) {\n        g.addEdge(i, j);\n    }\n\n \
    \   auto res = g.solve();\n    cout << res.size() << endl;\n    for (int x : res)\
    \ {\n        cout << x << ' ';\n    }\n    cout << endl;\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/MaxClique.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/MaxClique.cpp
layout: document
redirect_from:
- /library/Graph/MaxClique.cpp
- /library/Graph/MaxClique.cpp.html
title: Graph/MaxClique.cpp
---
