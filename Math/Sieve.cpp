// F is called for each prime
// Sieve (odd only + segmented) {{{
template<typename F>
void sieve(int MAX, F func) {

    const int S = sqrt(MAX + 0.5);
    vector<char> sieve(S + 1, true);
    vector<array<int, 2>> cp;
    for (int i = 3; i <= S; i += 2) {
        if (!sieve[i])
            continue;
        cp.push_back({i, (i * i - 1) / 2});
        for (int j = i * i; j <= S; j += 2 * i)
            sieve[j] = false;
    }
    func(2);
    vector<char> block(S);
    int high = (MAX - 1) / 2;
    for (int low = 0; low <= high; low += S) {
        fill(block.begin(), block.end(), true);
        for (auto &i : cp) {
            int p = i[0], idx = i[1];
            for (; idx < S; idx += p)
                block[idx] = false;
            i[1] = idx - S;
        }
        if (low == 0)
            block[0] = false;
        for (int i = 0; i < S && low + i <= high; i++)
            if (block[i]) {
                func((low + i) * 2 + 1);
            }
    };
}
// }}}
//Example Code
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include <bits/stdc++.h>
using namespace std;

#include "../Prime/Sieve.h"

int n, a, b, cnt = 0, cnt_mod = 0;
vector<int> ps;
void newPrime(int p) {
    if (p > n) {
        cout << cnt << ' ' << ps.size() << '\n';
        for (int x : ps) cout << x << ' ';
        exit(0);
    }
    if (cnt_mod == b) ps.push_back(p);
    ++cnt;
    ++cnt_mod;
    if (cnt_mod == a) cnt_mod = 0;
}

int32_t main() {
    cin >> n >> a >> b;
    sieve(1'000'000'000, newPrime);
    return 0;
}