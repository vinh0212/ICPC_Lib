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
  bundledCode: "#line 1 \"String/SuffixTrie.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct vertex\n{\n    char alphabet;\n    bool exist;\n  \
    \  vector<vertex *> child;\n    vertex(char a) : alphabet(a), exist(false) { child.assign(26,\
    \ NULL); }\n};\n\nclass Trie\n{        // this is TRIE\nprivate: // NOT Suffix\
    \ Trie\n    vertex *root;\n\npublic:\n    Trie() { root = new vertex('!'); }\n\
    \n    void insert(string word)\n    { // insert a word into trie\n        vertex\
    \ *cur = root;\n        for (int i = 0; i < (int)word.size(); ++i)\n        {\
    \ // O(n)\n            int alphaNum = word[i] - 'A';\n            if (cur->child[alphaNum]\
    \ == NULL) // add new branch if NULL\n                cur->child[alphaNum] = new\
    \ vertex(word[i]);\n            cur = cur->child[alphaNum];\n        }\n     \
    \   cur->exist = true;\n    }\n\n    bool search(string word)\n    { // true if\
    \ word in trie\n        vertex *cur = root;\n        for (int i = 0; i < (int)word.size();\
    \ ++i)\n        { // O(m)\n            int alphaNum = word[i] - 'A';\n       \
    \     if (cur->child[alphaNum] == NULL) // not found\n                return false;\n\
    \            cur = cur->child[alphaNum];\n        }\n        return cur->exist;\
    \ // check exist flag\n    }\n\n    bool startsWith(string prefix)\n    { // true\
    \ if match prefix\n        vertex *cur = root;\n        for (int i = 0; i < (int)prefix.size();\
    \ ++i)\n        {\n            int alphaNum = prefix[i] - 'A';\n            if\
    \ (cur->child[alphaNum] == NULL) // not found\n                return false;\n\
    \            cur = cur->child[alphaNum];\n        }\n        return true; // reach\
    \ here, return true\n    }\n};\n\nint main()\n{\n    Trie T;\n    set<string>\
    \ S = {\"CAR\", \"CAT\", \"RAT\"};\n    for (auto &str : S)\n    {\n        printf(\"\
    Insert %s\\n\", str.c_str());\n        T.insert(str);\n    }\n    printf(\"'CAR'\
    \ exist? %d\\n\", T.search(\"CAR\"));               // 1 (true)\n    printf(\"\
    'DOG' exist? %d\\n\", T.search(\"DOG\"));               // 0 (false)\n    printf(\"\
    Starts with 'CA' exist? %d\\n\", T.startsWith(\"CA\")); // 1 (true)\n    printf(\"\
    Starts with 'Z' exist? %d\\n\", T.startsWith(\"Z\"));   // 0 (false)\n    printf(\"\
    Starts with 'AT' exist? %d\\n\", T.startsWith(\"AT\")); // 0 (false) for this\
    \ Trie, but in a Suffix Trie, we have a suffix \"AT\" (from \"CAT\" or \"RAT\"\
    ) that starts with \"AT\"\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct vertex\n{\n    char\
    \ alphabet;\n    bool exist;\n    vector<vertex *> child;\n    vertex(char a)\
    \ : alphabet(a), exist(false) { child.assign(26, NULL); }\n};\n\nclass Trie\n\
    {        // this is TRIE\nprivate: // NOT Suffix Trie\n    vertex *root;\n\npublic:\n\
    \    Trie() { root = new vertex('!'); }\n\n    void insert(string word)\n    {\
    \ // insert a word into trie\n        vertex *cur = root;\n        for (int i\
    \ = 0; i < (int)word.size(); ++i)\n        { // O(n)\n            int alphaNum\
    \ = word[i] - 'A';\n            if (cur->child[alphaNum] == NULL) // add new branch\
    \ if NULL\n                cur->child[alphaNum] = new vertex(word[i]);\n     \
    \       cur = cur->child[alphaNum];\n        }\n        cur->exist = true;\n \
    \   }\n\n    bool search(string word)\n    { // true if word in trie\n       \
    \ vertex *cur = root;\n        for (int i = 0; i < (int)word.size(); ++i)\n  \
    \      { // O(m)\n            int alphaNum = word[i] - 'A';\n            if (cur->child[alphaNum]\
    \ == NULL) // not found\n                return false;\n            cur = cur->child[alphaNum];\n\
    \        }\n        return cur->exist; // check exist flag\n    }\n\n    bool\
    \ startsWith(string prefix)\n    { // true if match prefix\n        vertex *cur\
    \ = root;\n        for (int i = 0; i < (int)prefix.size(); ++i)\n        {\n \
    \           int alphaNum = prefix[i] - 'A';\n            if (cur->child[alphaNum]\
    \ == NULL) // not found\n                return false;\n            cur = cur->child[alphaNum];\n\
    \        }\n        return true; // reach here, return true\n    }\n};\n\nint\
    \ main()\n{\n    Trie T;\n    set<string> S = {\"CAR\", \"CAT\", \"RAT\"};\n \
    \   for (auto &str : S)\n    {\n        printf(\"Insert %s\\n\", str.c_str());\n\
    \        T.insert(str);\n    }\n    printf(\"'CAR' exist? %d\\n\", T.search(\"\
    CAR\"));               // 1 (true)\n    printf(\"'DOG' exist? %d\\n\", T.search(\"\
    DOG\"));               // 0 (false)\n    printf(\"Starts with 'CA' exist? %d\\\
    n\", T.startsWith(\"CA\")); // 1 (true)\n    printf(\"Starts with 'Z' exist? %d\\\
    n\", T.startsWith(\"Z\"));   // 0 (false)\n    printf(\"Starts with 'AT' exist?\
    \ %d\\n\", T.startsWith(\"AT\")); // 0 (false) for this Trie, but in a Suffix\
    \ Trie, we have a suffix \"AT\" (from \"CAT\" or \"RAT\") that starts with \"\
    AT\"\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/SuffixTrie.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:09:26+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/SuffixTrie.cpp
layout: document
redirect_from:
- /library/String/SuffixTrie.cpp
- /library/String/SuffixTrie.cpp.html
title: String/SuffixTrie.cpp
---
