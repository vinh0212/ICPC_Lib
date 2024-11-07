#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define vi vector<int>

const int INF = 1e9;

vi dist(0, INF);
vector<vector<ii>> AL;

void dijkstra(int s)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0,s}); //multi-source: for(auto u : sources) pq.push({0,u});

    while(!pq.empty())
    {
        auto [d,u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v,w] : AL[u])
        {
            if(dist[u] + w >= dist[v]) continue;
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
}