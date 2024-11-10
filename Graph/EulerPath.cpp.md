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
  bundledCode: "#line 1 \"Graph/EulerPath.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntypedef vector<int> vi;\n\nint N;\nvector<vi> AL; // Directed graph,\
    \ undirected graph means add edge twice\n\nvi hierholzer(int s)\n{\n    vi ans,\
    \ idx(N, 0), st;\n    st.push_back(s);\n    while (!st.empty())\n    {\n     \
    \   int u = st.back();\n        if (idx[u] < (int)AL[u].size())\n        { //\
    \ still has neighbor\n            st.push_back(AL[u][idx[u]]);\n            ++idx[u];\n\
    \        }\n        else\n        {\n            ans.push_back(u);\n         \
    \   st.pop_back();\n        }\n    }\n    reverse(ans.begin(), ans.end());\n \
    \   return ans;\n}\n\nvi hierholzerUndirected() //\n{\n    vi ans, idx(N, 0),\
    \ st;\n    st.push_back(0);\n    while (!st.empty())\n    {\n        int u = st.back();\n\
    \        if (idx[u] < (int)AL[u].size())\n        { // still has neighbor\n  \
    \          int v = AL[u][idx[u]];\n            ++idx[u];\n            for (int\
    \ i = 0; i < (int)AL[v].size(); ++i)\n            {\n                if (AL[v][i]\
    \ == u)\n                {\n                    AL[v].erase(AL[v].begin() + i);\n\
    \                    break;\n                }\n            }\n            st.push_back(v);\n\
    \        }\n        else\n        {\n            ans.push_back(u);\n         \
    \   st.pop_back();\n        }\n    }\n    reverse(ans.begin(), ans.end());\n \
    \   return ans;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntypedef vector<int> vi;\n\
    \nint N;\nvector<vi> AL; // Directed graph, undirected graph means add edge twice\n\
    \nvi hierholzer(int s)\n{\n    vi ans, idx(N, 0), st;\n    st.push_back(s);\n\
    \    while (!st.empty())\n    {\n        int u = st.back();\n        if (idx[u]\
    \ < (int)AL[u].size())\n        { // still has neighbor\n            st.push_back(AL[u][idx[u]]);\n\
    \            ++idx[u];\n        }\n        else\n        {\n            ans.push_back(u);\n\
    \            st.pop_back();\n        }\n    }\n    reverse(ans.begin(), ans.end());\n\
    \    return ans;\n}\n\nvi hierholzerUndirected() //\n{\n    vi ans, idx(N, 0),\
    \ st;\n    st.push_back(0);\n    while (!st.empty())\n    {\n        int u = st.back();\n\
    \        if (idx[u] < (int)AL[u].size())\n        { // still has neighbor\n  \
    \          int v = AL[u][idx[u]];\n            ++idx[u];\n            for (int\
    \ i = 0; i < (int)AL[v].size(); ++i)\n            {\n                if (AL[v][i]\
    \ == u)\n                {\n                    AL[v].erase(AL[v].begin() + i);\n\
    \                    break;\n                }\n            }\n            st.push_back(v);\n\
    \        }\n        else\n        {\n            ans.push_back(u);\n         \
    \   st.pop_back();\n        }\n    }\n    reverse(ans.begin(), ans.end());\n \
    \   return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/EulerPath.cpp
  requiredBy: []
  timestamp: '2024-11-10 11:32:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/EulerPath.cpp
layout: document
redirect_from:
- /library/Graph/EulerPath.cpp
- /library/Graph/EulerPath.cpp.html
title: Graph/EulerPath.cpp
---
