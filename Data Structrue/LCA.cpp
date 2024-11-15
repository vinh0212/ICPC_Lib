#include <bits/stdc++.h>
using namespace std;

// Constants
const int MAXN = 100005;
const int LOG = 20;

// LCA Class using Euler Tour and Sparse Table (RMQ)
struct LCA {
    int n, root;
    vector<vector<int>> adj;            // Adjacency list
    vector<int> depth;                  // Depth of each node
    vector<int> first;                  // First occurrence in Euler Tour
    vector<int> euler;                  // Euler Tour
    vector<vector<pair<int, int>>> st;  // Sparse Table for RMQ

    // Constructor
    LCA(int _n, const vector<vector<int>>& _adj, int _root = 0)
        : n(_n), adj(_adj), root(_root), depth(_n, 0), first(_n, -1) {
        dfs(root, -1, 0);
        build_sparse_table();
    }

    // DFS to perform Euler Tour
    void dfs(int u, int fu, int d){
        depth[u] = d;
        first[u] = euler.size();
        euler.emplace_back(u);
        for(auto &v : adj[u]){
            if(v != fu){
                dfs(v, u, d + 1);
                euler.emplace_back(u);
            }
        }
    }

    // Build Sparse Table for RMQ
    void build_sparse_table(){
        int m = euler.size();
        int log_m = log2(m) + 1;
        st.assign(log_m, vector<pair<int, int>>(m));

        // Initialize level 0
        for(int i = 0; i < m; ++i){
            st[0][i] = {depth[euler[i]], euler[i]};
        }

        // Build Sparse Table
        for(int k = 1; (1 << k) <= m; ++k){
            for(int i = 0; i + (1 << k) <= m; ++i){
                st[k][i] = min(st[k-1][i], st[k-1][i + (1 << (k-1))]);
            }
        }
    }

    // Query Sparse Table for RMQ in range [L, R]
    pair<int, int> query(int L, int R){
        int k = log2(R - L + 1);
        return min(st[k][L], st[k][R - (1 << k) + 1]);
    }

    // Function to compute LCA of u and v
    int lca_query(int u, int v){
        if(first[u] > first[v]) swap(u, v);
        pair<int, int> res = query(first[u], first[v]);
        return res.second;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Read number of nodes and queries
    int n, q;
    cin >> n >> q;

    // Initialize adjacency list
    vector<vector<int>> adj(n, vector<int>());

    // Read tree edges (assuming 0-based indexing and node 0 is root)
    // Typically, for n nodes, there are n-1 edges
    for(int i = 1; i < n; ++i){
        int parent_node;
        cin >> parent_node;
        // If nodes are 1-based, uncomment the next line
        // parent_node--;
        adj[i].push_back(parent_node);
        adj[parent_node].push_back(i);
    }

    // Initialize LCA structure
    LCA lca(n, adj, 0); // Assuming root is node 0

    // Process queries
    while(q--){
        int u, v;
        cin >> u >> v;
        // If inputs are 1-based, convert to 0-based
        // u--; v--;
        int ancestor = lca.lca_query(u, v);
        cout << ancestor << '\n';
    }

    return 0;
}
