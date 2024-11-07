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
  bundledCode: "#line 1 \"Data Structrue/Fenwick.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define LSOne(S) ((S) & -(S)) // the key operation\n\n\
    typedef long long ll; // for extra flexibility\ntypedef vector<ll> vll;\ntypedef\
    \ vector<int> vi;\n\nclass FenwickTree\n{ // index 0 is not used\nprivate:\n\t\
    vll ft; // internal FT is an array\npublic:\n\tFenwickTree(int m) { ft.assign(m\
    \ + 1, 0); } // create an empty FT\n\n\tvoid build(const vll &f)\n\t{\n\t\tint\
    \ m = (int)f.size() - 1; // note f[0] is always 0\n\t\tft.assign(m + 1, 0);\n\t\
    \tfor (int i = 1; i <= m; ++i)\n\t\t{\t\t\t\t\t\t\t\t   // O(m)\n\t\t\tft[i] +=\
    \ f[i];\t\t\t\t   // add this value\n\t\t\tif (i + LSOne(i) <= m)\t\t   // i has\
    \ parent\n\t\t\t\tft[i + LSOne(i)] += ft[i]; // add to that parent\n\t\t}\n\t\
    }\n\n\tFenwickTree(const vll &f) { build(f); } // create FT based on f\n\n\tFenwickTree(int\
    \ m, const vi &s)\n\t{ // create FT based on s\n\t\tvll f(m + 1, 0);\n\t\tfor\
    \ (int i = 0; i < (int)s.size(); ++i) // do the conversion first\n\t\t\t++f[s[i]];\t\
    \t\t\t\t\t\t// in O(n)\n\t\tbuild(f);\t\t\t\t\t\t\t\t// in O(m)\n\t}\n\n\tll rsq(int\
    \ j)\n\t{ // returns RSQ(1, j)\n\t\tll sum = 0;\n\t\tfor (; j; j -= LSOne(j))\n\
    \t\t\tsum += ft[j];\n\t\treturn sum;\n\t}\n\n\tll rsq(int i, int j) { return rsq(j)\
    \ - rsq(i - 1); } // inc/exclusion\n\n\t// updates value of the i-th element by\
    \ v (v can be +ve/inc or -ve/dec)\n\tvoid update(int i, ll v)\n\t{\n\t\tfor (;\
    \ i < (int)ft.size(); i += LSOne(i))\n\t\t\tft[i] += v;\n\t}\n\n\tint select(ll\
    \ k)\n\t{ // O(log m)\n\t\tint p = 1;\n\t\twhile (p * 2 < (int)ft.size())\n\t\t\
    \tp *= 2;\n\t\tint i = 0;\n\t\twhile (p)\n\t\t{\n\t\t\tif (k > ft[i + p])\n\t\t\
    \t{\n\t\t\t\tk -= ft[i + p];\n\t\t\t\ti += p;\n\t\t\t}\n\t\t\tp /= 2;\n\t\t}\n\
    \t\treturn i + 1;\n\t}\n};\n\nclass RUPQ\n{ // RUPQ variant - range update, point\
    \ query\nprivate:\n\tFenwickTree ft; // internally use PURQ FT\npublic:\n\tRUPQ(int\
    \ m) : ft(FenwickTree(m)) {}\n\tvoid range_update(int ui, int uj, ll v)\n\t{\n\
    \t\tft.update(ui, v);\t   // [ui, ui+1, .., m] +v\n\t\tft.update(uj + 1, -v);\
    \ // [uj+1, uj+2, .., m] -v\n\t} // [ui, ui+1, .., uj] +v\n\tll point_query(int\
    \ i) { return ft.rsq(i); } // rsq(i) is sufficient\n};\n\nclass RURQ\n{\t\t\t\t\
    \t  // RURQ variant - range update, range query\nprivate:\t\t\t  // needs two\
    \ helper FTs\n\tRUPQ rupq;\t\t  // one RUPQ and\n\tFenwickTree purq; // one PURQ\n\
    public:\n\tRURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {} // initialization\n\
    \tvoid range_update(int ui, int uj, ll v)\n\t{\n\t\trupq.range_update(ui, uj,\
    \ v);  // [ui, ui+1, .., uj] +v\n\t\tpurq.update(ui, v * (ui - 1)); // -(ui-1)*v\
    \ before ui\n\t\tpurq.update(uj + 1, -v * uj);  // +(uj-ui+1)*v after uj\n\t}\n\
    \tll rsq(int j)\n\t{\n\t\treturn rupq.point_query(j) * j - // optimistic calculation\n\
    \t\t\t   purq.rsq(j);\t\t\t\t // cancelation factor\n\t}\n\tll rsq(int i, int\
    \ j) { return rsq(j) - rsq(i - 1); } // standard\n};\n\n// Example code\nint main()\n\
    {\n\tvll f = {0, 0, 1, 0, 1, 2, 3, 2, 1, 1, 0}; // index 0 is always 0\n\tFenwickTree\
    \ ft(f);\n\tprintf(\"%lld\\n\", ft.rsq(1, 6));\t // 7 => ft[6]+ft[4] = 5+2 = 7\n\
    \tprintf(\"%d\\n\", ft.select(7));\t // index 6, rsq(1, 6) == 7, which is >= 7\n\
    \tft.update(5, 1);\t\t\t\t // update demo\n\tprintf(\"%lld\\n\", ft.rsq(1, 10));\
    \ // now 12\n\tprintf(\"=====\\n\");\n\tRUPQ rupq(10);\n\tRURQ rurq(10);\n\trupq.range_update(2,\
    \ 9, 7); // indices in [2, 3, .., 9] updated by +7\n\trurq.range_update(2, 9,\
    \ 7); // same as rupq above\n\trupq.range_update(6, 7, 3); // indices 6&7 are\
    \ further updated by +3 (10)\n\trurq.range_update(6, 7, 3); // same as rupq above\n\
    \t// idx = 0 (unused) | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10\n\t// val = -  \
    \        | 0 | 7 | 7 | 7 | 7 |10 |10 | 7 | 7 | 0\n\tfor (int i = 1; i <= 10; i++)\n\
    \t\tprintf(\"%d -> %lld\\n\", i, rupq.point_query(i));\n\tprintf(\"RSQ(1, 10)\
    \ = %lld\\n\", rurq.rsq(1, 10)); // 62\n\tprintf(\"RSQ(6, 7) = %lld\\n\", rurq.rsq(6,\
    \ 7));\t// 20\n\treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define LSOne(S) ((S) &\
    \ -(S)) // the key operation\n\ntypedef long long ll; // for extra flexibility\n\
    typedef vector<ll> vll;\ntypedef vector<int> vi;\n\nclass FenwickTree\n{ // index\
    \ 0 is not used\nprivate:\n\tvll ft; // internal FT is an array\npublic:\n\tFenwickTree(int\
    \ m) { ft.assign(m + 1, 0); } // create an empty FT\n\n\tvoid build(const vll\
    \ &f)\n\t{\n\t\tint m = (int)f.size() - 1; // note f[0] is always 0\n\t\tft.assign(m\
    \ + 1, 0);\n\t\tfor (int i = 1; i <= m; ++i)\n\t\t{\t\t\t\t\t\t\t\t   // O(m)\n\
    \t\t\tft[i] += f[i];\t\t\t\t   // add this value\n\t\t\tif (i + LSOne(i) <= m)\t\
    \t   // i has parent\n\t\t\t\tft[i + LSOne(i)] += ft[i]; // add to that parent\n\
    \t\t}\n\t}\n\n\tFenwickTree(const vll &f) { build(f); } // create FT based on\
    \ f\n\n\tFenwickTree(int m, const vi &s)\n\t{ // create FT based on s\n\t\tvll\
    \ f(m + 1, 0);\n\t\tfor (int i = 0; i < (int)s.size(); ++i) // do the conversion\
    \ first\n\t\t\t++f[s[i]];\t\t\t\t\t\t\t// in O(n)\n\t\tbuild(f);\t\t\t\t\t\t\t\
    \t// in O(m)\n\t}\n\n\tll rsq(int j)\n\t{ // returns RSQ(1, j)\n\t\tll sum = 0;\n\
    \t\tfor (; j; j -= LSOne(j))\n\t\t\tsum += ft[j];\n\t\treturn sum;\n\t}\n\n\t\
    ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); } // inc/exclusion\n\n\t//\
    \ updates value of the i-th element by v (v can be +ve/inc or -ve/dec)\n\tvoid\
    \ update(int i, ll v)\n\t{\n\t\tfor (; i < (int)ft.size(); i += LSOne(i))\n\t\t\
    \tft[i] += v;\n\t}\n\n\tint select(ll k)\n\t{ // O(log m)\n\t\tint p = 1;\n\t\t\
    while (p * 2 < (int)ft.size())\n\t\t\tp *= 2;\n\t\tint i = 0;\n\t\twhile (p)\n\
    \t\t{\n\t\t\tif (k > ft[i + p])\n\t\t\t{\n\t\t\t\tk -= ft[i + p];\n\t\t\t\ti +=\
    \ p;\n\t\t\t}\n\t\t\tp /= 2;\n\t\t}\n\t\treturn i + 1;\n\t}\n};\n\nclass RUPQ\n\
    { // RUPQ variant - range update, point query\nprivate:\n\tFenwickTree ft; //\
    \ internally use PURQ FT\npublic:\n\tRUPQ(int m) : ft(FenwickTree(m)) {}\n\tvoid\
    \ range_update(int ui, int uj, ll v)\n\t{\n\t\tft.update(ui, v);\t   // [ui, ui+1,\
    \ .., m] +v\n\t\tft.update(uj + 1, -v); // [uj+1, uj+2, .., m] -v\n\t} // [ui,\
    \ ui+1, .., uj] +v\n\tll point_query(int i) { return ft.rsq(i); } // rsq(i) is\
    \ sufficient\n};\n\nclass RURQ\n{\t\t\t\t\t  // RURQ variant - range update, range\
    \ query\nprivate:\t\t\t  // needs two helper FTs\n\tRUPQ rupq;\t\t  // one RUPQ\
    \ and\n\tFenwickTree purq; // one PURQ\npublic:\n\tRURQ(int m) : rupq(RUPQ(m)),\
    \ purq(FenwickTree(m)) {} // initialization\n\tvoid range_update(int ui, int uj,\
    \ ll v)\n\t{\n\t\trupq.range_update(ui, uj, v);  // [ui, ui+1, .., uj] +v\n\t\t\
    purq.update(ui, v * (ui - 1)); // -(ui-1)*v before ui\n\t\tpurq.update(uj + 1,\
    \ -v * uj);  // +(uj-ui+1)*v after uj\n\t}\n\tll rsq(int j)\n\t{\n\t\treturn rupq.point_query(j)\
    \ * j - // optimistic calculation\n\t\t\t   purq.rsq(j);\t\t\t\t // cancelation\
    \ factor\n\t}\n\tll rsq(int i, int j) { return rsq(j) - rsq(i - 1); } // standard\n\
    };\n\n// Example code\nint main()\n{\n\tvll f = {0, 0, 1, 0, 1, 2, 3, 2, 1, 1,\
    \ 0}; // index 0 is always 0\n\tFenwickTree ft(f);\n\tprintf(\"%lld\\n\", ft.rsq(1,\
    \ 6));\t // 7 => ft[6]+ft[4] = 5+2 = 7\n\tprintf(\"%d\\n\", ft.select(7));\t //\
    \ index 6, rsq(1, 6) == 7, which is >= 7\n\tft.update(5, 1);\t\t\t\t // update\
    \ demo\n\tprintf(\"%lld\\n\", ft.rsq(1, 10)); // now 12\n\tprintf(\"=====\\n\"\
    );\n\tRUPQ rupq(10);\n\tRURQ rurq(10);\n\trupq.range_update(2, 9, 7); // indices\
    \ in [2, 3, .., 9] updated by +7\n\trurq.range_update(2, 9, 7); // same as rupq\
    \ above\n\trupq.range_update(6, 7, 3); // indices 6&7 are further updated by +3\
    \ (10)\n\trurq.range_update(6, 7, 3); // same as rupq above\n\t// idx = 0 (unused)\
    \ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10\n\t// val = -          | 0 | 7 | 7 |\
    \ 7 | 7 |10 |10 | 7 | 7 | 0\n\tfor (int i = 1; i <= 10; i++)\n\t\tprintf(\"%d\
    \ -> %lld\\n\", i, rupq.point_query(i));\n\tprintf(\"RSQ(1, 10) = %lld\\n\", rurq.rsq(1,\
    \ 10)); // 62\n\tprintf(\"RSQ(6, 7) = %lld\\n\", rurq.rsq(6, 7));\t// 20\n\treturn\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Data Structrue/Fenwick.cpp
  requiredBy: []
  timestamp: '2024-11-07 11:32:23+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structrue/Fenwick.cpp
layout: document
redirect_from:
- /library/Data Structrue/Fenwick.cpp
- /library/Data Structrue/Fenwick.cpp.html
title: Data Structrue/Fenwick.cpp
---
