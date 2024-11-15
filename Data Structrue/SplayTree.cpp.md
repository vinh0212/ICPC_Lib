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
  bundledCode: "#line 1 \"Data Structrue/SplayTree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Define the type for keys and aggregate data\ntypedef\
    \ long long ll;\n\n// Node structure for the Splay Tree\nstruct Node {\n    int\
    \ key;        // Value stored in the node\n    ll sum;         // Sum of the subtree\n\
    \    int size;       // Size of the subtree\n    bool rev;       // Flag for lazy\
    \ reversal\n    Node* left;     // Left child\n    Node* right;    // Right child\n\
    \    Node* parent;   // Parent node\n\n    Node(int _key) : key(_key), sum(_key),\
    \ size(1), rev(false), left(nullptr), right(nullptr), parent(nullptr) {}\n};\n\
    \n// Utility functions for Splay Tree operations\n\n// Update the current node's\
    \ aggregate data based on its children\nvoid update(Node* x) {\n    if (!x) return;\n\
    \    x->size = 1;\n    x->sum = x->key;\n    if (x->left) {\n        x->size +=\
    \ x->left->size;\n        x->sum += x->left->sum;\n        x->left->parent = x;\n\
    \    }\n    if (x->right) {\n        x->size += x->right->size;\n        x->sum\
    \ += x->right->sum;\n        x->right->parent = x;\n    }\n}\n\n// Push down the\
    \ lazy propagation flags\nvoid push_down(Node* x) {\n    if (x && x->rev) {\n\
    \        swap(x->left, x->right);\n        if (x->left) x->left->rev ^= true;\n\
    \        if (x->right) x->right->rev ^= true;\n        x->rev = false;\n    }\n\
    }\n\n// Rotate operation in Splay Tree\nvoid rotate(Node* x) {\n    Node* p =\
    \ x->parent;\n    Node* g = p->parent;\n    if (p->left == x) {\n        p->left\
    \ = x->right;\n        if (x->right) x->right->parent = p;\n        x->right =\
    \ p;\n    }\n    else {\n        p->right = x->left;\n        if (x->left) x->left->parent\
    \ = p;\n        x->left = p;\n    }\n    p->parent = x;\n    x->parent = g;\n\
    \    if (g) {\n        if (g->left == p) g->left = x;\n        else g->right =\
    \ x;\n    }\n    update(p);\n    update(x);\n}\n\n// Splay operation: bring node\
    \ x to the root\nvoid splay(Node*& root, Node* x) {\n    if (!x) return;\n   \
    \ while (x->parent) {\n        Node* p = x->parent;\n        Node* g = p->parent;\n\
    \        if (g) {\n            if ((g->left == p) == (p->left == x)) rotate(p);\
    \ // Zig-Zig\n            else rotate(x); // Zig-Zag\n        }\n        rotate(x);\n\
    \    }\n    root = x;\n}\n\n// Find the k-th node (0-based index)\nNode* find_kth(Node*\
    \ root, int k) {\n    Node* x = root;\n    while (x) {\n        push_down(x);\n\
    \        int left_size = x->left ? x->left->size : 0;\n        if (k < left_size)\
    \ {\n            x = x->left;\n        }\n        else if (k == left_size) {\n\
    \            splay(root, x);\n            return x;\n        }\n        else {\n\
    \            k -= left_size + 1;\n            x = x->right;\n        }\n    }\n\
    \    return nullptr;\n}\n\n// Merge two trees: left and right\nNode* merge(Node*\
    \ left, Node* right) {\n    if (!left) return right;\n    if (!right) return left;\n\
    \    // Find the maximum in the left tree\n    Node* x = left;\n    while (x->right)\
    \ {\n        push_down(x);\n        x = x->right;\n    }\n    splay(left, x);\
    \ // Bring x to root\n    x->right = right;\n    if (right) right->parent = x;\n\
    \    update(x);\n    return x;\n}\n\n// Split the tree into [0, k-1] and [k, end]\n\
    pair<Node*, Node*> split(Node* root, int k) {\n    if (k == 0) return {nullptr,\
    \ root};\n    Node* x = find_kth(root, k - 1);\n    if (!x) return {nullptr, root};\n\
    \    splay(root, x);\n    Node* right = x->right;\n    if (right) right->parent\
    \ = nullptr;\n    x->right = nullptr;\n    update(x);\n    return {x, right};\n\
    }\n\n// In-order traversal to collect keys (for debugging or output)\nvoid inorder_traversal(Node*\
    \ x, vector<int>& res) {\n    if (!x) return;\n    push_down(x);\n    inorder_traversal(x->left,\
    \ res);\n    res.push_back(x->key);\n    inorder_traversal(x->right, res);\n}\n\
    \n// Splay Tree Class\nstruct SplayTree {\n    Node* root;\n\n    SplayTree()\
    \ : root(nullptr) {}\n\n    // Insert key at position pos (0-based)\n    void\
    \ insert(int pos, int key) {\n        Node* new_node = new Node(key);\n      \
    \  pair<Node*, Node*> splitted = split(root, pos);\n        root = merge(merge(splitted.first,\
    \ new_node), splitted.second);\n    }\n\n    // Erase node at position pos (0-based)\n\
    \    void erase(int pos) {\n        Node* x = find_kth(root, pos);\n        if\
    \ (!x) return;\n        splay(root, x);\n        root = merge(x->left, x->right);\n\
    \        if (root) root->parent = nullptr;\n        delete x;\n    }\n\n    //\
    \ Reverse the range [l, r) (0-based)\n    void reverse_range(int l, int r) {\n\
    \        if (l >= r) return;\n        pair<Node*, Node*> splitted1 = split(root,\
    \ l);\n        pair<Node*, Node*> splitted2 = split(splitted1.second, r - l);\n\
    \        if (splitted2.first) splitted2.first->rev ^= true;\n        root = merge(merge(splitted1.first,\
    \ splitted2.first), splitted2.second);\n    }\n\n    // Get the sum of the range\
    \ [l, r) (0-based)\n    ll range_sum(int l, int r) {\n        if (l >= r) return\
    \ 0;\n        pair<Node*, Node*> splitted1 = split(root, l);\n        pair<Node*,\
    \ Node*> splitted2 = split(splitted1.second, r - l);\n        ll res = splitted2.first\
    \ ? splitted2.first->sum : 0;\n        root = merge(merge(splitted1.first, splitted2.first),\
    \ splitted2.second);\n        return res;\n    }\n\n    // Get the maximum value\
    \ in the range [l, r) (0-based)\n    // (Requires modifying the Node structure\
    \ and update function to store maximum)\n    // This is a placeholder; implement\
    \ similarly to range_sum\n    ll range_max(int l, int r) {\n        // Implement\
    \ if needed\n        return 0;\n    }\n\n    // Get the entire sequence (for debugging)\n\
    \    vector<int> get_sequence() {\n        vector<int> res;\n        inorder_traversal(root,\
    \ res);\n        return res;\n    }\n};\n\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// Define the type for\
    \ keys and aggregate data\ntypedef long long ll;\n\n// Node structure for the\
    \ Splay Tree\nstruct Node {\n    int key;        // Value stored in the node\n\
    \    ll sum;         // Sum of the subtree\n    int size;       // Size of the\
    \ subtree\n    bool rev;       // Flag for lazy reversal\n    Node* left;    \
    \ // Left child\n    Node* right;    // Right child\n    Node* parent;   // Parent\
    \ node\n\n    Node(int _key) : key(_key), sum(_key), size(1), rev(false), left(nullptr),\
    \ right(nullptr), parent(nullptr) {}\n};\n\n// Utility functions for Splay Tree\
    \ operations\n\n// Update the current node's aggregate data based on its children\n\
    void update(Node* x) {\n    if (!x) return;\n    x->size = 1;\n    x->sum = x->key;\n\
    \    if (x->left) {\n        x->size += x->left->size;\n        x->sum += x->left->sum;\n\
    \        x->left->parent = x;\n    }\n    if (x->right) {\n        x->size +=\
    \ x->right->size;\n        x->sum += x->right->sum;\n        x->right->parent\
    \ = x;\n    }\n}\n\n// Push down the lazy propagation flags\nvoid push_down(Node*\
    \ x) {\n    if (x && x->rev) {\n        swap(x->left, x->right);\n        if (x->left)\
    \ x->left->rev ^= true;\n        if (x->right) x->right->rev ^= true;\n      \
    \  x->rev = false;\n    }\n}\n\n// Rotate operation in Splay Tree\nvoid rotate(Node*\
    \ x) {\n    Node* p = x->parent;\n    Node* g = p->parent;\n    if (p->left ==\
    \ x) {\n        p->left = x->right;\n        if (x->right) x->right->parent =\
    \ p;\n        x->right = p;\n    }\n    else {\n        p->right = x->left;\n\
    \        if (x->left) x->left->parent = p;\n        x->left = p;\n    }\n    p->parent\
    \ = x;\n    x->parent = g;\n    if (g) {\n        if (g->left == p) g->left =\
    \ x;\n        else g->right = x;\n    }\n    update(p);\n    update(x);\n}\n\n\
    // Splay operation: bring node x to the root\nvoid splay(Node*& root, Node* x)\
    \ {\n    if (!x) return;\n    while (x->parent) {\n        Node* p = x->parent;\n\
    \        Node* g = p->parent;\n        if (g) {\n            if ((g->left == p)\
    \ == (p->left == x)) rotate(p); // Zig-Zig\n            else rotate(x); // Zig-Zag\n\
    \        }\n        rotate(x);\n    }\n    root = x;\n}\n\n// Find the k-th node\
    \ (0-based index)\nNode* find_kth(Node* root, int k) {\n    Node* x = root;\n\
    \    while (x) {\n        push_down(x);\n        int left_size = x->left ? x->left->size\
    \ : 0;\n        if (k < left_size) {\n            x = x->left;\n        }\n  \
    \      else if (k == left_size) {\n            splay(root, x);\n            return\
    \ x;\n        }\n        else {\n            k -= left_size + 1;\n           \
    \ x = x->right;\n        }\n    }\n    return nullptr;\n}\n\n// Merge two trees:\
    \ left and right\nNode* merge(Node* left, Node* right) {\n    if (!left) return\
    \ right;\n    if (!right) return left;\n    // Find the maximum in the left tree\n\
    \    Node* x = left;\n    while (x->right) {\n        push_down(x);\n        x\
    \ = x->right;\n    }\n    splay(left, x); // Bring x to root\n    x->right = right;\n\
    \    if (right) right->parent = x;\n    update(x);\n    return x;\n}\n\n// Split\
    \ the tree into [0, k-1] and [k, end]\npair<Node*, Node*> split(Node* root, int\
    \ k) {\n    if (k == 0) return {nullptr, root};\n    Node* x = find_kth(root,\
    \ k - 1);\n    if (!x) return {nullptr, root};\n    splay(root, x);\n    Node*\
    \ right = x->right;\n    if (right) right->parent = nullptr;\n    x->right = nullptr;\n\
    \    update(x);\n    return {x, right};\n}\n\n// In-order traversal to collect\
    \ keys (for debugging or output)\nvoid inorder_traversal(Node* x, vector<int>&\
    \ res) {\n    if (!x) return;\n    push_down(x);\n    inorder_traversal(x->left,\
    \ res);\n    res.push_back(x->key);\n    inorder_traversal(x->right, res);\n}\n\
    \n// Splay Tree Class\nstruct SplayTree {\n    Node* root;\n\n    SplayTree()\
    \ : root(nullptr) {}\n\n    // Insert key at position pos (0-based)\n    void\
    \ insert(int pos, int key) {\n        Node* new_node = new Node(key);\n      \
    \  pair<Node*, Node*> splitted = split(root, pos);\n        root = merge(merge(splitted.first,\
    \ new_node), splitted.second);\n    }\n\n    // Erase node at position pos (0-based)\n\
    \    void erase(int pos) {\n        Node* x = find_kth(root, pos);\n        if\
    \ (!x) return;\n        splay(root, x);\n        root = merge(x->left, x->right);\n\
    \        if (root) root->parent = nullptr;\n        delete x;\n    }\n\n    //\
    \ Reverse the range [l, r) (0-based)\n    void reverse_range(int l, int r) {\n\
    \        if (l >= r) return;\n        pair<Node*, Node*> splitted1 = split(root,\
    \ l);\n        pair<Node*, Node*> splitted2 = split(splitted1.second, r - l);\n\
    \        if (splitted2.first) splitted2.first->rev ^= true;\n        root = merge(merge(splitted1.first,\
    \ splitted2.first), splitted2.second);\n    }\n\n    // Get the sum of the range\
    \ [l, r) (0-based)\n    ll range_sum(int l, int r) {\n        if (l >= r) return\
    \ 0;\n        pair<Node*, Node*> splitted1 = split(root, l);\n        pair<Node*,\
    \ Node*> splitted2 = split(splitted1.second, r - l);\n        ll res = splitted2.first\
    \ ? splitted2.first->sum : 0;\n        root = merge(merge(splitted1.first, splitted2.first),\
    \ splitted2.second);\n        return res;\n    }\n\n    // Get the maximum value\
    \ in the range [l, r) (0-based)\n    // (Requires modifying the Node structure\
    \ and update function to store maximum)\n    // This is a placeholder; implement\
    \ similarly to range_sum\n    ll range_max(int l, int r) {\n        // Implement\
    \ if needed\n        return 0;\n    }\n\n    // Get the entire sequence (for debugging)\n\
    \    vector<int> get_sequence() {\n        vector<int> res;\n        inorder_traversal(root,\
    \ res);\n        return res;\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Data Structrue/SplayTree.cpp
  requiredBy: []
  timestamp: '2024-11-15 23:57:47+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structrue/SplayTree.cpp
layout: document
redirect_from:
- /library/Data Structrue/SplayTree.cpp
- /library/Data Structrue/SplayTree.cpp.html
title: Data Structrue/SplayTree.cpp
---
