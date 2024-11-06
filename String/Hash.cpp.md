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
    - https://judge.yosupo.jp/problem/zalgorithm
    - https://oj.vnoi.info/problem/dtksub
    - https://oj.vnoi.info/problem/paliny
    - https://oj.vnoi.info/problem/substr
    - https://oj.vnoi.info/problem/vostr
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Math/modint.h:\
    \ line -1: no such header\n"
  code: "#include \"../Math/modint.h\"\n\n// Hash {{{\n// Usage:\n// HashGenerator\
    \ g(MAX_LENGTH)\n//\n// auto h = g.hash(s)\n// g.equals(s, h, l1, r1, s, h, l2,\
    \ r2)\n// g.cmp(s, h, l1, r1, s, h, l2, r2)\n//\n// Tested:\n// - https://oj.vnoi.info/problem/substr\n\
    // - https://oj.vnoi.info/problem/paliny  - max palin / binary search\n// - https://oj.vnoi.info/problem/dtksub\
    \  - hash<Hash> for unordered_map\n// - https://oj.vnoi.info/problem/vostr   -\
    \ cmp\n\nconst int MOD = 1e9 + 7;\nusing modular = ModInt<MOD>;\n\nstruct Hash\
    \ {\n    long long x;\n    modular y;\n\n    Hash operator + (const Hash& a) const\
    \ { return Hash{x + a.x, y + a.y}; }\n    Hash operator - (const Hash& a) const\
    \ { return Hash{x - a.x, y - a.y}; }\n    Hash operator * (const Hash& a) const\
    \ { return Hash{x * a.x, y * a.y}; }\n    Hash operator * (int k) const { return\
    \ Hash{x*k, y*k}; }\n\n    Hash& operator += (const Hash& a) { return *this =\
    \ *this + a; }\n    Hash& operator -= (const Hash& a) { return *this = *this -\
    \ a; }\n    Hash& operator *= (const Hash& a) { return *this = *this * a; }\n\
    };\nbool operator == (const Hash& a, const Hash& b) {\n    return a.x == b.x &&\
    \ a.y == b.y;\n}\nbool operator < (const Hash& a, const Hash& b) {\n    if (a.x\
    \ != b.x) return a.x < b.x;\n    return a.y.x < b.y.x;\n}\nstd::ostream& operator\
    \ << (std::ostream& out, const Hash& h) {\n    out << '(' << h.x << \", \" <<\
    \ h.y << ')';\n    return out;\n}\n\n// hash function for std::unordered_map\n\
    namespace std {\n    template<>\n    struct hash<Hash> {\n        public:\n  \
    \          size_t operator() (const Hash& h) const {\n                return h.x\
    \ * 1000000009 + h.y.x;\n            }\n    };\n}\n\nstruct HashGenerator {\n\
    \    HashGenerator(int maxLen, int base = 311) {\n        p.resize(maxLen + 1);\n\
    \        p[0] = {1, 1};\n        for (int i = 1; i <= maxLen; i++) {\n       \
    \     p[i] = p[i-1] * base;\n        }\n    }\n\n    template<typename Container>\n\
    \    std::vector<Hash> hash(const Container& s) const {\n        std::vector<Hash>\
    \ res(s.size());\n        for (size_t i = 0; i < s.size(); i++) {\n          \
    \  res[i] = p[i] * (int) s[i];\n        }\n        std::partial_sum(res.begin(),\
    \ res.end(), res.begin());\n        return res;\n    }\n\n    Hash getHash(const\
    \ std::vector<Hash>& h, int l, int r) const {\n        return __getHash(h, l,\
    \ r) * p[p.size() - 1 - l];\n    }\n\n    // compare [l1, r1] vs [l2, r2]\n  \
    \  bool equals(\n            const std::vector<Hash>& h1, int l1, int r1,\n  \
    \          const std::vector<Hash>& h2, int l2, int r2) const {\n        assert(0\
    \ <= l1 && l1 <= r1 && r1 < (int) h1.size());\n        assert(0 <= l2 && l2 <=\
    \ r2 && r2 < (int) h2.size());\n        if (r1 - l1 != r2 - l2) return false;\n\
    \n        return getHash(h1, l1, r1) == getHash(h2, l2, r2);\n    }\n\n    //\
    \ Returns length of max common prefix of h1[l1, r1] and h2[l2, r2]\n    // length\
    \ = 0 -> first character of 2 substrings are different.\n    int maxCommonPrefix(\n\
    \            const std::vector<Hash>& h1, int l1, int r1,\n            const std::vector<Hash>&\
    \ h2, int l2, int r2) const {\n        assert(0 <= l1 && l1 <= r1 && r1 < (int)\
    \ h1.size());\n        assert(0 <= l2 && l2 <= r2 && r2 < (int) h2.size());\n\n\
    \        int len1 = r1 - l1 + 1;\n        int len2 = r2 - l2 + 1;\n\n        int\
    \ res = -1, left = 0, right = std::min(len1, len2) - 1;\n        while (left <=\
    \ right) {\n            int mid = (left + right) / 2;\n            if (equals(h1,\
    \ l1, l1 + mid, h2, l2, l2 + mid)) {\n                res = mid;\n           \
    \     left = mid + 1;\n            } else {\n                right = mid - 1;\n\
    \            }\n        }\n        return res + 1;\n        /* C++20\n       \
    \ auto r = std::views::iota(0, std::min(len1, len2));\n        auto res = std::ranges::partition_point(\n\
    \                r,\n                [&] (int mid) {\n                    return\
    \ equals(h1, l1, l1+mid, h2, l2, l2+mid);\n                });\n        return\
    \ *res;\n         */\n    }\n\n    // compare s1[l1, r1] and s2[l2, r2]\n    template<typename\
    \ Container1, typename Container2>\n    int cmp(\n            const Container1&\
    \ s1, const std::vector<Hash>& h1, int l1, int r1,\n            const Container2&\
    \ s2, const std::vector<Hash>& h2, int l2, int r2) const {\n        assert(0 <=\
    \ l1 && l1 <= r1 && r1 < (int) h1.size());\n        assert(0 <= l2 && l2 <= r2\
    \ && r2 < (int) h2.size());\n\n        int commonPrefixLen = maxCommonPrefix(h1,\
    \ l1, r1, h2, l2, r2);\n        char c1 = (l1 + commonPrefixLen <= r1) ? s1[l1\
    \ + commonPrefixLen] : 0;\n        char c2 = (l2 + commonPrefixLen <= r2) ? s2[l2\
    \ + commonPrefixLen] : 0;\n\n        return (c1 == c2) ? 0 : ((c1 < c2) ? -1 :\
    \ 1);\n    }\n\nprivate:\n    std::vector<Hash> p;\n\n    // DO NOT USE, this\
    \ doesn't divide by p[l]\n    Hash __getHash(const std::vector<Hash>& h, int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r < (int) h.size());\n  \
    \      return h[r] - (l == 0 ? Hash{0, 0} : h[l-1]);\n    }\n};\n// }}}\n//Example\
    \ Code\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ \"../../template.h\"\n#include \"../hash.h\"\n\nvoid solve() {\n    HashGenerator\
    \ g(500111);\n    string s; cin >> s;\n    auto h = g.hash(s);\n\n    int n =\
    \ s.size();\n    REP(i,n) {\n        cout << g.maxCommonPrefix(h, 0, n-1, h, i,\
    \ n-1) << ' ';\n    }\n    cout << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/Hash.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Hash.cpp
layout: document
redirect_from:
- /library/String/Hash.cpp
- /library/String/Hash.cpp.html
title: String/Hash.cpp
---
