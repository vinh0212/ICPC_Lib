#include <bits/stdc++.h>>
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi match, vis; // match: stores pairings; vis: marks visited nodes

bool AugmentPath(int L) {
    if (vis[L]) return false;
    vis[L] = 1;
    for (int R : AL[L]) {
        if (match[R] == -1 || AugmentPath(match[R])) {
            match[R] = L; // Pair R with L
            return true; // Return true if an augmenting path is found
        }
    }
    return false; 
}

int findMCBM(int Vleft, int Vright) {
    int MCBM = 0;
    match.assign(Vleft + Vright, -1);
    
    for (int L = 0; L < Vleft; ++L) { 
        vis.assign(Vleft, 0); // Reset visited state for each iteration
        if (AugmentPath(L)) MCBM++; 
    }
    return MCBM; 
}

int main() {
    int Vleft, Vright, E;
    cin >> Vleft >> Vright >> E; //number of left nodes, right nodes, and edges

    AL.assign(Vleft, vi()); // Initialize adjacency list for left nodes
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v; 
        AL[u].push_back(v);
    }

    int MCBM = findMCBM(Vleft, Vright);
    return 0;
}
