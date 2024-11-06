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
    - https://codeforces.com/blog/entry/12796?#comment-175287
    - https://cses.fi/problemset/task/2102
    - https://cses.fi/problemset/task/2103
    - https://cses.fi/problemset/task/2104
    - https://cses.fi/problemset/task/2108
    - https://github.com/kth-competitive-programming/kactl/blob/main/content/strings/SuffixArray.h
    - https://judge.yosupo.jp/problem/number_of_substrings
    - https://judge.yosupo.jp/problem/suffixarray
    - https://judge.yosupo.jp/submission/52300
    - https://oj.vnoi.info/problem/icpc22_mt_b
    - https://www.spoj.com/problems/ADAPHOTO/
    - https://www.spoj.com/problems/LCS/
    - https://www.spoj.com/problems/LCS2/
    - https://www.spoj.com/problems/LONGCS
    - https://www.spoj.com/problems/SARRAY/
    - https://www.spoj.com/problems/SUBLEX/
    - https://www.spoj.com/problems/SUBST1/
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: hash.h: line -1:\
    \ no such header\n"
  code: "// Efficient O(N + alphabet_size) time and space suffix array\n// For ICPC\
    \ notebook, it's better to copy a shorter code such as\n// https://github.com/kth-competitive-programming/kactl/blob/main/content/strings/SuffixArray.h\n\
    \n// Usage:\n// - sa = suffix_array(s, 'a', 'z')\n// - lcp = LCP(s, sa)\n//  \
    \ lcp[i] = LCP(sa[i], sa[i+1])\n//\n// Tested:\n// - SA https://judge.yosupo.jp/problem/suffixarray\n\
    // - SA https://www.spoj.com/problems/SARRAY/\n// - LCP https://judge.yosupo.jp/problem/number_of_substrings\n\
    // Suffix Array {{{\n// Copied from https://judge.yosupo.jp/submission/52300\n\
    // Helper functions {{{\nvoid induced_sort(const std::vector<int>& vec, int val_range,\n\
    \                  std::vector<int>& SA, const std::vector<bool>& sl,\n      \
    \            const std::vector<int>& lms_idx) {\n    std::vector<int> l(val_range,\
    \ 0), r(val_range, 0);\n    for (int c : vec) {\n        if (c + 1 < val_range)\
    \ ++l[c + 1];\n        ++r[c];\n    }\n    std::partial_sum(l.begin(), l.end(),\
    \ l.begin());\n    std::partial_sum(r.begin(), r.end(), r.begin());\n    std::fill(SA.begin(),\
    \ SA.end(), -1);\n    for (int i = (int)lms_idx.size() - 1; i >= 0; --i)\n   \
    \     SA[--r[vec[lms_idx[i]]]] = lms_idx[i];\n    for (int i : SA)\n        if\
    \ (i >= 1 && sl[i - 1]) SA[l[vec[i - 1]]++] = i - 1;\n    std::fill(r.begin(),\
    \ r.end(), 0);\n    for (int c : vec) ++r[c];\n    std::partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    for (int k = (int)SA.size() - 1, i = SA[k]; k >= 1;\
    \ --k, i = SA[k])\n        if (i >= 1 && !sl[i - 1]) {\n            SA[--r[vec[i\
    \ - 1]]] = i - 1;\n        }\n}\n\nstd::vector<int> SA_IS(const std::vector<int>&\
    \ vec, int val_range) {\n    const int n = vec.size();\n    std::vector<int> SA(n),\
    \ lms_idx;\n    std::vector<bool> sl(n);\n    sl[n - 1] = false;\n    for (int\
    \ i = n - 2; i >= 0; --i) {\n        sl[i] = (vec[i] > vec[i + 1] || (vec[i] ==\
    \ vec[i + 1] && sl[i + 1]));\n        if (sl[i] && !sl[i + 1]) lms_idx.push_back(i\
    \ + 1);\n    }\n    std::reverse(lms_idx.begin(), lms_idx.end());\n    induced_sort(vec,\
    \ val_range, SA, sl, lms_idx);\n    std::vector<int> new_lms_idx(lms_idx.size()),\
    \ lms_vec(lms_idx.size());\n    for (int i = 0, k = 0; i < n; ++i)\n        if\
    \ (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) {\n            new_lms_idx[k++]\
    \ = SA[i];\n        }\n    int cur = 0;\n    SA[n - 1] = cur;\n    for (size_t\
    \ k = 1; k < new_lms_idx.size(); ++k) {\n        int i = new_lms_idx[k - 1], j\
    \ = new_lms_idx[k];\n        if (vec[i] != vec[j]) {\n            SA[j] = ++cur;\n\
    \            continue;\n        }\n        bool flag = false;\n        for (int\
    \ a = i + 1, b = j + 1;; ++a, ++b) {\n            if (vec[a] != vec[b]) {\n  \
    \              flag = true;\n                break;\n            }\n         \
    \   if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {\n                flag\
    \ = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));\n                break;\n\
    \            }\n        }\n        SA[j] = (flag ? ++cur : cur);\n    }\n    for\
    \ (size_t i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];\n    if\
    \ (cur + 1 < (int)lms_idx.size()) {\n        auto lms_SA = SA_IS(lms_vec, cur\
    \ + 1);\n        for (size_t i = 0; i < lms_idx.size(); ++i) {\n            new_lms_idx[i]\
    \ = lms_idx[lms_SA[i]];\n        }\n    }\n    induced_sort(vec, val_range, SA,\
    \ sl, new_lms_idx);\n    return SA;\n}\n// }}}\n\ntemplate<typename ContainerT\
    \ = std::string, typename ElemT = unsigned char>\nstd::vector<int> suffix_array(const\
    \ ContainerT& s, const ElemT first = 'a',\n                         const ElemT\
    \ last = 'z') {\n    std::vector<int> vec(s.size() + 1);\n    std::copy(std::begin(s),\
    \ std::end(s), std::begin(vec));\n    for (auto& x : vec) x -= (int)first - 1;\n\
    \    vec.back() = 0;\n    auto ret = SA_IS(vec, (int)last - (int)first + 2);\n\
    \    ret.erase(ret.begin());\n    return ret;\n}\n// Author: https://codeforces.com/blog/entry/12796?#comment-175287\n\
    // Uses kasai's algorithm linear in time and space\nstd::vector<int> LCP(const\
    \ std::string& s, const std::vector<int>& sa) {\n    int n = s.size(), k = 0;\n\
    \    std::vector<int> lcp(n), rank(n);\n    for (int i = 0; i < n; i++) rank[sa[i]]\
    \ = i;\n    for (int i = 0; i < n; i++, k ? k-- : 0) {\n        if (rank[i] ==\
    \ n - 1) {\n            k = 0;\n            continue;\n        }\n        int\
    \ j = sa[rank[i] + 1];\n        while (i + k < n && j + k < n && s[i + k] == s[j\
    \ + k]) k++;\n        lcp[rank[i]] = k;\n    }\n    lcp[n - 1] = 0;\n    return\
    \ lcp;\n}\n// }}}\n// Number of distinct substrings {{{\n// Tested:\n// - https://judge.yosupo.jp/problem/number_of_substrings\n\
    // - https://www.spoj.com/problems/SUBST1/\nint64_t cnt_distinct_substrings(const\
    \ std::string& s) {\n    auto lcp = LCP(s, suffix_array(s, 0, 255));\n    return\
    \ s.size() * (int64_t) (s.size() + 1) / 2\n        - std::accumulate(lcp.begin(),\
    \ lcp.end(), 0LL);\n}\n// }}}\n// K-th distinct substring {{{\n// Tested:\n//\
    \ - https://cses.fi/problemset/task/2108\n// - https://www.spoj.com/problems/SUBLEX/\n\
    \n// Consider all distinct substring of string `s` in lexicographically increasing\n\
    // order. Find k-th substring.\n//\n// Preprocessing: O(N)\n// Each query: O(log(N))\n\
    //\n// Returns {start index, length}. If not found -> {-1, -1}\nstd::vector<std::pair<int,int>>\
    \ kth_distinct_substring(\n        const std::string& s,\n        const std::vector<int64_t>&\
    \ ks) {\n    if (s.empty()) {\n        return {};\n    }\n    auto sa = suffix_array(s,\
    \ 0, 255);\n    auto lcp = LCP(s, sa);\n    int n = s.size();\n    \n    // for\
    \ each suffix (in increasing order), we count how many new distinct\n    // substrings\
    \ it create\n    std::vector<int64_t> n_new_substrs(n);\n    for (int i = 0; i\
    \ < n; ++i) {\n        int substr_len = n - sa[i];\n        int new_substr_start\
    \ = (i > 0 ? lcp[i-1] : 0);\n        n_new_substrs[i] = substr_len - new_substr_start;\n\
    \    }\n    std::partial_sum(n_new_substrs.begin(), n_new_substrs.end(), n_new_substrs.begin());\n\
    \n    std::vector<std::pair<int,int>> res;\n    for (int64_t k : ks) {\n     \
    \   if (k > *n_new_substrs.rbegin()) {\n            res.emplace_back(-1, -1);\n\
    \        } else {\n            int i = std::lower_bound(n_new_substrs.begin(),\
    \ n_new_substrs.end(), k) - n_new_substrs.begin();\n            int new_substr_start\
    \ = (i > 0 ? lcp[i-1] : 0);\n            if (i > 0) k -= n_new_substrs[i-1];\n\
    \            res.emplace_back(sa[i], new_substr_start + k);\n        }\n    }\n\
    \    return res;\n}\n// }}}\n// Count substring occurrences {{{\n// given string\
    \ S and Q queries pat_i, for each query, count how many\n// times pat_i appears\
    \ in S\n// O(min(|S|, |pat|) * log(|S|)) per query\n//\n// Tested:\n// - (yes\
    \ / no) https://cses.fi/problemset/task/2102\n// - (count) https://cses.fi/problemset/task/2103\n\
    // - (position; need RMQ) https://cses.fi/problemset/task/2104\nint cnt_occurrences(const\
    \ string& s, const vector<int>& sa, const string& pat) {\n    int n = s.size(),\
    \ m = pat.size();\n    assert(n == (int) sa.size());\n    if (n < m) return 0;\n\
    \ \n    auto f = [&] (int start) {  // compare S[start..] and pat[0..]\n     \
    \   for (int i = 0; start + i < n && i < m; ++i) {\n            if (s[start +\
    \ i] < pat[i]) return true;\n            if (s[start + i] > pat[i]) return false;\n\
    \        }\n        return n - start < m;\n    };\n    auto g = [&] (int start)\
    \ {\n        for (int i = 0; start + i < n && i < m; ++i) {\n            if (s[start\
    \ + i] > pat[i]) return false;\n        }\n        return true;\n    };\n    auto\
    \ l = std::partition_point(sa.begin(), sa.end(), f);\n    auto r = std::partition_point(l,\
    \ sa.end(), g);\n    // To find first occurrence, return min of sa in range [l,\
    \ r)\n    // See https://cses.fi/problemset/task/2104\n    return std::distance(l,\
    \ r);\n}\n// }}}\n// Count substring occurrences using hash {{{\n// If hash array\
    \ can be pre-computed, can answer each query in\n// O(log(|S|) * log(|S| + |pat|)\n\
    // Tested\n// - https://oj.vnoi.info/problem/icpc22_mt_b\n#include \"./hash.h\"\
    \nint cnt_occurrences_hash(\n        const vector<int>& sa,        // suffix array\n\
    \        const HashGenerator& gen,\n        const string& s,\n        const vector<Hash>&\
    \ hash_s,   // hash of `s`, generated with `gen`\n        const string_view& pat,\n\
    \        const vector<Hash>& hash_pat  // hash of `pat`, generated with `gen`\n\
    \        ) {\n    int n = s.size(), len = pat.size();\n    assert(len == (int)\
    \ hash_pat.size());\n    assert(n == (int) sa.size());\n    if (n < len) return\
    \ 0;\n\n    // f(start) = compare string S[start..] and pat[0..len-1]\n    auto\
    \ f = [&] (int start) {\n        return gen.cmp(\n                s, hash_s, start,\
    \ n-1,\n                pat, hash_pat, 0, len-1) < 0;\n    };\n    // g(start)\
    \ = true if S[start..] == pat[0..]\n    auto g = [&] (int start) {\n        int\
    \ max_len = std::min(n - start, len);\n        return gen.cmp(\n             \
    \   s, hash_s, start, start + max_len - 1,\n                pat, hash_pat, 0,\
    \ max_len-1) == 0;\n    };\n    auto l = std::partition_point(sa.begin(), sa.end(),\
    \ f);\n    auto r = std::partition_point(l, sa.end(), g);\n    return std::distance(l,\
    \ r);\n}\n// }}}\n// Returns length of LCS of strings s & t {{{\n// O(N)\n// Tested:\n\
    // - https://www.spoj.com/problems/LCS/\n// - https://www.spoj.com/problems/ADAPHOTO/\n\
    int longestCommonSubstring(const string& s, const string& t) {\n    char c = 127;\n\
    \    string combined = s + c + t;\n    auto sa = suffix_array(combined, 0, 127);\n\
    \    auto lcp = LCP(combined, sa);\n \n    // s -> 0 .. |s|-1\n    // 255 -> |s|\n\
    \    // t -> |s|+1 ..\n    int ls = s.size(), lcombined = combined.size();\n \
    \   auto is_s = [&] (int id) { return sa[id] < ls; };\n    auto is_t = [&] (int\
    \ id) { return sa[id] > ls; };\n \n    assert(sa[lcombined - 1] == ls);\n \n \
    \   int res = 0;\n    for (int i = 0; i < lcombined - 2; ++i) {\n        if ((is_s(i)\
    \ && is_t(i+1)) || (is_s(i+1) && is_t(i))) {\n            res = max(res, lcp[i]);\n\
    \        }\n    }\n    return res;\n}\n// }}}\n// Returns length of LCS of n strings\
    \ {{{\n// Tested:\n// - https://www.spoj.com/problems/LCS2/\n// - https://www.spoj.com/problems/LONGCS\n\
    #include \"../DataStructure/RMQ.h\"\nint longestCommonSubstring(const std::vector<std::string>\
    \ strs) {\n    char c = 127;\n    string combined = \"\";\n    vector<int> ids;\n\
    \    for (size_t i = 0; i < strs.size(); ++i) {\n        const auto& s = strs[i];\n\
    \        combined += s;\n        while (ids.size() < combined.size()) ids.push_back(i);\n\
    \n        combined += c;\n        ids.push_back(-1);\n\n        --c;\n    }\n\
    \    auto sa = suffix_array(combined, 0, 127);\n    auto lcp = LCP(combined, sa);\n\
    \    RMQ<int, _min> rmq(lcp);\n\n    // count frequency of i-th string in current\
    \ window\n    std::vector<int> cnt(strs.size(), 0);\n    int strs_in_window =\
    \ 0;\n    auto add = [&] (int i) {\n        if (i < 0) return;\n        ++cnt[i];\n\
    \        if (cnt[i] == 1) ++strs_in_window;\n    };\n    auto rem = [&] (int i)\
    \ {\n        if (i < 0) return;\n        --cnt[i];\n        if (cnt[i] == 0) --strs_in_window;\n\
    \    };\n\n    int i = 0, j = -1;\n    int lcombined = combined.size();\n    int\
    \ n = strs.size();\n    int res = 0;\n    while (i < lcombined - 1) {\n      \
    \  while (j + 1 < lcombined - 1 && strs_in_window < n) {\n            ++j;\n \
    \           add(ids[sa[j]]);\n        }\n        if (strs_in_window == n) {\n\
    \            res = max(res, rmq.get(i, j));\n        }\n\n        rem(ids[sa[i]]);\
    \ ++i;\n    }\n    return res;\n}\n// }}}\n//Example Code\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/suffixarray\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#include \"../SuffixArray.h\"\n\nint32_t main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    string s; cin >> s;\n    auto sa = suffix_array(s, 'a', 'z');\n\
    \    for (int x : sa) std::cout << x << ' ';\n    cout << endl;\n    return 0;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: String/SuffixArray.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/SuffixArray.cpp
layout: document
redirect_from:
- /library/String/SuffixArray.cpp
- /library/String/SuffixArray.cpp.html
title: String/SuffixArray.cpp
---
