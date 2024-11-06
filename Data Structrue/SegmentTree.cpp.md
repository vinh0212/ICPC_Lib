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
    using namespace std;\n\ntypedef vector<int> vi;\n\nclass SegmentTree {       \
    \                       // OOP style\nprivate:\n  int n;                     \
    \                    // n = (int)A.size()\n  vi A, st, lazy;                 \
    \               // the arrays\n\n  int l(int p) { return  p<<1; }            \
    \     // go to left child\n  int r(int p) { return (p<<1)+1; }              //\
    \ go to right child\n\n  int conquer(int a, int b) {\n    if (a == -1) return\
    \ b;                       // corner case\n    if (b == -1) return a;\n    return\
    \ min(a, b);                            // RMQ\n  }\n\n  void build(int p, int\
    \ L, int R) {              // O(n)\n    if (L == R)\n      st[p] = A[L];     \
    \                         // base case\n    else {\n      int m = (L+R)/2;\n \
    \     build(l(p), L  , m);\n      build(r(p), m+1, R);\n      st[p] = conquer(st[l(p)],\
    \ st[r(p)]);\n    }\n  }\n\n  void propagate(int p, int L, int R) {\n    if (lazy[p]\
    \ != -1) {                         // has a lazy flag\n      st[p] = lazy[p];\
    \                           // [L..R] has same value\n      if (L != R)      \
    \                          // not a leaf\n        lazy[l(p)] = lazy[r(p)] = lazy[p];\
    \       // propagate downwards\n      else                                   \
    \    // L == R, a single index\n        A[L] = lazy[p];                      \
    \    // time to update this\n      lazy[p] = -1;                             \
    \ // erase lazy flag\n    }\n  }\n\n  int RMQ(int p, int L, int R, int i, int\
    \ j) {   // O(log n)\n    propagate(p, L, R);                          // lazy\
    \ propagation\n    if (i > j) return -1;                        // infeasible\n\
    \    if ((L >= i) && (R <= j)) return st[p];      // found the segment\n    int\
    \ m = (L+R)/2;\n    return conquer(RMQ(l(p), L  , m, i          , min(m, j)),\n\
    \                   RMQ(r(p), m+1, R, max(i, m+1), j        ));\n  }\n\n  void\
    \ update(int p, int L, int R, int i, int j, int val) { // O(log n)\n    propagate(p,\
    \ L, R);                          // lazy propagation\n    if (i > j) return;\n\
    \    if ((L >= i) && (R <= j)) {                  // found the segment\n     \
    \ lazy[p] = val;                             // update this\n      propagate(p,\
    \ L, R);                        // lazy propagation\n    }\n    else {\n     \
    \ int m = (L+R)/2;\n      update(l(p), L  , m, i          , min(m, j), val);\n\
    \      update(r(p), m+1, R, max(i, m+1), j        , val);\n      int lsubtree\
    \ = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];\n      int rsubtree = (lazy[r(p)]\
    \ != -1) ? lazy[r(p)] : st[r(p)];\n      st[p] = conquer(lsubtree, rsubtree);\n\
    \    }\n  }\n\npublic:\n  SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n,\
    \ -1) {}\n\n  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size())\
    \ {\n    A = initialA;\n    build(1, 0, n-1);\n  }\n\n  void update(int i, int\
    \ j, int val) { update(1, 0, n-1, i, j, val); }\n\n  int RMQ(int i, int j) { return\
    \ RMQ(1, 0, n-1, i, j); }\n};\n\n//Example Code\n\nint main() {\n  vi A = {18,\
    \ 17, 13, 19, 15, 11, 20, 99};       // make n a power of 2\n  SegmentTree st(A);\n\
    \n  printf(\"              idx    0, 1, 2, 3, 4, 5, 6, 7\\n\");\n  printf(\" \
    \             A is {18,17,13,19,15,11,20,oo}\\n\");\n  printf(\"RMQ(1, 3) = %d\\\
    n\", st.RMQ(1, 3));      // 13\n  printf(\"RMQ(4, 7) = %d\\n\", st.RMQ(4, 7));\
    \      // 11\n  printf(\"RMQ(3, 4) = %d\\n\", st.RMQ(3, 4));      // 15\n\n  st.update(5,\
    \ 5, 77);                           // update A[5] to 77\n  printf(\"        \
    \      idx    0, 1, 2, 3, 4, 5, 6, 7\\n\");\n  printf(\"Now, modify A into {18,17,13,19,15,77,20,oo}\\\
    n\");\n  printf(\"RMQ(1, 3) = %d\\n\", st.RMQ(1, 3));      // remains 13\n  printf(\"\
    RMQ(4, 7) = %d\\n\", st.RMQ(4, 7));      // now 15\n  printf(\"RMQ(3, 4) = %d\\\
    n\", st.RMQ(3, 4));      // remains 15\n\n  st.update(0, 3, 30);             \
    \              // update A[0..3] to 30\n  printf(\"              idx    0, 1,\
    \ 2, 3, 4, 5, 6, 7\\n\");\n  printf(\"Now, modify A into {30,30,30,30,15,77,20,oo}\\\
    n\");\n  printf(\"RMQ(1, 3) = %d\\n\", st.RMQ(1, 3));      // now 30\n  printf(\"\
    RMQ(4, 7) = %d\\n\", st.RMQ(4, 7));      // remains 15\n  printf(\"RMQ(3, 4) =\
    \ %d\\n\", st.RMQ(3, 4));      // remains 15\n\n  st.update(3, 3, 7);        \
    \                    // update A[3] to 7\n  printf(\"              idx    0, 1,\
    \ 2, 3, 4, 5, 6, 7\\n\");\n  printf(\"Now, modify A into {30,30,30, 7,15,77,20,oo}\\\
    n\");\n  printf(\"RMQ(1, 3) = %d\\n\", st.RMQ(1, 3));      // now 7\n  printf(\"\
    RMQ(4, 7) = %d\\n\", st.RMQ(4, 7));      // remains 15\n  printf(\"RMQ(3, 4) =\
    \ %d\\n\", st.RMQ(3, 4));      // now 7\n\n  return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntypedef vector<int> vi;\n\
    \nclass SegmentTree {                              // OOP style\nprivate:\n  int\
    \ n;                                         // n = (int)A.size()\n  vi A, st,\
    \ lazy;                                // the arrays\n\n  int l(int p) { return\
    \  p<<1; }                 // go to left child\n  int r(int p) { return (p<<1)+1;\
    \ }              // go to right child\n\n  int conquer(int a, int b) {\n    if\
    \ (a == -1) return b;                       // corner case\n    if (b == -1) return\
    \ a;\n    return min(a, b);                            // RMQ\n  }\n\n  void build(int\
    \ p, int L, int R) {              // O(n)\n    if (L == R)\n      st[p] = A[L];\
    \                              // base case\n    else {\n      int m = (L+R)/2;\n\
    \      build(l(p), L  , m);\n      build(r(p), m+1, R);\n      st[p] = conquer(st[l(p)],\
    \ st[r(p)]);\n    }\n  }\n\n  void propagate(int p, int L, int R) {\n    if (lazy[p]\
    \ != -1) {                         // has a lazy flag\n      st[p] = lazy[p];\
    \                           // [L..R] has same value\n      if (L != R)      \
    \                          // not a leaf\n        lazy[l(p)] = lazy[r(p)] = lazy[p];\
    \       // propagate downwards\n      else                                   \
    \    // L == R, a single index\n        A[L] = lazy[p];                      \
    \    // time to update this\n      lazy[p] = -1;                             \
    \ // erase lazy flag\n    }\n  }\n\n  int RMQ(int p, int L, int R, int i, int\
    \ j) {   // O(log n)\n    propagate(p, L, R);                          // lazy\
    \ propagation\n    if (i > j) return -1;                        // infeasible\n\
    \    if ((L >= i) && (R <= j)) return st[p];      // found the segment\n    int\
    \ m = (L+R)/2;\n    return conquer(RMQ(l(p), L  , m, i          , min(m, j)),\n\
    \                   RMQ(r(p), m+1, R, max(i, m+1), j        ));\n  }\n\n  void\
    \ update(int p, int L, int R, int i, int j, int val) { // O(log n)\n    propagate(p,\
    \ L, R);                          // lazy propagation\n    if (i > j) return;\n\
    \    if ((L >= i) && (R <= j)) {                  // found the segment\n     \
    \ lazy[p] = val;                             // update this\n      propagate(p,\
    \ L, R);                        // lazy propagation\n    }\n    else {\n     \
    \ int m = (L+R)/2;\n      update(l(p), L  , m, i          , min(m, j), val);\n\
    \      update(r(p), m+1, R, max(i, m+1), j        , val);\n      int lsubtree\
    \ = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];\n      int rsubtree = (lazy[r(p)]\
    \ != -1) ? lazy[r(p)] : st[r(p)];\n      st[p] = conquer(lsubtree, rsubtree);\n\
    \    }\n  }\n\npublic:\n  SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n,\
    \ -1) {}\n\n  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size())\
    \ {\n    A = initialA;\n    build(1, 0, n-1);\n  }\n\n  void update(int i, int\
    \ j, int val) { update(1, 0, n-1, i, j, val); }\n\n  int RMQ(int i, int j) { return\
    \ RMQ(1, 0, n-1, i, j); }\n};\n\n//Example Code\n\nint main() {\n  vi A = {18,\
    \ 17, 13, 19, 15, 11, 20, 99};       // make n a power of 2\n  SegmentTree st(A);\n\
    \n  printf(\"              idx    0, 1, 2, 3, 4, 5, 6, 7\\n\");\n  printf(\" \
    \             A is {18,17,13,19,15,11,20,oo}\\n\");\n  printf(\"RMQ(1, 3) = %d\\\
    n\", st.RMQ(1, 3));      // 13\n  printf(\"RMQ(4, 7) = %d\\n\", st.RMQ(4, 7));\
    \      // 11\n  printf(\"RMQ(3, 4) = %d\\n\", st.RMQ(3, 4));      // 15\n\n  st.update(5,\
    \ 5, 77);                           // update A[5] to 77\n  printf(\"        \
    \      idx    0, 1, 2, 3, 4, 5, 6, 7\\n\");\n  printf(\"Now, modify A into {18,17,13,19,15,77,20,oo}\\\
    n\");\n  printf(\"RMQ(1, 3) = %d\\n\", st.RMQ(1, 3));      // remains 13\n  printf(\"\
    RMQ(4, 7) = %d\\n\", st.RMQ(4, 7));      // now 15\n  printf(\"RMQ(3, 4) = %d\\\
    n\", st.RMQ(3, 4));      // remains 15\n\n  st.update(0, 3, 30);             \
    \              // update A[0..3] to 30\n  printf(\"              idx    0, 1,\
    \ 2, 3, 4, 5, 6, 7\\n\");\n  printf(\"Now, modify A into {30,30,30,30,15,77,20,oo}\\\
    n\");\n  printf(\"RMQ(1, 3) = %d\\n\", st.RMQ(1, 3));      // now 30\n  printf(\"\
    RMQ(4, 7) = %d\\n\", st.RMQ(4, 7));      // remains 15\n  printf(\"RMQ(3, 4) =\
    \ %d\\n\", st.RMQ(3, 4));      // remains 15\n\n  st.update(3, 3, 7);        \
    \                    // update A[3] to 7\n  printf(\"              idx    0, 1,\
    \ 2, 3, 4, 5, 6, 7\\n\");\n  printf(\"Now, modify A into {30,30,30, 7,15,77,20,oo}\\\
    n\");\n  printf(\"RMQ(1, 3) = %d\\n\", st.RMQ(1, 3));      // now 7\n  printf(\"\
    RMQ(4, 7) = %d\\n\", st.RMQ(4, 7));      // remains 15\n  printf(\"RMQ(3, 4) =\
    \ %d\\n\", st.RMQ(3, 4));      // now 7\n\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Data Structrue/SegmentTree.cpp
  requiredBy: []
  timestamp: '2024-11-07 00:17:58+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structrue/SegmentTree.cpp
layout: document
redirect_from:
- /library/Data Structrue/SegmentTree.cpp
- /library/Data Structrue/SegmentTree.cpp.html
title: Data Structrue/SegmentTree.cpp
---
