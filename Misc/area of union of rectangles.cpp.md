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
    - https://codeforces.com/contest/610/problem/D
    - https://oj.vnoi.info/problem/icpc23_mb_b
  bundledCode: "#line 1 \"Misc/area of union of rectangles.cpp\"\n//Tested: \n// -\
    \ https://codeforces.com/contest/610/problem/D\n// - https://oj.vnoi.info/problem/icpc23_mb_b\n\
    // From CTP.LTT\n#include <bits/stdc++.h>\nusing namespace std;\n#define maxn\
    \ 400005\n#define maxm 1000005\n\nint a[maxn], sum[maxn*4], cnt[maxn*4];\n\nvoid\
    \ update(int l, int r, int low, int high, int id, int gt) {//range: [a[l], a[r])\n\
    \    if (high <= a[l] || a[r] <= low) return;\n    if (low <= a[l] && a[r] <=\
    \ high) {\n        cnt[id] += gt;\n        if (cnt[id]) sum[id] = a[r]-a[l];\n\
    \        else sum[id] = sum[2*id] + sum[2*id+1];\n        return;\n    }\n   \
    \ int mid = (l+r)/2;\n    update(l, mid, low, high, 2*id, gt);\n    update(mid,\
    \ r, low, high, 2*id+1, gt);\n    if (!cnt[id]) sum[id] = sum[2*id] + sum[2*id+1];\n\
    }\n\nint main() {\n    fastio;\n    int n; cin >> n;\n    vector<int> tmp;\n \
    \   vector< pair<ii, ii> > sweepline; //sweepline: (x, type), (y1, y2)\n    fto\
    \ (i, 1, n) {\n        int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;\n    \
    \    if (x1 > x2) swap(x1, x2);\n        if (y1 > y2) swap(y1, y2);\n        ++y2;\
    \ ++x2;\n        sweepline.pb(mp(mp(x1, 1), mp(y1, y2)));\n        sweepline.pb(mp(mp(x2,\
    \ -1), mp(y1, y2)));\n        tmp.pb(y1); tmp.pb(y2);\n    }\n    int r = 0;\n\
    \    sort(tmp.begin(), tmp.end());\n    sort(sweepline.begin(), sweepline.end(),\
    \ [&](pair<ii, ii> left, pair<ii, ii> right) {\n        return left.ff.ff < right.ff.ff;\n\
    \    });\n    fto (i, 0, (int)tmp.size()-1) {\n        a[++r] = tmp[i];\n    \
    \    while (i+1 < tmp.size() && tmp[i] == tmp[i+1]) ++i;\n    }\n    long long\
    \ ans = 0;\n    int pre = sweepline[0].ff.ff;\n    fto (i, 0, (int)sweepline.size()-1)\
    \ {\n        ans = ans + (long long)(sweepline[i].ff.ff-pre)*sum[1];\n       \
    \ pre = sweepline[i].ff.ff;\n        update(1, r, sweepline[i].ss.ff, sweepline[i].ss.ss,\
    \ 1, sweepline[i].ff.ss);\n        while (i+1 < sweepline.size() && sweepline[i+1].ff.ff\
    \ == sweepline[i].ff.ff) {\n            ++i;\n            update(1, r, sweepline[i].ss.ff,\
    \ sweepline[i].ss.ss, 1, sweepline[i].ff.ss);\n        }\n    }\n    cout << ans\
    \ << endl;\n    return 0;\n}\n"
  code: "//Tested: \n// - https://codeforces.com/contest/610/problem/D\n// - https://oj.vnoi.info/problem/icpc23_mb_b\n\
    // From CTP.LTT\n#include <bits/stdc++.h>\nusing namespace std;\n#define maxn\
    \ 400005\n#define maxm 1000005\n\nint a[maxn], sum[maxn*4], cnt[maxn*4];\n\nvoid\
    \ update(int l, int r, int low, int high, int id, int gt) {//range: [a[l], a[r])\n\
    \    if (high <= a[l] || a[r] <= low) return;\n    if (low <= a[l] && a[r] <=\
    \ high) {\n        cnt[id] += gt;\n        if (cnt[id]) sum[id] = a[r]-a[l];\n\
    \        else sum[id] = sum[2*id] + sum[2*id+1];\n        return;\n    }\n   \
    \ int mid = (l+r)/2;\n    update(l, mid, low, high, 2*id, gt);\n    update(mid,\
    \ r, low, high, 2*id+1, gt);\n    if (!cnt[id]) sum[id] = sum[2*id] + sum[2*id+1];\n\
    }\n\nint main() {\n    fastio;\n    int n; cin >> n;\n    vector<int> tmp;\n \
    \   vector< pair<ii, ii> > sweepline; //sweepline: (x, type), (y1, y2)\n    fto\
    \ (i, 1, n) {\n        int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;\n    \
    \    if (x1 > x2) swap(x1, x2);\n        if (y1 > y2) swap(y1, y2);\n        ++y2;\
    \ ++x2;\n        sweepline.pb(mp(mp(x1, 1), mp(y1, y2)));\n        sweepline.pb(mp(mp(x2,\
    \ -1), mp(y1, y2)));\n        tmp.pb(y1); tmp.pb(y2);\n    }\n    int r = 0;\n\
    \    sort(tmp.begin(), tmp.end());\n    sort(sweepline.begin(), sweepline.end(),\
    \ [&](pair<ii, ii> left, pair<ii, ii> right) {\n        return left.ff.ff < right.ff.ff;\n\
    \    });\n    fto (i, 0, (int)tmp.size()-1) {\n        a[++r] = tmp[i];\n    \
    \    while (i+1 < tmp.size() && tmp[i] == tmp[i+1]) ++i;\n    }\n    long long\
    \ ans = 0;\n    int pre = sweepline[0].ff.ff;\n    fto (i, 0, (int)sweepline.size()-1)\
    \ {\n        ans = ans + (long long)(sweepline[i].ff.ff-pre)*sum[1];\n       \
    \ pre = sweepline[i].ff.ff;\n        update(1, r, sweepline[i].ss.ff, sweepline[i].ss.ss,\
    \ 1, sweepline[i].ff.ss);\n        while (i+1 < sweepline.size() && sweepline[i+1].ff.ff\
    \ == sweepline[i].ff.ff) {\n            ++i;\n            update(1, r, sweepline[i].ss.ff,\
    \ sweepline[i].ss.ss, 1, sweepline[i].ff.ss);\n        }\n    }\n    cout << ans\
    \ << endl;\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Misc/area of union of rectangles.cpp
  requiredBy: []
  timestamp: '2024-11-10 11:32:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/area of union of rectangles.cpp
layout: document
redirect_from:
- /library/Misc/area of union of rectangles.cpp
- /library/Misc/area of union of rectangles.cpp.html
title: Misc/area of union of rectangles.cpp
---
