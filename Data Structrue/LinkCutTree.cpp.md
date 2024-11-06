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
    - https://codeforces.com/blog/entry/67637?#comment-650424
    - https://codeforces.com/blog/entry/75885
    - https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
    - https://oj.vnoi.info/problem/icpc22_mn_b
    - https://www.spoj.com/problems/DYNACON1/
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../LinkCutTree.h:\
    \ line -1: no such header\n"
  code: "// copied from https://codeforces.com/blog/entry/75885\n// - Index from 1\n\
    // - T needs to support + operation\n//   For subtree queries -> requires - operation\n\
    //   --> see this comment for how to handle it: https://codeforces.com/blog/entry/67637?#comment-650424\n\
    // - Not using template here, since inheritance becomes very ugly\n// - Doesn't\
    \ support lazy update (so no subtree updates)\n// - For query on *edge* weights\
    \ (instead of vertex weights)\n//   --> for each edge, add a new node in LinkCut\
    \ tree.\n//       See https://oj.vnoi.info/problem/icpc22_mn_b for example\n//\n\
    // Tested:\n// - https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum\n\
    // - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\n\
    // - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\n// -\
    \ (edge weights) https://oj.vnoi.info/problem/icpc22_mn_b\n// - (link, cut, connected)\
    \ https://www.spoj.com/problems/DYNACON1/\n\n// Add this for path queries only\n\
    // #define PATH_QUERIES_ONLY\n\n// TODO: Specify T\n// using T = long long;\n\
    // Link Cut Tree {{{\n// SplayTree {{{\nstruct SplayTree { // can we replace SplayTreeById\
    \ and use this only?\n    struct Node {\n        array<int, 2> child = {0, 0};\n\
    \        int parent = 0;\n\n        // Path aggregates\n        // - path[0] =\
    \ go from left -> right\n        // - path[1] = go from right -> left\n      \
    \  array<T, 2> path;  // default to T constructor\n        T self;\n\n       \
    \ // Subtree aggregates\n        T sub, vir;\n\n        bool reverse = false;\n\
    \    };\n    vector<Node> nodes;\n\n    SplayTree(int n) : nodes(n + 1) {}\n\n\
    \    void splay(int x) {\n        for (pushDown(x); ~getDirection(x); ) {\n  \
    \          int y = nodes[x].parent;\n            int z = nodes[y].parent;\n  \
    \          pushDown(z);\n            pushDown(y);\n            pushDown(x);\n\
    \            int dx = getDirection(x);\n            int dy = getDirection(y);\n\
    \            if (~dy) rotate(dx != dy ? x : y);\n            rotate(x);\n    \
    \    }\n    }\n\n// private:\n    // Return t where nodes[parent(x)].child[t]\
    \ == x\n    int getDirection(int x) {\n        int p = nodes[x].parent;\n    \
    \    if (!p) return -1;\n        return nodes[p].child[0] == x ? 0 : nodes[p].child[1]\
    \ == x ? 1 : -1;\n    }\n\n    /**\n     * Before:\n     *    z\n     *    |\n\
    \     *    y\n     *   /\n     *  x\n     *   \\\n     *   xchild\n     * \n \
    \    * After:\n     *    z\n     *    |\n     *    x\n     *     \\\n     *  \
    \    y\n     *     /\n     *   xchild\n     */\n    void rotate(int x) {\n   \
    \     int y = nodes[x].parent, dx = getDirection(x);\n        int z = nodes[y].parent,\
    \ dy = getDirection(y);\n\n        setChild(y, nodes[x].child[!dx], dx);\n   \
    \     setChild(x, y, !dx);\n        if (~dy) setChild(z, x, dy);\n        nodes[x].parent\
    \ = z;\n    }\n\n    void pushDown(int x) {\n        if (!x) return;\n       \
    \ if (nodes[x].reverse) {\n            auto [l, r] = nodes[x].child;\n       \
    \     nodes[l].reverse ^= 1;\n            nodes[r].reverse ^= 1;\n\n         \
    \   swap(nodes[x].child[0], nodes[x].child[1]);\n            swap(nodes[x].path[0],\
    \ nodes[x].path[1]);\n            nodes[x].reverse = false;\n        }\n    }\n\
    \n    void pushUp(int x) {\n        auto [l, r] = nodes[x].child;\n        pushDown(l);\
    \ pushDown(r);\n\n        nodes[x].path[0] = nodes[l].path[0] + nodes[x].self\
    \ + nodes[r].path[0];\n        nodes[x].path[1] = nodes[r].path[1] + nodes[x].self\
    \ + nodes[l].path[1];\n\n        nodes[x].sub = nodes[x].vir + nodes[l].sub +\
    \ nodes[r].sub + nodes[x].self;\n    }\n\n    void setChild(int x, int y, int\
    \ dir) {\n        nodes[x].child[dir] = y;\n        nodes[y].parent = x;\n   \
    \     pushUp(x);\n    }\n};\n// }}}\n\nstruct LinkCut : SplayTree {\n    LinkCut(int\
    \ n) : SplayTree(n) {}\n\n    bool is_connected(int u, int v) {\n        return\
    \ LCA(u, v) > 0;\n    }\n\n    void link(int u, int v) {\n        reroot(u);\n\
    \        access(v);\n\n        nodes[v].vir = nodes[v].vir + nodes[u].sub;\n \
    \       nodes[u].parent = v;\n        pushUp(v);\n    }\n\n    void cut(int u,\
    \ int v) {\n        reroot(u);\n        access(v);\n\n        nodes[v].child[0]\
    \ = nodes[u].parent = 0;\n        pushUp(v);\n    }\n\n    // Returns 0 if u and\
    \ v are not connected\n    int LCA(int u, int v) {\n        if (u == v) return\
    \ u;\n        access(u);\n        int ret = access(v);\n        return nodes[u].parent\
    \ ? ret : 0;\n    }\n\n    T getPath(int u, int v) {\n        reroot(u);\n   \
    \     access(v);\n        return nodes[v].path[1];\n    }\n\n    void set(int\
    \ u, T val) {\n        access(u);\n        nodes[u].self = val;\n        pushUp(u);\n\
    \    }\n\n    T get(int u) {\n        return nodes[u].self;\n    }\n\n    // Get\
    \ aggregate of subtree(u). v is parent of u. There must exist edge(v, u) (?)\n\
    \    T getSubtree(int u, int v) {\n        reroot(v); access(u);\n        return\
    \ nodes[u].vir + nodes[u].self;\n    }\n\n// private:\n    void reroot(int x)\
    \ {\n        access(x);\n        nodes[x].reverse ^= 1;\n        pushDown(x);\n\
    \    }\n\n    int access(int x) {\n        int u = x, v = 0;\n        for (; u;\
    \ v = u, u = nodes[u].parent) {\n            splay(u);\n            int& ov =\
    \ nodes[u].child[1];\n            nodes[u].vir = nodes[u].vir + nodes[ov].sub;\n\
    #ifndef PATH_QUERIES_ONLY\n            // T requires subtract for subtree queries\n\
    \            nodes[u].vir -= nodes[v].sub;\n#endif\n\n            ov = v; pushUp(u);\n\
    \        }\n        return splay(x), v;\n    }\n};\n// }}}\n\n//Example Code\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing T = long long;\n#include\
    \ \"../LinkCutTree.h\"\n\n#define FOR(i, a, b) for (int i = (a), _##i = (b); i\
    \ <= _##i; ++i)\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\
    \nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\n    int n, q;\
    \ cin >> n >> q;\n    LinkCut tree(n);\n    FOR(i,1,n) {\n        int x; cin >>\
    \ x;\n        tree.set(i, x);\n    }\n    REP(i,n-1) {\n        int u, v; cin\
    \ >> u >> v;\n        ++u; ++v;\n        tree.link(u, v);\n    }\n\n    while\
    \ (q--) {\n        int typ; cin >> typ;\n        if (typ == 0) {  // delete (u,\
    \ v), add(w, x)\n            int u, v, w, x; cin >> u >> v >> w >> x;\n      \
    \      ++u; ++v;\n            ++w; ++x;\n            tree.cut(u, v);\n       \
    \     tree.link(w, x);\n        } else if (typ == 1) {  // a[p] += x\n       \
    \     int p, x; cin >> p >> x;\n            ++p;\n            tree.set(p, tree.get(p)\
    \ + x);\n        } else if (typ == 2) {  // get sum of subtree(u). v is parent\
    \ of u\n            int u, v; cin >> u >> v;\n            ++u; ++v;\n        \
    \    cout << tree.getSubtree(u, v) << '\\n';\n        }\n    }\n    return 0;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Data Structrue/LinkCutTree.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structrue/LinkCutTree.cpp
layout: document
redirect_from:
- /library/Data Structrue/LinkCutTree.cpp
- /library/Data Structrue/LinkCutTree.cpp.html
title: Data Structrue/LinkCutTree.cpp
---
