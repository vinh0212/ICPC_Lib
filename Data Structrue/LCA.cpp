// LCA
// Notes:
// - Index from 0
// - Cannot use for queries like min edge in path u -> v
//
// Tested:
// - https://judge.yosupo.jp/problem/lca
#include "RMQ.h"
struct LCA {
    const int n;
    vector<vector<int>> adj;
    const int root;
    using P = pair<int,int>;
    static P f(P x, P y) { return std::min(x, y); }

    LCA(int _n, const vector<vector<int>>& _adj, int _root)
            : n(_n), adj(_adj), root(_root) {
        assert(0 <= root && root < n);
        id.resize(n);
        depth.resize(n);
        order.reserve(2 * n);
        dfs(root, -1, 0);
        rmq = RMQ<P, f>(order);
    }

    int lca(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);

        int x = id[u], y = id[v];
        if (x > y) std::swap(x, y);
        return rmq.get(x, y+1).second;
    }

// private:
    vector<int> id, depth;
    vector<P> order;
    RMQ<P, f> rmq;

    void dfs(int u, int fu, int d) {
        id[u] = order.size();
        depth[u] = d;
        order.emplace_back(d, u);
        for (int v : adj[u]) {
            if (v == fu) continue;
            dfs(v, u, d + 1);
            order.emplace_back(d, u);
        }
    }
};

//Example Code
#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>
using namespace std;

#include "../LCA.h"
#include "../../buffered_reader.h"

#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = IO::get<int>();
    int q = IO::get<int>();
    vector<vector<int>> adj(n);
    FOR(i,1,n-1) {
        int pi = IO::get<int>();
        adj[i].push_back(pi);
        adj[pi].push_back(i);
    }

    LCA lca(n, adj, 0);

    while (q--) {
        int u = IO::get<int>();
        int v = IO::get<int>();

        cout << lca.lca(u, v) << '\n';
    }
    return 0;
}