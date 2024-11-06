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
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
    - https://cses.fi/problemset/task/1142
    - https://cses.fi/problemset/task/1645
    - https://oj.vnoi.info/problem/kagain
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../template.h:\
    \ line -1: no such header\n"
  code: "// Nearest smaller {{{\n// Tested:\n// - https://cses.fi/problemset/task/1645\n\
    // - https://cses.fi/problemset/task/1142\n// - https://oj.vnoi.info/problem/kagain\n\
    //\n// return:\n// - left[i] = largest j such that\n//      j < i\n//      a[j]\
    \ < a[i]\n// - no such j -> left[i] = -1\nvector<int> leftNearestSmaller(const\
    \ vector<int>& a) {\n    int n = a.size();\n    vector<int> left(n);\n    stack<int>\
    \ st;  // positions of candidates, A is increasing\n    st.push(-1);\n    for\
    \ (int i = 0; i < n; i++) {\n        while (st.top() >= 0 && a[st.top()] >= a[i])\
    \ st.pop();\n        left[i] = st.top();\n        st.push(i);\n    }\n    return\
    \ left;\n}\n\n// return:\n// - right[i] = smallest j such that:\n//      j > i\n\
    //      a[j] < a[i]\n// - no such j -> right[i] = n\nvector<int> rightNearestSmaller(const\
    \ vector<int>& a) {\n    int n = a.size();\n    vector<int> right(n);\n    stack<int>\
    \ st;   // positions of candidates, A is increasing\n    st.push(n);\n    for\
    \ (int i = n-1; i >= 0; i--) {\n        while (st.top() < n && a[st.top()] >=\
    \ a[i]) st.pop();\n        right[i] = st.top();\n        st.push(i);\n    }\n\
    \    return right;\n}\n// }}}\n//Example Code\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\
    \n\n#include \"../../template.h\"\n#include \"../left_nearest_smaller.h\"\n\n\
    void solve() {\n    int n; cin >> n;\n    vector<int> a(n); for(int& x : a) cin\
    \ >> x;\n\n    auto left = leftNearestSmaller(a);\n    auto right = rightNearestSmaller(a);\n\
    \n    long long res = 0;\n    for (int i = 0; i < n; i++) {\n        int l = left[i]\
    \ + 1;\n        int r = right[i] - 1;\n        res = max(res, a[i] * (r - l +\
    \ 1LL));\n    }\n    cout << res << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Misc/Left nearest smaller.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Left nearest smaller.cpp
layout: document
redirect_from:
- /library/Misc/Left nearest smaller.cpp
- /library/Misc/Left nearest smaller.cpp.html
title: Misc/Left nearest smaller.cpp
---
