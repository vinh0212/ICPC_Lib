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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: .../DSU/DisjointSets.cpp:\
    \ line -1: no such header\n"
  code: "#include <bits/stdc++.h>\n#include \".../DSU/DisjointSets.cpp\"\n\nusing\
    \ namespace std;\n\n#define fto(i, x, y) for (int i = x; i <= y; ++i)\n#define\
    \ iii tuple<int, int, int>\n\nvoid kruskal()\n{\n    vector<iii> EL(E);\n    fto(i,1,V)\
    \ \n    {\n        int u,v,w; cin >> u >> v >> w;\n        EL.pb({w,u,v});\n \
    \   }\n\n    sort(EL.begin(), EL.end());\n\n    int cost = 0, taken = 0;\n\n \
    \   UnionFind UF(V);\n    for (auto &[w,u,v] : EL)\n    {\n        if(UF.isSameSet(u,\
    \ v)) continue;\n        cost += w;\n\n        UF.unionSet(u, v);\n        taken++;\n\
    \        if(taken == V-1) break;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/MST-kruskal.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/MST-kruskal.cpp
layout: document
redirect_from:
- /library/Graph/MST-kruskal.cpp
- /library/Graph/MST-kruskal.cpp.html
title: Graph/MST-kruskal.cpp
---
