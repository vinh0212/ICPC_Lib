#include <bits/stdc++.h>
#include ".../DSU/DisjointSets.cpp"

using namespace std;

#define fto(i, x, y) for (int i = x; i <= y; ++i)
#define iii tuple<int, int, int>

void kruskal()
{
    vector<iii> EL(E);
    fto(i,1,V) 
    {
        int u,v,w; cin >> u >> v >> w;
        EL.pb({w,u,v});
    }

    sort(EL.begin(), EL.end());

    int cost = 0, taken = 0;

    UnionFind UF(V);
    for (auto &[w,u,v] : EL)
    {
        if(UF.isSameSet(u, v)) continue;
        cost += w;

        UF.unionSet(u, v);
        taken++;
        if(taken == V-1) break;
    }
}