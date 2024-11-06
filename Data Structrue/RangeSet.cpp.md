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
    - https://suisen-cp.github.io/cp-library-cpp/library/datastructure/util/range_set.hpp
    - https://yukicoder.me/problems/no/674
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../template.h:\
    \ line -1: no such header\n"
  code: "// RangeSet - for maintaining set of segments {{{\n//\n// merge_adjacent_segment\
    \ = true -> merge 2 consecutive segments,\n// e.g. [1, 10] and [11, 20] --> [1,\
    \ 20]\n//\n// Based on https://suisen-cp.github.io/cp-library-cpp/library/datastructure/util/range_set.hpp\n\
    template<typename T, bool merge_adjacent_segment = true>\nstruct RangeSet {\n\
    \    T n_elements() const { return sz; }\n    T n_ranges() const { return ranges.size();\
    \ }\n\n    bool contains(T x) const {\n        auto it = ranges.upper_bound(x);\n\
    \        return it != ranges.begin() && x <= std::prev(it)->second;\n    }\n\n\
    \    // Find range containing x, i.e. l <= x <= r\n    auto find_range(T x) const\
    \ {\n        auto it = ranges.upper_bound(x);\n        return it != ranges.begin()\
    \ && x <= prev(it)->second ? prev(it) : ranges.end();\n    }\n\n    // Insert\
    \ [l, r]\n    // Returns number of new integers added.\n    // AMORTIZED O(logN)\n\
    \    T insert(T l, T r) {\n        assert(l <= r);\n        auto it = ranges.upper_bound(l);\n\
    \        if (it != ranges.begin() && is_mergeable(std::prev(it)->second, l)) {\n\
    \            it = std::prev(it);\n            l = std::min(l, it->first);\n  \
    \      }\n        T inserted = 0;\n        for (; it != ranges.end() && is_mergeable(r,\
    \ it->first); it = ranges.erase(it)) {\n            auto [cl, cr] = *it;\n   \
    \         r = std::max(r, cr);\n            inserted -= cr - cl + 1;\n       \
    \ }\n\n        inserted += r - l + 1;\n        ranges[l] = r;\n        sz += inserted;\n\
    \        return inserted;\n    }\n\n    // Erase [l, r]\n    // Returns number\
    \ of integers removed\n    // AMORTIZED O(logN)\n    T erase(T l, T r) {\n   \
    \     assert(l <= r);\n        T tl = l, tr = r;\n        auto it = ranges.upper_bound(l);\n\
    \        if (it != ranges.begin() && l <= std::prev(it)->second) {\n         \
    \   it = std::prev(it);\n            tl = it->first;\n        }\n\n        T erased\
    \ = 0;\n        for (; it != ranges.end() && it->first <= r; it = ranges.erase(it))\
    \ {\n            auto [cl, cr] = *it;\n            tr = cr;\n            erased\
    \ += cr - cl + 1;\n        }\n        if (tl < l) {\n            ranges[tl] =\
    \ l-1;\n            erased -= l - tl;\n        }\n        if (r < tr) {\n    \
    \        ranges[r + 1] = tr;\n            erased -= tr - r;\n        }\n     \
    \   sz -= erased;\n        return erased;\n    }\n\n    // Find min x: x >= lower\
    \ && x NOT in this set\n    T minimum_excluded(T lower) const {\n        static_assert(merge_adjacent_segment);\n\
    \        auto it = find_range(lower);\n        return it == ranges.end() ? lower\
    \ : it->second + 1;\n    }\n\n    // Find max x: x <= upper && x NOT in this set\n\
    \    T maximum_excluded(T upper) const {\n        static_assert(merge_adjacent_segment);\n\
    \        auto it = find_range(upper);\n        return it == ranges.end() ? upper\
    \ : it->first - 1;\n    }\n\n    T sz = 0;\n    std::map<T, T> ranges;\n\n   \
    \ bool is_mergeable(T cur_r, T next_l) {\n        return next_l <= cur_r + merge_adjacent_segment;\n\
    \    }\n};\n// }}}\n\n//Example Code\n#define PROBLEM \"https://yukicoder.me/problems/no/674\"\
    \n\n#include \"../../template.h\"\n#include \"../RangeSet.h\"\n\nvoid solve()\
    \ {\n    long long d;\n    int q;\n    std::cin >> d >> q;\n\n    long long ans\
    \ = 0;\n    RangeSet<long long> set;\n    while (q --> 0) {\n        long long\
    \ l, r;\n        std::cin >> l >> r;\n        set.insert(l, r);\n        auto\
    \ lr = set.find_range(l);\n        if (lr != set.ranges.end()) {\n           \
    \ auto [nl, nr] = *lr;\n            ans = std::max(ans, nr - nl + 1LL);\n    \
    \    }\n        std::cout << ans << '\\n';\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: Data Structrue/RangeSet.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structrue/RangeSet.cpp
layout: document
redirect_from:
- /library/Data Structrue/RangeSet.cpp
- /library/Data Structrue/RangeSet.cpp.html
title: Data Structrue/RangeSet.cpp
---
