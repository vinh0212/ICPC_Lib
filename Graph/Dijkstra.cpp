const long long INF = 2000000000000000000LL;
struct Edge{
    int v;
    long long w;
};
void dijkstra(int n, int S, vector<vector<Edge>> E, vector<long long> &D, vector<int> &trace) {
    D.resize(n, INF);
    trace.resize(n, -1);
    
    vector<bool> P(n, 0);
    D[S] = 0;
    
    for (int i = 0; i < n; i++) {
        int uBest; // tim đinh u chưa dung, co khoang cach nho nhat
        long long Max = INF;
        for (int u = 0; u < n; u++) {
            if(D[u] < Max && P[u] == false) {
                uBest = u;
                Max = D[u];
            }
        }
        
        // cải tiến các đường đi qua u
        int u = uBest;
        P[u] = true;
        for(auto x : E[u]) {
            int v = x.v;
            long long w = x.w;
            if(D[v] > D[u] + w) {
                D[v] = D[u] + w;
                trace[v] = u;
            }
        }
    }
}
vector<int> trace_path(vector<int> &trace, int S, int u) {
    if (u != S && trace[u] == -1) return vector<int>(0); // không có đường đi

    vector<int> path;
    while (u != -1) { // truy vết ngược từ u về S
        path.push_back(u);
        u = trace[u];
    }
    reverse(path.begin(), path.end()); // cần reverse vì đường đi lúc này là từ u về S
    
    return path;
}
//Example Code
    int n, m, S;
    cin >> n >> m >> S;
    
    vector<vector<Edge>> E(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--,v--;
        E[u].push_back({v, (long long)(pow(2,w))});
    }
    
    vector<long long> D;
    vector<int> trace;
    dijkstra(n, S, E, D, trace); // bắt đầu từ đỉnh S
    for(int i=0;i<n;i++) cout << D[i] << " ";