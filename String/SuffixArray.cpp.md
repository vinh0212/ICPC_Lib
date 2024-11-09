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
  bundledCode: "#line 1 \"String/SuffixArray.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntypedef pair<int, int> ii;\ntypedef vector<int> vi;\n\nclass\
    \ SuffixArray\n{\nprivate:\n    vi RA; // rank array\n\n    void countingSort(int\
    \ k)\n    {                                       // O(n)\n        int maxi =\
    \ max(300, n);             // up to 255 ASCII chars\n        vi c(maxi, 0);  \
    \                    // clear frequency table\n        for (int i = 0; i < n;\
    \ ++i)         // count the frequency\n            ++c[i + k < n ? RA[i + k] :\
    \ 0]; // of each integer rank\n        for (int i = 0, sum = 0; i < maxi; ++i)\n\
    \        {\n            int t = c[i];\n            c[i] = sum;\n            sum\
    \ += t;\n        }\n        vi tempSA(n);\n        for (int i = 0; i < n; ++i)\
    \ // sort SA\n            tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];\n\
    \        swap(SA, tempSA); // update SA\n    }\n\n    void constructSA()\n   \
    \ { // can go up to 400K chars\n        SA.resize(n);\n        iota(SA.begin(),\
    \ SA.end(), 0); // the initial SA\n        RA.resize(n);\n        for (int i =\
    \ 0; i < n; ++i)\n            RA[i] = T[i]; // initial rankings\n        for (int\
    \ k = 1; k < n; k <<= 1)\n        { // repeat log_2 n times\n            // this\
    \ is actually radix sort\n            countingSort(k); // sort by 2nd item\n \
    \           countingSort(0); // stable-sort by 1st item\n            vi tempRA(n);\n\
    \            int r = 0;\n            tempRA[SA[0]] = r;          // re-ranking\
    \ process\n            for (int i = 1; i < n; ++i) // compare adj suffixes\n \
    \               tempRA[SA[i]] =         // same pair => same rank r; otherwise,\
    \ increase r\n                    ((RA[SA[i]] == RA[SA[i - 1]]) && (RA[SA[i] +\
    \ k] == RA[SA[i - 1] + k])) ? r : ++r;\n            swap(RA, tempRA); // update\
    \ RA\n            if (RA[SA[n - 1]] == n - 1)\n                break; // nice\
    \ optimization\n        }\n    }\n\n    void computeLCP()\n    {\n        vi Phi(n);\n\
    \        vi PLCP(n);\n        PLCP.resize(n);\n        Phi[SA[0]] = -1;      \
    \      // default value\n        for (int i = 1; i < n; ++i) // compute Phi in\
    \ O(n)\n            Phi[SA[i]] = SA[i - 1]; // remember prev suffix\n        for\
    \ (int i = 0, L = 0; i < n; ++i)\n        { // compute PLCP in O(n)\n        \
    \    if (Phi[i] == -1)\n            {\n                PLCP[i] = 0;\n        \
    \        continue;\n            } // special case\n            while ((i + L <\
    \ n) && (Phi[i] + L < n) && (T[i + L] == T[Phi[i] + L]))\n                ++L;\
    \ // L incr max n times\n            PLCP[i] = L;\n            L = max(L - 1,\
    \ 0); // L dec max n times\n        }\n        LCP.resize(n);\n        for (int\
    \ i = 0; i < n; ++i) // compute LCP in O(n)\n            LCP[i] = PLCP[SA[i]];\
    \   // restore PLCP\n    }\n\npublic:\n    const char *T; // the input string\n\
    \    const int n;   // the length of T\n    vi SA;         // Suffix Array\n \
    \   vi LCP;        // of adj sorted suffixes\n\n    SuffixArray(const char *initialT,\
    \ const int _n) : T(initialT), n(_n)\n    {\n        constructSA(); // O(n log\
    \ n)\n        computeLCP();  // O(n)\n    }\n\n    ii stringMatching(const char\
    \ *P)\n    {                           // in O(m log n)\n        int m = (int)strlen(P);\
    \ // usually, m < n\n        int lo = 0, hi = n - 1; // range = [0..n-1]\n   \
    \     while (lo < hi)\n        {                                         // find\
    \ lower bound\n            int mid = (lo + hi) / 2;              // this is round\
    \ down\n            int res = strncmp(T + SA[mid], P, m); // P in suffix SA[mid]?\n\
    \            (res >= 0) ? hi = mid : lo = mid + 1; // notice the >= sign\n   \
    \     }\n        if (strncmp(T + SA[lo], P, m) != 0)\n            return {-1,\
    \ -1}; // if not found\n        ii ans;\n        ans.first = lo;\n        hi =\
    \ n - 1; // range = [lo..n-1]\n        while (lo < hi)\n        { // now find\
    \ upper bound\n            int mid = (lo + hi) / 2;\n            int res = strncmp(T\
    \ + SA[mid], P, m);\n            (res > 0) ? hi = mid : lo = mid + 1; // notice\
    \ the > sign\n        }\n        if (strncmp(T + SA[hi], P, m) != 0)\n       \
    \     --hi; // special case\n        ans.second = hi;\n        return ans; //\
    \ returns (lb, ub)\n    } // where P is found\n\n    ii LRS() //longest repeated\
    \ substring\n    { // (LRS length, index)\n        int idx = 0, maxLCP = -1;\n\
    \        for (int i = 1; i < n; ++i) // O(n), start from i = 1\n            if\
    \ (LCP[i] > maxLCP)\n                maxLCP = LCP[i], idx = i;\n        return\
    \ {maxLCP, idx};\n    }\n\n    ii LCS(int split_idx)\n    { // (LCS length, index)\n\
    \        int idx = 0, maxLCP = -1;\n        for (int i = 1; i < n; ++i)\n    \
    \    { // O(n), start from i = 1\n            // if suffix SA[i] and suffix SA[i-1]\
    \ came from the same string, skip\n            if ((SA[i] < split_idx) == (SA[i\
    \ - 1] < split_idx))\n                continue;\n            if (LCP[i] > maxLCP)\n\
    \                maxLCP = LCP[i], idx = i;\n        }\n        return {maxLCP,\
    \ idx};\n    }\n};\n\nconst int MAX_N = 450010; // can go up to 450K chars\n\n\
    char T[MAX_N];\nchar P[MAX_N];\nchar LRS_ans[MAX_N];\nchar LCS_ans[MAX_N];\n\n\
    int main()\n{\n    cin >> T;        // read T\n    int n = (int)strlen(T); //\
    \ count n\n    T[n++] = '$';           // add terminating symbol\n    SuffixArray\
    \ S(T, n);    // construct SA+LCP\n\n    cout << \"T = '\" << T << \"'\\n\";\n\
    \    cout << \" i SA[i] LCP[i]   Suffix SA[i]\\n\";\n    for (int i = 0; i < n;\
    \ ++i)\n        cout << setw(2) << i << \"    \" \n             << setw(2) <<\
    \ S.SA[i] << \"    \" \n             << setw(2) << S.LCP[i] << \"    \" \n   \
    \          << (T + S.SA[i]) << \"\\n\";\n\n    // String Matching demo, we will\
    \ try to find P in T\n    strcpy(P, \"A\");\n    auto [lb, ub] = S.stringMatching(P);\n\
    \    if ((lb != -1) && (ub != -1))\n    {\n        cout << \"P = '\" << P << \"\
    ' is found SA[\" << lb << \"..\" << ub << \"] of T = '\" << T << \"'\\n\";\n \
    \       cout << \"They are:\\n\";\n        for (int i = lb; i <= ub; ++i)\n  \
    \          cout << \"  \" << (T + S.SA[i]) << \"\\n\";\n    }\n    else\n    \
    \    cout << \"P = '\" << P << \"' is not found in T = '\" << T << \"'\\n\";\n\
    \n    // LRS demo, find the LRS of T\n    auto [LRS_len, LRS_idx] = S.LRS();\n\
    \    strncpy(LRS_ans, T + S.SA[LRS_idx], LRS_len);\n    LRS_ans[LRS_len] = '\\\
    0'; // null-terminate the string\n    cout << \"The LRS is '\" << LRS_ans << \"\
    ' with length = \" << LRS_len << \"\\n\";\n\n    // LCS demo, find the LCS of\
    \ (T, P)\n    strcpy(P, \"CATA\");\n    int m = (int)strlen(P);\n    strcat(T,\
    \ P);       // append P to T\n    strcat(T, \"#\");     // add '#' at the back\n\
    \    n = (int)strlen(T); // update n\n\n    // reconstruct SA of the combined\
    \ strings\n    SuffixArray S2(T, n); // reconstruct SA+LCP\n    int split_idx\
    \ = n - m - 1;\n    cout << \"T+P = '\" << T << \"'\\n\";\n    cout << \" i SA[i]\
    \ LCP[i] From  Suffix SA[i]\\n\";\n    for (int i = 0; i < n; ++i)\n        cout\
    \ << setw(2) << i << \"    \" \n             << setw(2) << S2.SA[i] << \"    \"\
    \ \n             << setw(2) << S2.LCP[i] << \"    \" \n             << (S2.SA[i]\
    \ < split_idx ? 1 : 2) << \"    \" \n             << (T + S2.SA[i]) << \"\\n\"\
    ;\n\n    auto [LCS_len, LCS_idx] = S2.LCS(split_idx);\n    strncpy(LCS_ans, T\
    \ + S2.SA[LCS_idx], LCS_len);\n    LCS_ans[LCS_len] = '\\0'; // null-terminate\
    \ the string\n    cout << \"The LCS is '\" << LCS_ans << \"' with length = \"\
    \ << LCS_len << \"\\n\";\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntypedef pair<int, int>\
    \ ii;\ntypedef vector<int> vi;\n\nclass SuffixArray\n{\nprivate:\n    vi RA; //\
    \ rank array\n\n    void countingSort(int k)\n    {                          \
    \             // O(n)\n        int maxi = max(300, n);             // up to 255\
    \ ASCII chars\n        vi c(maxi, 0);                      // clear frequency\
    \ table\n        for (int i = 0; i < n; ++i)         // count the frequency\n\
    \            ++c[i + k < n ? RA[i + k] : 0]; // of each integer rank\n       \
    \ for (int i = 0, sum = 0; i < maxi; ++i)\n        {\n            int t = c[i];\n\
    \            c[i] = sum;\n            sum += t;\n        }\n        vi tempSA(n);\n\
    \        for (int i = 0; i < n; ++i) // sort SA\n            tempSA[c[SA[i] +\
    \ k < n ? RA[SA[i] + k] : 0]++] = SA[i];\n        swap(SA, tempSA); // update\
    \ SA\n    }\n\n    void constructSA()\n    { // can go up to 400K chars\n    \
    \    SA.resize(n);\n        iota(SA.begin(), SA.end(), 0); // the initial SA\n\
    \        RA.resize(n);\n        for (int i = 0; i < n; ++i)\n            RA[i]\
    \ = T[i]; // initial rankings\n        for (int k = 1; k < n; k <<= 1)\n     \
    \   { // repeat log_2 n times\n            // this is actually radix sort\n  \
    \          countingSort(k); // sort by 2nd item\n            countingSort(0);\
    \ // stable-sort by 1st item\n            vi tempRA(n);\n            int r = 0;\n\
    \            tempRA[SA[0]] = r;          // re-ranking process\n            for\
    \ (int i = 1; i < n; ++i) // compare adj suffixes\n                tempRA[SA[i]]\
    \ =         // same pair => same rank r; otherwise, increase r\n             \
    \       ((RA[SA[i]] == RA[SA[i - 1]]) && (RA[SA[i] + k] == RA[SA[i - 1] + k]))\
    \ ? r : ++r;\n            swap(RA, tempRA); // update RA\n            if (RA[SA[n\
    \ - 1]] == n - 1)\n                break; // nice optimization\n        }\n  \
    \  }\n\n    void computeLCP()\n    {\n        vi Phi(n);\n        vi PLCP(n);\n\
    \        PLCP.resize(n);\n        Phi[SA[0]] = -1;            // default value\n\
    \        for (int i = 1; i < n; ++i) // compute Phi in O(n)\n            Phi[SA[i]]\
    \ = SA[i - 1]; // remember prev suffix\n        for (int i = 0, L = 0; i < n;\
    \ ++i)\n        { // compute PLCP in O(n)\n            if (Phi[i] == -1)\n   \
    \         {\n                PLCP[i] = 0;\n                continue;\n       \
    \     } // special case\n            while ((i + L < n) && (Phi[i] + L < n) &&\
    \ (T[i + L] == T[Phi[i] + L]))\n                ++L; // L incr max n times\n \
    \           PLCP[i] = L;\n            L = max(L - 1, 0); // L dec max n times\n\
    \        }\n        LCP.resize(n);\n        for (int i = 0; i < n; ++i) // compute\
    \ LCP in O(n)\n            LCP[i] = PLCP[SA[i]];   // restore PLCP\n    }\n\n\
    public:\n    const char *T; // the input string\n    const int n;   // the length\
    \ of T\n    vi SA;         // Suffix Array\n    vi LCP;        // of adj sorted\
    \ suffixes\n\n    SuffixArray(const char *initialT, const int _n) : T(initialT),\
    \ n(_n)\n    {\n        constructSA(); // O(n log n)\n        computeLCP();  //\
    \ O(n)\n    }\n\n    ii stringMatching(const char *P)\n    {                 \
    \          // in O(m log n)\n        int m = (int)strlen(P); // usually, m < n\n\
    \        int lo = 0, hi = n - 1; // range = [0..n-1]\n        while (lo < hi)\n\
    \        {                                         // find lower bound\n     \
    \       int mid = (lo + hi) / 2;              // this is round down\n        \
    \    int res = strncmp(T + SA[mid], P, m); // P in suffix SA[mid]?\n         \
    \   (res >= 0) ? hi = mid : lo = mid + 1; // notice the >= sign\n        }\n \
    \       if (strncmp(T + SA[lo], P, m) != 0)\n            return {-1, -1}; // if\
    \ not found\n        ii ans;\n        ans.first = lo;\n        hi = n - 1; //\
    \ range = [lo..n-1]\n        while (lo < hi)\n        { // now find upper bound\n\
    \            int mid = (lo + hi) / 2;\n            int res = strncmp(T + SA[mid],\
    \ P, m);\n            (res > 0) ? hi = mid : lo = mid + 1; // notice the > sign\n\
    \        }\n        if (strncmp(T + SA[hi], P, m) != 0)\n            --hi; //\
    \ special case\n        ans.second = hi;\n        return ans; // returns (lb,\
    \ ub)\n    } // where P is found\n\n    ii LRS() //longest repeated substring\n\
    \    { // (LRS length, index)\n        int idx = 0, maxLCP = -1;\n        for\
    \ (int i = 1; i < n; ++i) // O(n), start from i = 1\n            if (LCP[i] >\
    \ maxLCP)\n                maxLCP = LCP[i], idx = i;\n        return {maxLCP,\
    \ idx};\n    }\n\n    ii LCS(int split_idx)\n    { // (LCS length, index)\n  \
    \      int idx = 0, maxLCP = -1;\n        for (int i = 1; i < n; ++i)\n      \
    \  { // O(n), start from i = 1\n            // if suffix SA[i] and suffix SA[i-1]\
    \ came from the same string, skip\n            if ((SA[i] < split_idx) == (SA[i\
    \ - 1] < split_idx))\n                continue;\n            if (LCP[i] > maxLCP)\n\
    \                maxLCP = LCP[i], idx = i;\n        }\n        return {maxLCP,\
    \ idx};\n    }\n};\n\nconst int MAX_N = 450010; // can go up to 450K chars\n\n\
    char T[MAX_N];\nchar P[MAX_N];\nchar LRS_ans[MAX_N];\nchar LCS_ans[MAX_N];\n\n\
    int main()\n{\n    cin >> T;        // read T\n    int n = (int)strlen(T); //\
    \ count n\n    T[n++] = '$';           // add terminating symbol\n    SuffixArray\
    \ S(T, n);    // construct SA+LCP\n\n    cout << \"T = '\" << T << \"'\\n\";\n\
    \    cout << \" i SA[i] LCP[i]   Suffix SA[i]\\n\";\n    for (int i = 0; i < n;\
    \ ++i)\n        cout << setw(2) << i << \"    \" \n             << setw(2) <<\
    \ S.SA[i] << \"    \" \n             << setw(2) << S.LCP[i] << \"    \" \n   \
    \          << (T + S.SA[i]) << \"\\n\";\n\n    // String Matching demo, we will\
    \ try to find P in T\n    strcpy(P, \"A\");\n    auto [lb, ub] = S.stringMatching(P);\n\
    \    if ((lb != -1) && (ub != -1))\n    {\n        cout << \"P = '\" << P << \"\
    ' is found SA[\" << lb << \"..\" << ub << \"] of T = '\" << T << \"'\\n\";\n \
    \       cout << \"They are:\\n\";\n        for (int i = lb; i <= ub; ++i)\n  \
    \          cout << \"  \" << (T + S.SA[i]) << \"\\n\";\n    }\n    else\n    \
    \    cout << \"P = '\" << P << \"' is not found in T = '\" << T << \"'\\n\";\n\
    \n    // LRS demo, find the LRS of T\n    auto [LRS_len, LRS_idx] = S.LRS();\n\
    \    strncpy(LRS_ans, T + S.SA[LRS_idx], LRS_len);\n    LRS_ans[LRS_len] = '\\\
    0'; // null-terminate the string\n    cout << \"The LRS is '\" << LRS_ans << \"\
    ' with length = \" << LRS_len << \"\\n\";\n\n    // LCS demo, find the LCS of\
    \ (T, P)\n    strcpy(P, \"CATA\");\n    int m = (int)strlen(P);\n    strcat(T,\
    \ P);       // append P to T\n    strcat(T, \"#\");     // add '#' at the back\n\
    \    n = (int)strlen(T); // update n\n\n    // reconstruct SA of the combined\
    \ strings\n    SuffixArray S2(T, n); // reconstruct SA+LCP\n    int split_idx\
    \ = n - m - 1;\n    cout << \"T+P = '\" << T << \"'\\n\";\n    cout << \" i SA[i]\
    \ LCP[i] From  Suffix SA[i]\\n\";\n    for (int i = 0; i < n; ++i)\n        cout\
    \ << setw(2) << i << \"    \" \n             << setw(2) << S2.SA[i] << \"    \"\
    \ \n             << setw(2) << S2.LCP[i] << \"    \" \n             << (S2.SA[i]\
    \ < split_idx ? 1 : 2) << \"    \" \n             << (T + S2.SA[i]) << \"\\n\"\
    ;\n\n    auto [LCS_len, LCS_idx] = S2.LCS(split_idx);\n    strncpy(LCS_ans, T\
    \ + S2.SA[LCS_idx], LCS_len);\n    LCS_ans[LCS_len] = '\\0'; // null-terminate\
    \ the string\n    cout << \"The LCS is '\" << LCS_ans << \"' with length = \"\
    \ << LCS_len << \"\\n\";\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/SuffixArray.cpp
  requiredBy: []
  timestamp: '2024-11-09 21:40:45+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/SuffixArray.cpp
layout: document
redirect_from:
- /library/String/SuffixArray.cpp
- /library/String/SuffixArray.cpp.html
title: String/SuffixArray.cpp
---
