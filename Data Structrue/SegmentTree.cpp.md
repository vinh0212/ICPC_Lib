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
  bundledCode: "#line 1 \"Data Structrue/SegmentTree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntypedef vector<int> vi;\n\nclass SegmentTree\n{\nprivate:\n\
    \    int n;          // n = (int)A.size()\n    vi A, st, lazy; // the arrays\n\
    \n    int lc(int p) { return p << 1; }       // go to left child\n    int rc(int\
    \ p) { return (p << 1) + 1; } // go to right child\n\n    int conquer(int a, int\
    \ b)\n    {\n        if (a == -1)\n            return b; // corner case\n    \
    \    if (b == -1)\n            return a;\n        return min(a, b); // choose\
    \ type of query here, maybe max, sum, etc\n    }\n\n    void build(int p, int\
    \ l, int r)\n    { // O(n)\n        if (l == r)\n            st[p] = A[l]; //\
    \ base case\n        else\n        {\n            int mid = (l + r) / 2;\n   \
    \         build(lc(p), l, mid);\n            build(rc(p), mid + 1, r);\n     \
    \       st[p] = conquer(st[lc(p)], st[rc(p)]);\n        }\n    }\n\n    void propagate(int\
    \ p, int l, int r)\n    {\n        if (lazy[p] != -1)\n        {             \
    \                             // has a lazy flag\n            st[p] = lazy[p];\
    \                       // [l..r] has same value\n            if (l != r)    \
    \                        // not a leaf\n                lazy[lc(p)] = lazy[rc(p)]\
    \ = lazy[p]; // propagate downwards\n            else                        \
    \           // l == r, a single index\n                A[l] = lazy[p];       \
    \             // time to update this\n            lazy[p] = -1;              \
    \            // erase lazy flag\n        }\n    }\n\n    int query(int p, int\
    \ l, int r, int i, int j)\n    {                       // O(log n)\n        propagate(p,\
    \ l, r); // lazy propagation\n        if (i > j)\n            return -1; // infeasible\n\
    \        if ((l >= i) && (r <= j))\n            return st[p]; // found the segment\n\
    \        int mid = (l + r) / 2;\n        return conquer(query(lc(p), l, mid, i,\
    \ min(mid, j)),\n                       query(rc(p), mid + 1, r, max(i, mid +\
    \ 1), j));\n    }\n\n    void update(int p, int l, int r, int i, int j, int val)\n\
    \    {                       // O(log n)\n        propagate(p, l, r); // lazy\
    \ propagation\n        if (i > j)\n            return;\n        if ((l >= i) &&\
    \ (r <= j)) //[l,r] in [i,j]\n        {                       // found the segment\n\
    \            lazy[p] = val;      // update this\n            propagate(p, l, r);\
    \ // lazy propagation\n        }\n        else\n        {\n            int mid\
    \ = (l + r) / 2;\n            update(lc(p), l, mid, i, min(mid, j), val);\n  \
    \          update(rc(p), mid + 1, r, max(i, mid + 1), j, val);\n            int\
    \ lsubtree, rsubtree;\n            if (lazy[lc(p)] != -1)\n                lsubtree\
    \ = lazy[lc(p)];\n            else\n                lsubtree = st[lc(p)];\n  \
    \          if (lazy[rc(p)] != -1)\n                rsubtree = lazy[rc(p)];\n \
    \           else\n                rsubtree = st[rc(p)];\n            st[p] = conquer(lsubtree,\
    \ rsubtree);\n        }\n    }\n\npublic:\n    SegmentTree(int sz) : n(sz), A(n),\
    \ st(4 * n), lazy(4 * n, -1) {}\n\n    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size())\n\
    \    {\n        A = initialA;\n        build(1, 0, n - 1);\n    }\n\n    void\
    \ update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }\n\n    int\
    \ query(int i, int j) { return query(1, 0, n - 1, i, j); }\n};\n\n// Example Code\n\
    \nint main()\n{\n    vi A = {18, 17, 13, 19, 15, 11, 20, 99}; // make n a power\
    \ of 2\n    SegmentTree st(A);\n\n    cout << \"              idx    0, 1, 2,\
    \ 3, 4, 5, 6, 7\" << endl;\n    cout << \"              A is {18,17,13,19,15,11,20,oo}\"\
    \ << endl;\n    cout << \"query(1, 3) = \" << st.query(1, 3) << endl; // 13\n\
    \    cout << \"query(4, 7) = \" << st.query(4, 7) << endl; // 11\n    cout <<\
    \ \"query(3, 4) = \" << st.query(3, 4) << endl; // 15\n\n    st.update(5, 5, 77);\
    \ // update A[5] to 77\n    cout << \"              idx    0, 1, 2, 3, 4, 5, 6,\
    \ 7\" << endl;\n    cout << \"Now, modify A into {18,17,13,19,15,77,20,oo}\" <<\
    \ endl;\n    cout << \"query(1, 3) = \" << st.query(1, 3) << endl; // remains\
    \ 13\n    cout << \"query(4, 7) = \" << st.query(4, 7) << endl; // now 15\n  \
    \  cout << \"query(3, 4) = \" << st.query(3, 4) << endl; // remains 15\n\n   \
    \ st.update(0, 3, 30); // update A[0..3] to 30\n    cout << \"              idx\
    \    0, 1, 2, 3, 4, 5, 6, 7\" << endl;\n    cout << \"Now, modify A into {30,30,30,30,15,77,20,oo}\"\
    \ << endl;\n    cout << \"query(1, 3) = \" << st.query(1, 3) << endl; // now 30\n\
    \    cout << \"query(4, 7) = \" << st.query(4, 7) << endl; // remains 15\n   \
    \ cout << \"query(3, 4) = \" << st.query(3, 4) << endl; // remains 15\n\n    st.update(3,\
    \ 3, 7); // update A[3] to 7\n    cout << \"              idx    0, 1, 2, 3, 4,\
    \ 5, 6, 7\" << endl;\n    cout << \"Now, modify A into {30,30,30, 7,15,77,20,oo}\"\
    \ << endl;\n    cout << \"query(1, 3) = \" << st.query(1, 3) << endl; // now 7\n\
    \    cout << \"query(4, 7) = \" << st.query(4, 7) << endl; // remains 15\n   \
    \ cout << \"query(3, 4) = \" << st.query(3, 4) << endl; // now 7\n\n    return\
    \ 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntypedef vector<int> vi;\n\
    \nclass SegmentTree\n{\nprivate:\n    int n;          // n = (int)A.size()\n \
    \   vi A, st, lazy; // the arrays\n\n    int lc(int p) { return p << 1; }    \
    \   // go to left child\n    int rc(int p) { return (p << 1) + 1; } // go to right\
    \ child\n\n    int conquer(int a, int b)\n    {\n        if (a == -1)\n      \
    \      return b; // corner case\n        if (b == -1)\n            return a;\n\
    \        return min(a, b); // choose type of query here, maybe max, sum, etc\n\
    \    }\n\n    void build(int p, int l, int r)\n    { // O(n)\n        if (l ==\
    \ r)\n            st[p] = A[l]; // base case\n        else\n        {\n      \
    \      int mid = (l + r) / 2;\n            build(lc(p), l, mid);\n           \
    \ build(rc(p), mid + 1, r);\n            st[p] = conquer(st[lc(p)], st[rc(p)]);\n\
    \        }\n    }\n\n    void propagate(int p, int l, int r)\n    {\n        if\
    \ (lazy[p] != -1)\n        {                                          // has a\
    \ lazy flag\n            st[p] = lazy[p];                       // [l..r] has\
    \ same value\n            if (l != r)                            // not a leaf\n\
    \                lazy[lc(p)] = lazy[rc(p)] = lazy[p]; // propagate downwards\n\
    \            else                                   // l == r, a single index\n\
    \                A[l] = lazy[p];                    // time to update this\n \
    \           lazy[p] = -1;                          // erase lazy flag\n      \
    \  }\n    }\n\n    int query(int p, int l, int r, int i, int j)\n    {       \
    \                // O(log n)\n        propagate(p, l, r); // lazy propagation\n\
    \        if (i > j)\n            return -1; // infeasible\n        if ((l >= i)\
    \ && (r <= j))\n            return st[p]; // found the segment\n        int mid\
    \ = (l + r) / 2;\n        return conquer(query(lc(p), l, mid, i, min(mid, j)),\n\
    \                       query(rc(p), mid + 1, r, max(i, mid + 1), j));\n    }\n\
    \n    void update(int p, int l, int r, int i, int j, int val)\n    {         \
    \              // O(log n)\n        propagate(p, l, r); // lazy propagation\n\
    \        if (i > j)\n            return;\n        if ((l >= i) && (r <= j)) //[l,r]\
    \ in [i,j]\n        {                       // found the segment\n           \
    \ lazy[p] = val;      // update this\n            propagate(p, l, r); // lazy\
    \ propagation\n        }\n        else\n        {\n            int mid = (l +\
    \ r) / 2;\n            update(lc(p), l, mid, i, min(mid, j), val);\n         \
    \   update(rc(p), mid + 1, r, max(i, mid + 1), j, val);\n            int lsubtree,\
    \ rsubtree;\n            if (lazy[lc(p)] != -1)\n                lsubtree = lazy[lc(p)];\n\
    \            else\n                lsubtree = st[lc(p)];\n            if (lazy[rc(p)]\
    \ != -1)\n                rsubtree = lazy[rc(p)];\n            else\n        \
    \        rsubtree = st[rc(p)];\n            st[p] = conquer(lsubtree, rsubtree);\n\
    \        }\n    }\n\npublic:\n    SegmentTree(int sz) : n(sz), A(n), st(4 * n),\
    \ lazy(4 * n, -1) {}\n\n    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size())\n\
    \    {\n        A = initialA;\n        build(1, 0, n - 1);\n    }\n\n    void\
    \ update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }\n\n    int\
    \ query(int i, int j) { return query(1, 0, n - 1, i, j); }\n};\n\n// Example Code\n\
    \nint main()\n{\n    vi A = {18, 17, 13, 19, 15, 11, 20, 99}; // make n a power\
    \ of 2\n    SegmentTree st(A);\n\n    cout << \"              idx    0, 1, 2,\
    \ 3, 4, 5, 6, 7\" << endl;\n    cout << \"              A is {18,17,13,19,15,11,20,oo}\"\
    \ << endl;\n    cout << \"query(1, 3) = \" << st.query(1, 3) << endl; // 13\n\
    \    cout << \"query(4, 7) = \" << st.query(4, 7) << endl; // 11\n    cout <<\
    \ \"query(3, 4) = \" << st.query(3, 4) << endl; // 15\n\n    st.update(5, 5, 77);\
    \ // update A[5] to 77\n    cout << \"              idx    0, 1, 2, 3, 4, 5, 6,\
    \ 7\" << endl;\n    cout << \"Now, modify A into {18,17,13,19,15,77,20,oo}\" <<\
    \ endl;\n    cout << \"query(1, 3) = \" << st.query(1, 3) << endl; // remains\
    \ 13\n    cout << \"query(4, 7) = \" << st.query(4, 7) << endl; // now 15\n  \
    \  cout << \"query(3, 4) = \" << st.query(3, 4) << endl; // remains 15\n\n   \
    \ st.update(0, 3, 30); // update A[0..3] to 30\n    cout << \"              idx\
    \    0, 1, 2, 3, 4, 5, 6, 7\" << endl;\n    cout << \"Now, modify A into {30,30,30,30,15,77,20,oo}\"\
    \ << endl;\n    cout << \"query(1, 3) = \" << st.query(1, 3) << endl; // now 30\n\
    \    cout << \"query(4, 7) = \" << st.query(4, 7) << endl; // remains 15\n   \
    \ cout << \"query(3, 4) = \" << st.query(3, 4) << endl; // remains 15\n\n    st.update(3,\
    \ 3, 7); // update A[3] to 7\n    cout << \"              idx    0, 1, 2, 3, 4,\
    \ 5, 6, 7\" << endl;\n    cout << \"Now, modify A into {30,30,30, 7,15,77,20,oo}\"\
    \ << endl;\n    cout << \"query(1, 3) = \" << st.query(1, 3) << endl; // now 7\n\
    \    cout << \"query(4, 7) = \" << st.query(4, 7) << endl; // remains 15\n   \
    \ cout << \"query(3, 4) = \" << st.query(3, 4) << endl; // now 7\n\n    return\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Data Structrue/SegmentTree.cpp
  requiredBy: []
  timestamp: '2024-11-07 11:32:23+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structrue/SegmentTree.cpp
layout: document
redirect_from:
- /library/Data Structrue/SegmentTree.cpp
- /library/Data Structrue/SegmentTree.cpp.html
title: Data Structrue/SegmentTree.cpp
---
