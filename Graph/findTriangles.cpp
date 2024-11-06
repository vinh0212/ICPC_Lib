// Find all cycles of length 3 (a.k.a. triangles)
// Complexity: O(N + M*sqrt(M))
//
// Index from 0
//
// Tested:
// - https://judge.yosupo.jp/problem/enumerate_triangles
vector< tuple<int,int,int> > find_all_triangles(
        int n,
        vector<pair<int,int>> edges) {
    // Remove duplicated edges
    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());

    // Compute degs
    vector<int> deg(n, 0);
    for (const auto& [u, v] : edges) {
        if (u == v) continue;
        ++deg[u], ++deg[v];
    }

    // Add edge (u, v) where u is 'lower' than v
    vector<vector<int>> adj(n);
    for (auto [u, v] : edges) {
        if (u == v) continue;
        if (deg[u] > deg[v] || (deg[u] == deg[v] && u > v)) swap(u, v);
        adj[u].push_back(v);
    }

    // Find all triplets.
    // If it's too slow, remove vector res and compute answer directly
    vector<tuple<int,int,int>> res;
    vector<bool> good(n, false);
    for (int i = 0; i < n; i++) {
        for (auto j : adj[i]) good[j] = true;
        for (auto j : adj[i]) {
            for (auto k : adj[j]) {
                if (good[k]) {
                    res.emplace_back(i, j, k);
                }
            }
        }
        for (auto j : adj[i]) good[j] = false;
    }
    return res;
}
//Example Code
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include <bits/stdc++.h>
using namespace std;

#include "../find_triangles.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<long long> xs(n);
    REP(i,n) cin >> xs[i];

    vector<pair<int,int>> edges(m);
    for (auto& [u, v] : edges) {
        cin >> u >> v;
    }

    auto res = find_all_triangles(n, edges);
    long long sum = 0;
    const int MOD = 998244353;
    for (auto [i, j, k] : res) {
        sum = (sum + xs[i] * xs[j] % MOD * xs[k]) % MOD;
    }
    cout << sum << endl;
    return 0;
}