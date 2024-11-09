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
  bundledCode: "#line 1 \"DSU/DisjointSet.cpp\"\n// Union-Find Disjoint Sets Library\
    \ written in OOP manner, using both path compression and union by rank heuristics\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\ntypedef vector<int> vi;\n\n\
    class UnionFind\n{ // OOP style\nprivate:\n    vi p, rank, setSize; // vi p is\
    \ the key part\n    int numSets;\n\npublic:\n    UnionFind(int N)\n    {\n   \
    \     p.assign(N, 0);\n        for (int i = 0; i < N; ++i)\n            p[i] =\
    \ i;         // fto(i,0,N-1)\n        rank.assign(N, 0);    // optional speedup\n\
    \        setSize.assign(N, 1); // optional feature\n        numSets = N;     \
    \     // optional feature\n    }\n\n    int findSet(int i)\n    {\n        return\
    \ (p[i] == i) ? i : (p[i] = findSet(p[i]));\n        /*\n            if (p[i]\
    \ != i)\n            {\n                int root = findSet(p[i]);\n          \
    \      dist[i] += dist[p[i]];\n                p[i] = root;\n            }\n \
    \               return p[i];\n        */\n    }\n    bool isSameSet(int i, int\
    \ j) { return findSet(i) == findSet(j); }\n\n    int numDisjointSets() { return\
    \ numSets; }            // optional\n    int sizeOfSet(int i) { return setSize[findSet(i)];\
    \ } // optional\n\n    void unionSet(int i, int j)\n    {\n        if (isSameSet(i,\
    \ j))\n            return;                         // i and j are in same set\n\
    \        int x = findSet(i), y = findSet(j); // find both rep items\n        if\
    \ (rank[x] > rank[y])\n            swap(x, y); // keep x 'shorter' than y\n  \
    \      p[x] = y;       // set x under y\n        if (rank[x] == rank[y])\n   \
    \         ++rank[y];            // optional speedup\n        setSize[y] += setSize[x];\
    \ // combine set sizes at y\n        --numSets;                // a union reduces\
    \ numSets\n    }\n};\n\nint main()\n{\n    printf(\"Assume that there are 5 disjoint\
    \ sets initially\\n\");\n    UnionFind UF(5);                      // create 5\
    \ disjoint sets\n    printf(\"%d\\n\", UF.numDisjointSets()); // 5\n    UF.unionSet(0,\
    \ 1);\n    printf(\"%d\\n\", UF.numDisjointSets()); // 4\n    UF.unionSet(2, 3);\n\
    \    printf(\"%d\\n\", UF.numDisjointSets()); // 3\n    UF.unionSet(4, 3);\n \
    \   printf(\"%d\\n\", UF.numDisjointSets());                 // 2\n    printf(\"\
    isSameSet(0, 3) = %d\\n\", UF.isSameSet(0, 3)); // will return 0 (false)\n   \
    \ printf(\"isSameSet(4, 3) = %d\\n\", UF.isSameSet(4, 3)); // will return 1 (true)\n\
    \    for (int i = 0; i < 5; i++)                           // findSet will return\
    \ 1 for {0, 1} and 3 for {2, 3, 4}\n        printf(\"findSet(%d) = %d, sizeOfSet(%d)\
    \ = %d\\n\", i, UF.findSet(i), i, UF.sizeOfSet(i));\n    UF.unionSet(0, 3);\n\
    \    printf(\"%d\\n\", UF.numDisjointSets()); // 1\n    for (int i = 0; i < 5;\
    \ i++)           // findSet will return 3 for {0, 1, 2, 3, 4}\n        printf(\"\
    findSet(%d) = %d, sizeOfSet(%d) = %d\\n\", i, UF.findSet(i), i, UF.sizeOfSet(i));\n\
    \    return 0;\n}\n"
  code: "// Union-Find Disjoint Sets Library written in OOP manner, using both path\
    \ compression and union by rank heuristics\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntypedef vector<int> vi;\n\nclass UnionFind\n{ // OOP style\n\
    private:\n    vi p, rank, setSize; // vi p is the key part\n    int numSets;\n\
    \npublic:\n    UnionFind(int N)\n    {\n        p.assign(N, 0);\n        for (int\
    \ i = 0; i < N; ++i)\n            p[i] = i;         // fto(i,0,N-1)\n        rank.assign(N,\
    \ 0);    // optional speedup\n        setSize.assign(N, 1); // optional feature\n\
    \        numSets = N;          // optional feature\n    }\n\n    int findSet(int\
    \ i)\n    {\n        return (p[i] == i) ? i : (p[i] = findSet(p[i]));\n      \
    \  /*\n            if (p[i] != i)\n            {\n                int root = findSet(p[i]);\n\
    \                dist[i] += dist[p[i]];\n                p[i] = root;\n      \
    \      }\n                return p[i];\n        */\n    }\n    bool isSameSet(int\
    \ i, int j) { return findSet(i) == findSet(j); }\n\n    int numDisjointSets()\
    \ { return numSets; }            // optional\n    int sizeOfSet(int i) { return\
    \ setSize[findSet(i)]; } // optional\n\n    void unionSet(int i, int j)\n    {\n\
    \        if (isSameSet(i, j))\n            return;                         //\
    \ i and j are in same set\n        int x = findSet(i), y = findSet(j); // find\
    \ both rep items\n        if (rank[x] > rank[y])\n            swap(x, y); // keep\
    \ x 'shorter' than y\n        p[x] = y;       // set x under y\n        if (rank[x]\
    \ == rank[y])\n            ++rank[y];            // optional speedup\n       \
    \ setSize[y] += setSize[x]; // combine set sizes at y\n        --numSets;    \
    \            // a union reduces numSets\n    }\n};\n\nint main()\n{\n    printf(\"\
    Assume that there are 5 disjoint sets initially\\n\");\n    UnionFind UF(5); \
    \                     // create 5 disjoint sets\n    printf(\"%d\\n\", UF.numDisjointSets());\
    \ // 5\n    UF.unionSet(0, 1);\n    printf(\"%d\\n\", UF.numDisjointSets()); //\
    \ 4\n    UF.unionSet(2, 3);\n    printf(\"%d\\n\", UF.numDisjointSets()); // 3\n\
    \    UF.unionSet(4, 3);\n    printf(\"%d\\n\", UF.numDisjointSets());        \
    \         // 2\n    printf(\"isSameSet(0, 3) = %d\\n\", UF.isSameSet(0, 3)); //\
    \ will return 0 (false)\n    printf(\"isSameSet(4, 3) = %d\\n\", UF.isSameSet(4,\
    \ 3)); // will return 1 (true)\n    for (int i = 0; i < 5; i++)              \
    \             // findSet will return 1 for {0, 1} and 3 for {2, 3, 4}\n      \
    \  printf(\"findSet(%d) = %d, sizeOfSet(%d) = %d\\n\", i, UF.findSet(i), i, UF.sizeOfSet(i));\n\
    \    UF.unionSet(0, 3);\n    printf(\"%d\\n\", UF.numDisjointSets()); // 1\n \
    \   for (int i = 0; i < 5; i++)           // findSet will return 3 for {0, 1,\
    \ 2, 3, 4}\n        printf(\"findSet(%d) = %d, sizeOfSet(%d) = %d\\n\", i, UF.findSet(i),\
    \ i, UF.sizeOfSet(i));\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: DSU/DisjointSet.cpp
  requiredBy: []
  timestamp: '2024-11-09 09:36:42+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DSU/DisjointSet.cpp
layout: document
redirect_from:
- /library/DSU/DisjointSet.cpp
- /library/DSU/DisjointSet.cpp.html
title: DSU/DisjointSet.cpp
---
