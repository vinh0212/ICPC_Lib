#include <bits/stdc++.h>
using namespace std;

// Define the type for keys and aggregate data
typedef long long ll;

// Node structure for the Splay Tree
struct Node {
    int key;        // Value stored in the node
    ll sum;         // Sum of the subtree
    int size;       // Size of the subtree
    bool rev;       // Flag for lazy reversal
    Node* left;     // Left child
    Node* right;    // Right child
    Node* parent;   // Parent node

    Node(int _key) : key(_key), sum(_key), size(1), rev(false), left(nullptr), right(nullptr), parent(nullptr) {}
};

// Utility functions for Splay Tree operations

// Update the current node's aggregate data based on its children
void update(Node* x) {
    if (!x) return;
    x->size = 1;
    x->sum = x->key;
    if (x->left) {
        x->size += x->left->size;
        x->sum += x->left->sum;
        x->left->parent = x;
    }
    if (x->right) {
        x->size += x->right->size;
        x->sum += x->right->sum;
        x->right->parent = x;
    }
}

// Push down the lazy propagation flags
void push_down(Node* x) {
    if (x && x->rev) {
        swap(x->left, x->right);
        if (x->left) x->left->rev ^= true;
        if (x->right) x->right->rev ^= true;
        x->rev = false;
    }
}

// Rotate operation in Splay Tree
void rotate(Node* x) {
    Node* p = x->parent;
    Node* g = p->parent;
    if (p->left == x) {
        p->left = x->right;
        if (x->right) x->right->parent = p;
        x->right = p;
    }
    else {
        p->right = x->left;
        if (x->left) x->left->parent = p;
        x->left = p;
    }
    p->parent = x;
    x->parent = g;
    if (g) {
        if (g->left == p) g->left = x;
        else g->right = x;
    }
    update(p);
    update(x);
}

// Splay operation: bring node x to the root
void splay(Node*& root, Node* x) {
    if (!x) return;
    while (x->parent) {
        Node* p = x->parent;
        Node* g = p->parent;
        if (g) {
            if ((g->left == p) == (p->left == x)) rotate(p); // Zig-Zig
            else rotate(x); // Zig-Zag
        }
        rotate(x);
    }
    root = x;
}

// Find the k-th node (0-based index)
Node* find_kth(Node* root, int k) {
    Node* x = root;
    while (x) {
        push_down(x);
        int left_size = x->left ? x->left->size : 0;
        if (k < left_size) {
            x = x->left;
        }
        else if (k == left_size) {
            splay(root, x);
            return x;
        }
        else {
            k -= left_size + 1;
            x = x->right;
        }
    }
    return nullptr;
}

// Merge two trees: left and right
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;
    // Find the maximum in the left tree
    Node* x = left;
    while (x->right) {
        push_down(x);
        x = x->right;
    }
    splay(left, x); // Bring x to root
    x->right = right;
    if (right) right->parent = x;
    update(x);
    return x;
}

// Split the tree into [0, k-1] and [k, end]
pair<Node*, Node*> split(Node* root, int k) {
    if (k == 0) return {nullptr, root};
    Node* x = find_kth(root, k - 1);
    if (!x) return {nullptr, root};
    splay(root, x);
    Node* right = x->right;
    if (right) right->parent = nullptr;
    x->right = nullptr;
    update(x);
    return {x, right};
}

// In-order traversal to collect keys (for debugging or output)
void inorder_traversal(Node* x, vector<int>& res) {
    if (!x) return;
    push_down(x);
    inorder_traversal(x->left, res);
    res.push_back(x->key);
    inorder_traversal(x->right, res);
}

// Splay Tree Class
struct SplayTree {
    Node* root;

    SplayTree() : root(nullptr) {}

    // Insert key at position pos (0-based)
    void insert(int pos, int key) {
        Node* new_node = new Node(key);
        pair<Node*, Node*> splitted = split(root, pos);
        root = merge(merge(splitted.first, new_node), splitted.second);
    }

    // Erase node at position pos (0-based)
    void erase(int pos) {
        Node* x = find_kth(root, pos);
        if (!x) return;
        splay(root, x);
        root = merge(x->left, x->right);
        if (root) root->parent = nullptr;
        delete x;
    }

    // Reverse the range [l, r) (0-based)
    void reverse_range(int l, int r) {
        if (l >= r) return;
        pair<Node*, Node*> splitted1 = split(root, l);
        pair<Node*, Node*> splitted2 = split(splitted1.second, r - l);
        if (splitted2.first) splitted2.first->rev ^= true;
        root = merge(merge(splitted1.first, splitted2.first), splitted2.second);
    }

    // Get the sum of the range [l, r) (0-based)
    ll range_sum(int l, int r) {
        if (l >= r) return 0;
        pair<Node*, Node*> splitted1 = split(root, l);
        pair<Node*, Node*> splitted2 = split(splitted1.second, r - l);
        ll res = splitted2.first ? splitted2.first->sum : 0;
        root = merge(merge(splitted1.first, splitted2.first), splitted2.second);
        return res;
    }

    // Get the maximum value in the range [l, r) (0-based)
    // (Requires modifying the Node structure and update function to store maximum)
    // This is a placeholder; implement similarly to range_sum
    ll range_max(int l, int r) {
        // Implement if needed
        return 0;
    }

    // Get the entire sequence (for debugging)
    vector<int> get_sequence() {
        vector<int> res;
        inorder_traversal(root, res);
        return res;
    }
};

