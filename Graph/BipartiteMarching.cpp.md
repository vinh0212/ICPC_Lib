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
    - https://codeforces.com/gym/100337
    - https://codeforces.com/gym/100337/submission/139751832)
    - https://judge.yosupo.jp/problem/bipartitematching
    - https://oj.vnoi.info/problem/fmatch
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Matching/BipartiteMatching.h:\
    \ line -1: no such header\n"
  code: "// Max Bipartite matching.\n// Index from 0\n// Assume 2 sides have same\
    \ number of vertices\n//\n// Notes:\n// - If TLE --> try shuffle edges\n//   REP(i,n)\
    \ shuffle(ke[i].begin(), ke[i].end(), rng)\n// - It should be quite fast, can\
    \ AC 10^5 vertices\n//\n// Find vertices that belong to all maximum matching:\n\
    // (see https://codeforces.com/gym/100337/submission/139751832)\n// - L = vertices\
    \ not matched on left side --> BFS from these vertices\n//   (left --> right:\
    \ unmatched edges, right --> left: matched edges)\n//   reachable vertices on\
    \ left side --> not belong to some maximum matching\n// - Do similar for right\
    \ side\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/bipartitematching\n\
    // - https://oj.vnoi.info/problem/fmatch\n// - https://codeforces.com/gym/100337\
    \ - A: find vertices belong to all max matching\n\n// Bipartite Matching {{{\n\
    struct Matching {\n    int n;\n    vector< vector<int> > ke;\n    vector< int\
    \ > seen;\n    vector< int > matchL, matchR;\n    int iteration;\n\n    Matching(int\
    \ _n) : n(_n), ke(_n), seen(_n, false), matchL(_n, -1), matchR(_n, -1), iteration{0}\
    \ {\n    }\n\n    void addEdge(int u, int v) {\n        ke[u].push_back(v);\n\
    \    }\n\n    bool dfs(int u) {\n        seen[u] = iteration;\n        for (int\
    \ v : ke[u]) {\n            if (matchR[v] < 0) {\n                matchR[v] =\
    \ u;\n                matchL[u] = v;\n                return true;\n         \
    \   }\n        }\n        for (int v : ke[u]) {\n            if (seen[matchR[v]]\
    \ != iteration && dfs(matchR[v])) {\n                matchR[v] = u;\n        \
    \        matchL[u] = v;\n                return true;\n            }\n       \
    \ }\n        return false;\n    }\n\n    int match() {\n        int res = 0;\n\
    \        int newMatches = 0;\n        do {\n            iteration++;\n       \
    \     newMatches = 0;\n            for (int u = 0; u < n; u++) {\n           \
    \     if (matchL[u] < 0 && dfs(u)) ++newMatches;\n            }\n            res\
    \ += newMatches;\n        } while (newMatches > 0);\n        return res;\n   \
    \ }\n};\n// }}}\n//Example Code\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../Matching/BipartiteMatching.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int left, right,\
    \ m; cin >> left >> right >> m;\n    Matching mat(max(left, right));\n    while\
    \ (m--) {\n        int u, v; cin >> u >> v;\n        mat.addEdge(u, v);\n    }\n\
    \n    REP(i,left) {\n        shuffle(mat.ke[i].begin(), mat.ke[i].end(), rng);\n\
    \    }\n\n    cout << mat.match() << '\\n';\n    REP(i,left) {\n        if (mat.matchL[i]\
    \ >= 0) {\n            cout << i << ' ' << mat.matchL[i] << '\\n';\n        }\n\
    \    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BipartiteMarching.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BipartiteMarching.cpp
layout: document
redirect_from:
- /library/Graph/BipartiteMarching.cpp
- /library/Graph/BipartiteMarching.cpp.html
title: Graph/BipartiteMarching.cpp
---
