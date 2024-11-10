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
    - https://oj.vnoi.info/problem/substr
  bundledCode: "#line 1 \"String/Zfunc.cpp\"\n// z[i] = length of longest common prefix\
    \ of s[0..N] and s[i..N]\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/zalgorithm\n\
    // - (string matching) https://oj.vnoi.info/problem/substr\n// Z-func {{{\nvector<int>\
    \ zfunc(const string& s) {\n    int n = (int) s.length();\n    vector<int> z(n);\n\
    \    z[0] = n;\n    for (int i = 1, l = 0, r = 0; i < n; ++i) {\n        if (i\
    \ <= r)\n            z[i] = min(r - i + 1, z[i - l]);\n        while (i + z[i]\
    \ < n && s[z[i]] == s[i + z[i]])\n            ++z[i];\n        if (i + z[i] -\
    \ 1 > r)\n            l = i, r = i + z[i] - 1;\n    }\n    return z;\n}\n// }}}\n\
    \n// Examples:\n// Find all occurrences of p in t\n\n/**\n    string s = p + \"\
    _\" + t;\n    auto z = zfunc(s);\n\n    REP(i,SZ(t)) {\n        if (z[i + SZ(p)\
    \ + 1] == SZ(p)) {\n            cout << 1+i << ' ';\n        }\n    }\n    cout\
    \ << endl;\n*/\n"
  code: "// z[i] = length of longest common prefix of s[0..N] and s[i..N]\n//\n//\
    \ Tested:\n// - https://judge.yosupo.jp/problem/zalgorithm\n// - (string matching)\
    \ https://oj.vnoi.info/problem/substr\n// Z-func {{{\nvector<int> zfunc(const\
    \ string& s) {\n    int n = (int) s.length();\n    vector<int> z(n);\n    z[0]\
    \ = n;\n    for (int i = 1, l = 0, r = 0; i < n; ++i) {\n        if (i <= r)\n\
    \            z[i] = min(r - i + 1, z[i - l]);\n        while (i + z[i] < n &&\
    \ s[z[i]] == s[i + z[i]])\n            ++z[i];\n        if (i + z[i] - 1 > r)\n\
    \            l = i, r = i + z[i] - 1;\n    }\n    return z;\n}\n// }}}\n\n// Examples:\n\
    // Find all occurrences of p in t\n\n/**\n    string s = p + \"_\" + t;\n    auto\
    \ z = zfunc(s);\n\n    REP(i,SZ(t)) {\n        if (z[i + SZ(p) + 1] == SZ(p))\
    \ {\n            cout << 1+i << ' ';\n        }\n    }\n    cout << endl;\n*/"
  dependsOn: []
  isVerificationFile: false
  path: String/Zfunc.cpp
  requiredBy: []
  timestamp: '2024-11-10 11:18:59+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Zfunc.cpp
layout: document
redirect_from:
- /library/String/Zfunc.cpp
- /library/String/Zfunc.cpp.html
title: String/Zfunc.cpp
---
