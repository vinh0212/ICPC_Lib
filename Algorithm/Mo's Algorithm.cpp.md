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
  bundledCode: "#line 1 \"Algorithm/Mo's Algorithm.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Structure to represent a query\nstruct Query {\n  \
    \  int l, r, idx; // l: left index, r: right index, idx: original query index\n\
    };\n\n// Comparator function to sort queries according to Mo's algorithm\nbool\
    \ mo_cmp(const Query &a, const Query &b, int block_size) {\n    if (a.l / block_size\
    \ != b.l / block_size)\n        return a.l / block_size < b.l / block_size;\n\
    \    // If in the same block, sort by R value\n    // Alternate sorting order\
    \ for even and odd blocks to optimize cache\n    if ((a.l / block_size) & 1)\n\
    \        return a.r > b.r;\n    else\n        return a.r < b.r;\n}\n\n// Function\
    \ to perform Mo's algorithm\nvector<long long> mos_algorithm(int n, vector<Query>\
    \ &queries, vector<int> &array) {\n    int q = queries.size();\n    vector<long\
    \ long> answers(q);\n    \n    // Determine block size\n    int block_size = sqrt(n)\
    \ + 1;\n    \n    // Sort queries using the comparator\n    sort(queries.begin(),\
    \ queries.end(), [&](const Query &a, const Query &b) -> bool {\n        return\
    \ mo_cmp(a, b, block_size);\n    });\n    \n    // Initialize current range [curr_l,\
    \ curr_r]\n    int curr_l = 0, curr_r = -1;\n    \n    // Example: Count of distinct\
    \ elements\n    // Modify these variables and functions based on the problem\n\
    \    int distinct = 0;\n    // Assuming array elements are in the range [1, max_val]\n\
    \    int max_val = *max_element(array.begin(), array.end());\n    vector<int>\
    \ freq(max_val + 1, 0);\n    // Lambda to add an element to the current range\n\
    \    auto add = [&](int idx) {\n        freq[array[idx]]++;\n        if (freq[array[idx]]\
    \ == 1)\n            distinct++;\n    };\n    // Lambda to remove an element from\
    \ the current range\n    auto remove_fn = [&](int idx) {\n        freq[array[idx]]--;\n\
    \        if (freq[array[idx]] == 0)\n            distinct--;\n    };\n    \n \
    \   // Process each query\n    for(auto &query : queries){\n        int L = query.l;\n\
    \        int R = query.r;\n        \n        // Expand to the left\n        while(curr_l\
    \ > L) add(--curr_l);\n        // Expand to the right\n        while(curr_r <\
    \ R) add(++curr_r);\n        // Contract from the left\n        while(curr_l <\
    \ L) remove_fn(curr_l++);\n        // Contract from the right\n        while(curr_r\
    \ > R) remove_fn(curr_r--);\n        \n        // Store the answer for the current\
    \ query\n        answers[query.idx] = distinct; // Replace 'distinct' with the\
    \ required metric\n    }\n    \n    return answers;\n}\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n    \n    int n, q;\n    cin >> n >> q;\n    vector<int> array(n);\n\
    \    for(auto &x : array) cin >> x;\n    \n    vector<Query> queries(q);\n   \
    \ for(int i = 0; i < q; ++i){\n        cin >> queries[i].l >> queries[i].r;\n\
    \        queries[i].l--; // Convert to 0-based index\n        queries[i].r--;\
    \ // Convert to 0-based index\n        queries[i].idx = i;\n    }\n    \n    vector<long\
    \ long> answers = mos_algorithm(n, queries, array);\n    \n    for(auto &ans :\
    \ answers) cout << ans << \"\\n\";\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// Structure to represent\
    \ a query\nstruct Query {\n    int l, r, idx; // l: left index, r: right index,\
    \ idx: original query index\n};\n\n// Comparator function to sort queries according\
    \ to Mo's algorithm\nbool mo_cmp(const Query &a, const Query &b, int block_size)\
    \ {\n    if (a.l / block_size != b.l / block_size)\n        return a.l / block_size\
    \ < b.l / block_size;\n    // If in the same block, sort by R value\n    // Alternate\
    \ sorting order for even and odd blocks to optimize cache\n    if ((a.l / block_size)\
    \ & 1)\n        return a.r > b.r;\n    else\n        return a.r < b.r;\n}\n\n\
    // Function to perform Mo's algorithm\nvector<long long> mos_algorithm(int n,\
    \ vector<Query> &queries, vector<int> &array) {\n    int q = queries.size();\n\
    \    vector<long long> answers(q);\n    \n    // Determine block size\n    int\
    \ block_size = sqrt(n) + 1;\n    \n    // Sort queries using the comparator\n\
    \    sort(queries.begin(), queries.end(), [&](const Query &a, const Query &b)\
    \ -> bool {\n        return mo_cmp(a, b, block_size);\n    });\n    \n    // Initialize\
    \ current range [curr_l, curr_r]\n    int curr_l = 0, curr_r = -1;\n    \n   \
    \ // Example: Count of distinct elements\n    // Modify these variables and functions\
    \ based on the problem\n    int distinct = 0;\n    // Assuming array elements\
    \ are in the range [1, max_val]\n    int max_val = *max_element(array.begin(),\
    \ array.end());\n    vector<int> freq(max_val + 1, 0);\n    // Lambda to add an\
    \ element to the current range\n    auto add = [&](int idx) {\n        freq[array[idx]]++;\n\
    \        if (freq[array[idx]] == 1)\n            distinct++;\n    };\n    // Lambda\
    \ to remove an element from the current range\n    auto remove_fn = [&](int idx)\
    \ {\n        freq[array[idx]]--;\n        if (freq[array[idx]] == 0)\n       \
    \     distinct--;\n    };\n    \n    // Process each query\n    for(auto &query\
    \ : queries){\n        int L = query.l;\n        int R = query.r;\n        \n\
    \        // Expand to the left\n        while(curr_l > L) add(--curr_l);\n   \
    \     // Expand to the right\n        while(curr_r < R) add(++curr_r);\n     \
    \   // Contract from the left\n        while(curr_l < L) remove_fn(curr_l++);\n\
    \        // Contract from the right\n        while(curr_r > R) remove_fn(curr_r--);\n\
    \        \n        // Store the answer for the current query\n        answers[query.idx]\
    \ = distinct; // Replace 'distinct' with the required metric\n    }\n    \n  \
    \  return answers;\n}\n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n\
    \    \n    int n, q;\n    cin >> n >> q;\n    vector<int> array(n);\n    for(auto\
    \ &x : array) cin >> x;\n    \n    vector<Query> queries(q);\n    for(int i =\
    \ 0; i < q; ++i){\n        cin >> queries[i].l >> queries[i].r;\n        queries[i].l--;\
    \ // Convert to 0-based index\n        queries[i].r--; // Convert to 0-based index\n\
    \        queries[i].idx = i;\n    }\n    \n    vector<long long> answers = mos_algorithm(n,\
    \ queries, array);\n    \n    for(auto &ans : answers) cout << ans << \"\\n\"\
    ;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/Mo's Algorithm.cpp
  requiredBy: []
  timestamp: '2024-11-15 16:59:08+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/Mo's Algorithm.cpp
layout: document
redirect_from:
- /library/Algorithm/Mo's Algorithm.cpp
- /library/Algorithm/Mo's Algorithm.cpp.html
title: Algorithm/Mo's Algorithm.cpp
---
