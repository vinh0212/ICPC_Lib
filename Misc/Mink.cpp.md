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
    - https://oj.vnoi.info/problem/mink
    - https://www.spoj.com/problems/ADASQR/
  bundledCode: "#line 1 \"Misc/Mink.cpp\"\n// Tested:\n// - 1D: https://oj.vnoi.info/problem/mink\n\
    // - 2D (just do 1D twice, for row then for col): https://www.spoj.com/problems/ADASQR/\n\
    //\n// NOTE: Must update MN\nconst int MN = 5000111;\n\n// Return min of each\
    \ length-K-subarray for range [left, right) {{{\ntemplate<typename T>\nvector<T>\
    \ mink(const std::vector<T>& a, int k) {\n    // deque maintaining candidates\
    \ in *increasing order*\n    // Avoid using std::deque because of performance\n\
    \    int head = 0, tail = -1;\n    static pair<int, T> buf[MN];\n\n    auto is_empty\
    \ = [&] () { return head > tail; };\n    auto add = [&] (int id, T val) {\n  \
    \      while (!is_empty() && buf[tail].second >= val) --tail;\n        buf[++tail]\
    \ = {id, val};\n    };\n    // remove all ids <= lower_bound\n    auto rem = [&]\
    \ (int lower_bound) {\n        if (!is_empty() && buf[head].first <= lower_bound)\
    \ ++head;\n    };\n\n    int n = a.size();\n    vector<T> res(n - k + 1);\n  \
    \  for (int i = 0; i < n; ++i) {\n        add(i, a[i]);\n        if (i >= k-1)\
    \ {\n            rem(i - k);\n            res[i-k+1] = buf[head].second;\n   \
    \     }\n    }\n    return res;\n}\n// }}}\n"
  code: "// Tested:\n// - 1D: https://oj.vnoi.info/problem/mink\n// - 2D (just do\
    \ 1D twice, for row then for col): https://www.spoj.com/problems/ADASQR/\n//\n\
    // NOTE: Must update MN\nconst int MN = 5000111;\n\n// Return min of each length-K-subarray\
    \ for range [left, right) {{{\ntemplate<typename T>\nvector<T> mink(const std::vector<T>&\
    \ a, int k) {\n    // deque maintaining candidates in *increasing order*\n   \
    \ // Avoid using std::deque because of performance\n    int head = 0, tail = -1;\n\
    \    static pair<int, T> buf[MN];\n\n    auto is_empty = [&] () { return head\
    \ > tail; };\n    auto add = [&] (int id, T val) {\n        while (!is_empty()\
    \ && buf[tail].second >= val) --tail;\n        buf[++tail] = {id, val};\n    };\n\
    \    // remove all ids <= lower_bound\n    auto rem = [&] (int lower_bound) {\n\
    \        if (!is_empty() && buf[head].first <= lower_bound) ++head;\n    };\n\n\
    \    int n = a.size();\n    vector<T> res(n - k + 1);\n    for (int i = 0; i <\
    \ n; ++i) {\n        add(i, a[i]);\n        if (i >= k-1) {\n            rem(i\
    \ - k);\n            res[i-k+1] = buf[head].second;\n        }\n    }\n    return\
    \ res;\n}\n// }}}"
  dependsOn: []
  isVerificationFile: false
  path: Misc/Mink.cpp
  requiredBy: []
  timestamp: '2024-11-09 09:36:42+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Mink.cpp
layout: document
redirect_from:
- /library/Misc/Mink.cpp
- /library/Misc/Mink.cpp.html
title: Misc/Mink.cpp
---
