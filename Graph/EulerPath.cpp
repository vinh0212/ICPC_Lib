#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int N;
vector<vi> AL; // Directed graph, undirected graph means add edge twice

vi hierholzer(int s)
{
    vi ans, idx(N, 0), st;
    st.push_back(s);
    while (!st.empty())
    {
        int u = st.back();
        if (idx[u] < (int)AL[u].size())
        { // still has neighbor
            st.push_back(AL[u][idx[u]]);
            ++idx[u];
        }
        else
        {
            ans.push_back(u);
            st.pop_back();
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vi hierholzerUndirected() //
{
    vi ans, idx(N, 0), st;
    st.push_back(0);
    while (!st.empty())
    {
        int u = st.back();
        if (idx[u] < (int)AL[u].size())
        { // still has neighbor
            int v = AL[u][idx[u]];
            ++idx[u];
            for (int i = 0; i < (int)AL[v].size(); ++i)
            {
                if (AL[v][i] == u)
                {
                    AL[v].erase(AL[v].begin() + i);
                    break;
                }
            }
            st.push_back(v);
        }
        else
        {
            ans.push_back(u);
            st.pop_back();
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}