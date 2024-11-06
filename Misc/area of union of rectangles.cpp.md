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
    - https://judge.yosupo.jp/problem/area_of_union_of_rectangles
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../LazySegTree.h:\
    \ line -1: no such header\n"
  code: "#include \"../LazySegTree.h\"\n\n// Area of union of rectangles {{{\nnamespace\
    \ area_of_union_of_rectangles {\n    using ll = long long;\n    const int INF\
    \ = std::numeric_limits<int>::max() / 2;\n\n    struct Rect {\n        int x1,\
    \ y1, x2, y2;\n    };\n    istream& operator >> (istream& cin, Rect& r) {\n  \
    \      cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;\n        return cin;\n    }\n\n  \
    \  struct S {\n        int min_cnt;\n        ll sum;\n    };\n    S op(S x, S\
    \ y) {\n        if (x.min_cnt < y.min_cnt) return x;\n        if (y.min_cnt <\
    \ x.min_cnt) return y;\n        return { x.min_cnt, x.sum + y.sum };\n    }\n\
    \    S e() { return { INF, 0 }; }\n    S mapping(int f, S s) { return { s.min_cnt\
    \ + f, s.sum }; }\n    int composition(int f, int g) { return f + g; }\n    int\
    \ id() { return 0; }\n    using ST = LazySegTree<S, op, e, int, mapping, composition,\
    \ id>;\n\n    ll solve(const std::vector<Rect>& rects) {\n        if (rects.empty())\
    \ return ll(0);\n\n        const int n = rects.size();\n        std::vector<std::tuple<int,\
    \ int, int, int>> events; events.reserve(2*n);\n        std::vector<int> ys; ys.reserve(2*n);\n\
    \n        for (const auto& r : rects) {\n            events.emplace_back(r.x1,\
    \ r.y1, r.y2, +1);\n            events.emplace_back(r.x2, r.y1, r.y2, -1);\n \
    \           ys.push_back(r.y1);\n            ys.push_back(r.y2);\n        }\n\
    \        std::sort(events.begin(), events.end(), [] (const auto& e1, const auto&\
    \ e2) {\n                return std::get<0>(e1) < std::get<0>(e2); });\n     \
    \   std::sort(ys.begin(), ys.end());\n        ys.erase(std::unique(ys.begin(),\
    \ ys.end()), ys.end());\n\n        const int nys = ys.size();\n        std::vector<S>\
    \ init(nys - 1);\n        for (int i = 0; i < nys - 1; ++i) {\n            init[i]\
    \ = { 0, ys[i+1] - ys[i] };\n        }\n        ST st(init);\n\n        ll res\
    \ = 0;\n        ll lx = std::get<0>(events.front());  // events[i-1].x\n     \
    \   for (int i = 0; lx != std::get<0>(events.back());) {\n            for (;;\
    \ ++i) {\n                auto [xi, d, u, add] = events[i];\n                if\
    \ (xi != lx) break;\n                int ly = std::lower_bound(ys.begin(), ys.end(),\
    \ d) - ys.begin();\n                int ry = std::lower_bound(ys.begin(), ys.end(),\
    \ u) - ys.begin();\n                st.apply(ly, ry, add);\n            }\n  \
    \          ll rx = std::get<0> (events[i]);\n            auto [min_cnt, sum] =\
    \ st.all_prod();\n            res += (rx - lx) * (ys.back() - ys.front() - (min_cnt\
    \ == 0 ? sum : ll(0)));\n            lx = rx;\n        }\n        return res;\n\
    \    }\n}\n// }}}\n\n//Example Code\n#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../misc/area_of_union_of_rectangles.h\"\
    \nusing namespace area_of_union_of_rectangles;\n\nint main() {\n    int n; cin\
    \ >> n;\n    vector<Rect> rects(n);\n    for (auto& r : rects) cin >> r;\n   \
    \ cout << solve(rects) << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Misc/area of union of rectangles.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/area of union of rectangles.cpp
layout: document
redirect_from:
- /library/Misc/area of union of rectangles.cpp
- /library/Misc/area of union of rectangles.cpp.html
title: Misc/area of union of rectangles.cpp
---
