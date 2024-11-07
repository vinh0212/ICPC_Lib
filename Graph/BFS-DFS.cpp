#include <bits/stdc++.h>

using namespace std;

enum { UNVISITED = -1, VISITED = -2 };
#define INF (int)1e9
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

vector<vii> AL;
vi dist, p, dfs_num, num, low, av, visited,ts; //dfs_num only for visited or not, num for dfs numbering
int V, E, dfs_cnt, dfsRoot, rootChildren;

void bfs(int s)
{
    dist[s] = 0;
    queue<int> q; q.push(s);
    p.assign(V, -1);


    bool isBi = true;

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (auto &[v, w] : AL[u])
        {
            if (dist[v] == INF)
            {
                dist[v] = dist[u] + 1;
                p[v] = u;
                q.push(v);
            }
            else if (dist[v] % 2 == dist[u] % 2) //same parity
                isBi = false;
        }
    }
}

void dfs(int u)
{
    //cout << u;
    dfs_num[u] = VISITED;
    for (auto &[v, w] : AL[u])
    {
        if (dfs_num[v] == UNVISITED)
            dfs(v);
    }
    //ts.push_back(u); //topological sort
}

//DFS application
void findAV(int u) //find articulation points and bridges
{
    num[u] = dfs_cnt++;
    low[u] = num[u]; 
    for (auto &[v, w] : AL[u])
    {
        if (num[u] == UNVISITED)
        {
            p[v] = u;
            if (u == dfsRoot) ++rootChildren;
            findAV(v);

            if (low[v] >= num[u]) av[u] = 1; //av here

            if (low[v] > num[u]) // --> bridge (u,v)
            {}

            low[u] = min(low[u], low[v]);

        }
        else if (v != p[u])
            low[u] = min(low[u], num[v]);
    }
}
int countCC() //for counting connected components
{
    int numCC = 0;
    for (int u = 0; u <= V; u++)
    {
        if (dfs_num[u] == UNVISITED)
        {
            numCC++;
            dfs(u);
        }
    }
}

stack<int> St;
int numSCC = 0;
void tarjanSCC(int u) //for finding strongly connected components
{
    low[u] = num[u] = dfs_cnt; dfs_cnt++;
    St.push(u);
    visited[u] = 1;
    for (auto &[v, w] : AL[u])
    {
        if (num[v] == UNVISITED)
            tarjanSCC(v);
        if (visited[v])
            low[u] = min(low[u], low[v]);
    }

    if(low[u] == num[u]) //u is the root of SCC
    {
        numSCC++;
        while (1)
        {
            int v = St.top(); St.pop(); 
            visited[v] = 0;
            if (u == v) break;
        }
    }

    /* in main:
    for (int u = 0; u < V; u++)
        if (num[u] == UNVISITED)
            tarjanSCC(u);
    */
}

int main()
{
    //find Bridges and AVs
    for (int u = 0; u < V; ++u)
        if (dfs_num[u] == UNVISITED) {
            dfsRoot = u; rootChildren = 0;
            findAV(u);
            av[dfsRoot] = (rootChildren > 1); // special case
        }
    //printf("Articulation Points:\n");
    for (int u = 0; u < V; ++u)
        if (av[u])
            cout << u;
}
