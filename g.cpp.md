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
  bundledCode: "#line 1 \"g.cpp\"\n#include <bits/stdc++.h>\n#define ll long long\n\
    #define ii pair<int, int>\nusing namespace std;\n\nll n, res[500005] = {0}, dem1\
    \ = 0, sum[500005];\nstring s;\nvector<ll> v;\n\n\n\nll tinh(ll l, ll r){\n  \
    \  if(l == 0) return sum[r];\n    return sum[r] - sum[l-1];\n}\n\nll f(ll t){\n\
    \    if(res[t] != 0) return res[t];\n    ll cnt = 0, tmp = 0, m = INT_MAX;\n \
    \   for(ll i = 0; i < v.size(); i++){\n        if(tinh(i, v.size()-1) < t) break;\n\
    \        ll l = 0, r = v.size()-1, ans;\n        while(l <= r){\n            ll\
    \ mid = (l+r) >> 1;\n            ll tmp = tinh(i, mid);\n            if(tmp >=\
    \ t){\n                ans = mid;\n                r = mid-1;\n            }\n\
    \            else{\n                l = mid+1;\n            }\n        }\n   \
    \     m = min(m, tinh(i, ans));\n        cnt++;\n        i = ans;\n    }\n   \
    \ if(cnt == 0 || cnt == 1){\n        return 0;\n    }\n    for(ll i = t; i <=\
    \ m; i++){\n        res[i] = i * cnt + cnt - 1;\n    }\n    return res[t];\n}\n\
    \nint main()\n{\n    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\
    \    cin >> n >> s;\n    ll tmp = 0;\n    for(ll i = 0; i < n; i++){\n       \
    \ if(s[i] == '1') {\n            dem1++;\n            if(tmp) v.push_back(tmp);\n\
    \            tmp = 0;\n        }\n        else tmp++;\n    }\n    if(tmp) v.push_back(tmp);\n\
    \    if(v.empty()){\n        cout << dem1;\n        return 0;\n    }\n    sum[0]\
    \ = v[0];\n    for(ll i = 1; i < v.size(); i++) sum[i] = sum[i-1] + v[i];\n  \
    \  ll ans = dem1;\n    for(ll t = 1; t <= 500000; t++){\n        ll tmp = f(t);\n\
    \        if(tmp == 0) break;\n        ans = max(ans, tmp);\n    }\n    cout <<\
    \ ans;\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n#define ll long long\n#define ii pair<int, int>\n\
    using namespace std;\n\nll n, res[500005] = {0}, dem1 = 0, sum[500005];\nstring\
    \ s;\nvector<ll> v;\n\n\n\nll tinh(ll l, ll r){\n    if(l == 0) return sum[r];\n\
    \    return sum[r] - sum[l-1];\n}\n\nll f(ll t){\n    if(res[t] != 0) return res[t];\n\
    \    ll cnt = 0, tmp = 0, m = INT_MAX;\n    for(ll i = 0; i < v.size(); i++){\n\
    \        if(tinh(i, v.size()-1) < t) break;\n        ll l = 0, r = v.size()-1,\
    \ ans;\n        while(l <= r){\n            ll mid = (l+r) >> 1;\n           \
    \ ll tmp = tinh(i, mid);\n            if(tmp >= t){\n                ans = mid;\n\
    \                r = mid-1;\n            }\n            else{\n              \
    \  l = mid+1;\n            }\n        }\n        m = min(m, tinh(i, ans));\n \
    \       cnt++;\n        i = ans;\n    }\n    if(cnt == 0 || cnt == 1){\n     \
    \   return 0;\n    }\n    for(ll i = t; i <= m; i++){\n        res[i] = i * cnt\
    \ + cnt - 1;\n    }\n    return res[t];\n}\n\nint main()\n{\n    ios_base::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n    cin >> n >> s;\n    ll tmp = 0;\n    for(ll i\
    \ = 0; i < n; i++){\n        if(s[i] == '1') {\n            dem1++;\n        \
    \    if(tmp) v.push_back(tmp);\n            tmp = 0;\n        }\n        else\
    \ tmp++;\n    }\n    if(tmp) v.push_back(tmp);\n    if(v.empty()){\n        cout\
    \ << dem1;\n        return 0;\n    }\n    sum[0] = v[0];\n    for(ll i = 1; i\
    \ < v.size(); i++) sum[i] = sum[i-1] + v[i];\n    ll ans = dem1;\n    for(ll t\
    \ = 1; t <= 500000; t++){\n        ll tmp = f(t);\n        if(tmp == 0) break;\n\
    \        ans = max(ans, tmp);\n    }\n    cout << ans;\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: g.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:09:26+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: g.cpp
layout: document
redirect_from:
- /library/g.cpp
- /library/g.cpp.html
title: g.cpp
---
