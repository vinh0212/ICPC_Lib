#include <bits/stdc++.h>
using namespace std;

// Structure to represent a query
struct Query {
    int l, r, idx; // l: left index, r: right index, idx: original query index
};

// Comparator function to sort queries according to Mo's algorithm
bool mo_cmp(const Query &a, const Query &b, int block_size) {
    if (a.l / block_size != b.l / block_size)
        return a.l / block_size < b.l / block_size;
    // If in the same block, sort by R value
    // Alternate sorting order for even and odd blocks to optimize cache
    if ((a.l / block_size) & 1)
        return a.r > b.r;
    else
        return a.r < b.r;
}

// Function to perform Mo's algorithm
vector<long long> mos_algorithm(int n, vector<Query> &queries, vector<int> &array) {
    int q = queries.size();
    vector<long long> answers(q);
    
    // Determine block size
    int block_size = sqrt(n) + 1;
    
    // Sort queries using the comparator
    sort(queries.begin(), queries.end(), [&](const Query &a, const Query &b) -> bool {
        return mo_cmp(a, b, block_size);
    });
    
    // Initialize current range [curr_l, curr_r]
    int curr_l = 0, curr_r = -1;
    
    // Example: Count of distinct elements
    // Modify these variables and functions based on the problem
    int distinct = 0;
    // Assuming array elements are in the range [1, max_val]
    int max_val = *max_element(array.begin(), array.end());
    vector<int> freq(max_val + 1, 0);
    // Lambda to add an element to the current range
    auto add = [&](int idx) {
        freq[array[idx]]++;
        if (freq[array[idx]] == 1)
            distinct++;
    };
    // Lambda to remove an element from the current range
    auto remove_fn = [&](int idx) {
        freq[array[idx]]--;
        if (freq[array[idx]] == 0)
            distinct--;
    };
    
    // Process each query
    for(auto &query : queries){
        int L = query.l;
        int R = query.r;
        
        // Expand to the left
        while(curr_l > L) add(--curr_l);
        // Expand to the right
        while(curr_r < R) add(++curr_r);
        // Contract from the left
        while(curr_l < L) remove_fn(curr_l++);
        // Contract from the right
        while(curr_r > R) remove_fn(curr_r--);
        
        // Store the answer for the current query
        answers[query.idx] = distinct; // Replace 'distinct' with the required metric
    }
    
    return answers;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> array(n);
    for(auto &x : array) cin >> x;
    
    vector<Query> queries(q);
    for(int i = 0; i < q; ++i){
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; // Convert to 0-based index
        queries[i].r--; // Convert to 0-based index
        queries[i].idx = i;
    }
    
    vector<long long> answers = mos_algorithm(n, queries, array);
    
    for(auto &ans : answers) cout << ans << "\n";
}
