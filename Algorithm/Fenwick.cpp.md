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
  bundledCode: "#line 1 \"Algorithm/Fenwick.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define LSOne(S) ((S) & -(S))                    // the key\
    \ operation\n\ntypedef long long ll;                            // for extra flexibility\n\
    typedef vector<ll> vll;\ntypedef vector<int> vi;\n\nclass FenwickTree {      \
    \                        // index 0 is not used\nprivate:\n  vll ft;         \
    \                               // internal FT is an array\npublic:\n  FenwickTree(int\
    \ m) { ft.assign(m + 1, 0); }    // create an empty FT\n\n  void build(const vll\
    \ &f) {\n    int m = (int)f.size() - 1;                   // note f[0] is always\
    \ 0\n    ft.assign(m + 1, 0);\n    for (int i = 1; i <= m; ++i) {            \
    \   // O(m)\n      ft[i] += f[i];                             // add this value\n\
    \      if (i + LSOne(i) <= m)                     // i has parent\n        ft[i\
    \ + LSOne(i)] += ft[i];               // add to that parent\n    }\n  }\n\n  FenwickTree(const\
    \ vll &f) { build(f); }        // create FT based on f\n\n  FenwickTree(int m,\
    \ const vi &s) {              // create FT based on s\n    vll f(m + 1, 0);\n\
    \    for (int i = 0; i < (int)s.size(); ++i)      // do the conversion first\n\
    \      ++f[s[i]];                                 // in O(n)\n    build(f);  \
    \                                  // in O(m)\n  }\n\n  ll rsq(int j) {      \
    \                          // returns RSQ(1, j)\n    ll sum = 0;\n    for (; j;\
    \ j -= LSOne(j))\n      sum += ft[j];\n    return sum;\n  }\n\n  ll rsq(int i,\
    \ int j) { return rsq(j) - rsq(i - 1); } // inc/exclusion\n\n  // updates value\
    \ of the i-th element by v (v can be +ve/inc or -ve/dec)\n  void update(int i,\
    \ ll v) {\n    for (; i < (int)ft.size(); i += LSOne(i))\n      ft[i] += v;\n\
    \  }\n\n  int select(ll k) {                             // O(log m)\n    int\
    \ p = 1;\n    while (p * 2 < (int)ft.size()) p *= 2;\n    int i = 0;\n    while\
    \ (p) {\n      if (k > ft[i + p]) {\n        k -= ft[i + p];\n        i += p;\n\
    \      }\n      p /= 2;\n    }\n    return i + 1;\n  }\n};\n\nclass RUPQ {   \
    \                                  // RUPQ variant - range update, point query\n\
    private:\n  FenwickTree ft;                                // internally use PURQ\
    \ FT\npublic:\n  RUPQ(int m) : ft(FenwickTree(m)) {}\n  void range_update(int\
    \ ui, int uj, ll v) {\n    ft.update(ui, v);                            // [ui,\
    \ ui+1, .., m] +v\n    ft.update(uj + 1, -v);                       // [uj+1,\
    \ uj+2, .., m] -v\n  }                                              // [ui, ui+1,\
    \ .., uj] +v\n  ll point_query(int i) { return ft.rsq(i); }    // rsq(i) is sufficient\n\
    };\n\nclass RURQ  {                                    // RURQ variant - range\
    \ update, range query\nprivate:                                         // needs\
    \ two helper FTs\n  RUPQ rupq;                                     // one RUPQ\
    \ and\n  FenwickTree purq;                              // one PURQ\npublic:\n\
    \  RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {} // initialization\n  void\
    \ range_update(int ui, int uj, ll v) {\n    rupq.range_update(ui, uj, v);    \
    \            // [ui, ui+1, .., uj] +v\n    purq.update(ui, v * (ui - 1));    \
    \           // -(ui-1)*v before ui\n    purq.update(uj + 1, -v * uj);        \
    \        // +(uj-ui+1)*v after uj\n  }\n  ll rsq(int j) {\n    return rupq.point_query(j)\
    \ * j -             // optimistic calculation\n           purq.rsq(j);       \
    \                   // cancelation factor\n  }\n  ll rsq(int i, int j) { return\
    \ rsq(j) - rsq(i - 1); } // standard\n};\n\n//Example code\nint main() {\n  vll\
    \ f = {0, 0, 1, 0, 1, 2, 3, 2, 1, 1, 0};     // index 0 is always 0\n  FenwickTree\
    \ ft(f);\n  printf(\"%lld\\n\", ft.rsq(1, 6)); // 7 => ft[6]+ft[4] = 5+2 = 7\n\
    \  printf(\"%d\\n\", ft.select(7)); // index 6, rsq(1, 6) == 7, which is >= 7\n\
    \  ft.update(5, 1); // update demo\n  printf(\"%lld\\n\", ft.rsq(1, 10)); // now\
    \ 12\n  printf(\"=====\\n\");\n  RUPQ rupq(10);\n  RURQ rurq(10);\n  rupq.range_update(2,\
    \ 9, 7); // indices in [2, 3, .., 9] updated by +7\n  rurq.range_update(2, 9,\
    \ 7); // same as rupq above\n  rupq.range_update(6, 7, 3); // indices 6&7 are\
    \ further updated by +3 (10)\n  rurq.range_update(6, 7, 3); // same as rupq above\n\
    \  // idx = 0 (unused) | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10\n  // val = - \
    \         | 0 | 7 | 7 | 7 | 7 |10 |10 | 7 | 7 | 0\n  for (int i = 1; i <= 10;\
    \ i++)\n    printf(\"%d -> %lld\\n\", i, rupq.point_query(i));\n  printf(\"RSQ(1,\
    \ 10) = %lld\\n\", rurq.rsq(1, 10)); // 62\n  printf(\"RSQ(6, 7) = %lld\\n\",\
    \ rurq.rsq(6, 7)); // 20\n  return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define LSOne(S) ((S) &\
    \ -(S))                    // the key operation\n\ntypedef long long ll;     \
    \                       // for extra flexibility\ntypedef vector<ll> vll;\ntypedef\
    \ vector<int> vi;\n\nclass FenwickTree {                              // index\
    \ 0 is not used\nprivate:\n  vll ft;                                        //\
    \ internal FT is an array\npublic:\n  FenwickTree(int m) { ft.assign(m + 1, 0);\
    \ }    // create an empty FT\n\n  void build(const vll &f) {\n    int m = (int)f.size()\
    \ - 1;                   // note f[0] is always 0\n    ft.assign(m + 1, 0);\n\
    \    for (int i = 1; i <= m; ++i) {               // O(m)\n      ft[i] += f[i];\
    \                             // add this value\n      if (i + LSOne(i) <= m)\
    \                     // i has parent\n        ft[i + LSOne(i)] += ft[i];    \
    \           // add to that parent\n    }\n  }\n\n  FenwickTree(const vll &f) {\
    \ build(f); }        // create FT based on f\n\n  FenwickTree(int m, const vi\
    \ &s) {              // create FT based on s\n    vll f(m + 1, 0);\n    for (int\
    \ i = 0; i < (int)s.size(); ++i)      // do the conversion first\n      ++f[s[i]];\
    \                                 // in O(n)\n    build(f);                  \
    \                  // in O(m)\n  }\n\n  ll rsq(int j) {                      \
    \          // returns RSQ(1, j)\n    ll sum = 0;\n    for (; j; j -= LSOne(j))\n\
    \      sum += ft[j];\n    return sum;\n  }\n\n  ll rsq(int i, int j) { return\
    \ rsq(j) - rsq(i - 1); } // inc/exclusion\n\n  // updates value of the i-th element\
    \ by v (v can be +ve/inc or -ve/dec)\n  void update(int i, ll v) {\n    for (;\
    \ i < (int)ft.size(); i += LSOne(i))\n      ft[i] += v;\n  }\n\n  int select(ll\
    \ k) {                             // O(log m)\n    int p = 1;\n    while (p *\
    \ 2 < (int)ft.size()) p *= 2;\n    int i = 0;\n    while (p) {\n      if (k >\
    \ ft[i + p]) {\n        k -= ft[i + p];\n        i += p;\n      }\n      p /=\
    \ 2;\n    }\n    return i + 1;\n  }\n};\n\nclass RUPQ {                      \
    \               // RUPQ variant - range update, point query\nprivate:\n  FenwickTree\
    \ ft;                                // internally use PURQ FT\npublic:\n  RUPQ(int\
    \ m) : ft(FenwickTree(m)) {}\n  void range_update(int ui, int uj, ll v) {\n  \
    \  ft.update(ui, v);                            // [ui, ui+1, .., m] +v\n    ft.update(uj\
    \ + 1, -v);                       // [uj+1, uj+2, .., m] -v\n  }             \
    \                                 // [ui, ui+1, .., uj] +v\n  ll point_query(int\
    \ i) { return ft.rsq(i); }    // rsq(i) is sufficient\n};\n\nclass RURQ  {   \
    \                                 // RURQ variant - range update, range query\n\
    private:                                         // needs two helper FTs\n  RUPQ\
    \ rupq;                                     // one RUPQ and\n  FenwickTree purq;\
    \                              // one PURQ\npublic:\n  RURQ(int m) : rupq(RUPQ(m)),\
    \ purq(FenwickTree(m)) {} // initialization\n  void range_update(int ui, int uj,\
    \ ll v) {\n    rupq.range_update(ui, uj, v);                // [ui, ui+1, ..,\
    \ uj] +v\n    purq.update(ui, v * (ui - 1));               // -(ui-1)*v before\
    \ ui\n    purq.update(uj + 1, -v * uj);                // +(uj-ui+1)*v after uj\n\
    \  }\n  ll rsq(int j) {\n    return rupq.point_query(j) * j -             // optimistic\
    \ calculation\n           purq.rsq(j);                          // cancelation\
    \ factor\n  }\n  ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); } // standard\n\
    };\n\n//Example code\nint main() {\n  vll f = {0, 0, 1, 0, 1, 2, 3, 2, 1, 1, 0};\
    \     // index 0 is always 0\n  FenwickTree ft(f);\n  printf(\"%lld\\n\", ft.rsq(1,\
    \ 6)); // 7 => ft[6]+ft[4] = 5+2 = 7\n  printf(\"%d\\n\", ft.select(7)); // index\
    \ 6, rsq(1, 6) == 7, which is >= 7\n  ft.update(5, 1); // update demo\n  printf(\"\
    %lld\\n\", ft.rsq(1, 10)); // now 12\n  printf(\"=====\\n\");\n  RUPQ rupq(10);\n\
    \  RURQ rurq(10);\n  rupq.range_update(2, 9, 7); // indices in [2, 3, .., 9] updated\
    \ by +7\n  rurq.range_update(2, 9, 7); // same as rupq above\n  rupq.range_update(6,\
    \ 7, 3); // indices 6&7 are further updated by +3 (10)\n  rurq.range_update(6,\
    \ 7, 3); // same as rupq above\n  // idx = 0 (unused) | 1 | 2 | 3 | 4 | 5 | 6\
    \ | 7 | 8 | 9 |10\n  // val = -          | 0 | 7 | 7 | 7 | 7 |10 |10 | 7 | 7 |\
    \ 0\n  for (int i = 1; i <= 10; i++)\n    printf(\"%d -> %lld\\n\", i, rupq.point_query(i));\n\
    \  printf(\"RSQ(1, 10) = %lld\\n\", rurq.rsq(1, 10)); // 62\n  printf(\"RSQ(6,\
    \ 7) = %lld\\n\", rurq.rsq(6, 7)); // 20\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/Fenwick.cpp
  requiredBy: []
  timestamp: '2024-11-07 00:17:58+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/Fenwick.cpp
layout: document
redirect_from:
- /library/Algorithm/Fenwick.cpp
- /library/Algorithm/Fenwick.cpp.html
title: Algorithm/Fenwick.cpp
---
