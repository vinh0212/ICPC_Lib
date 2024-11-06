// Copied from https://judge.yosupo.jp/submission/15864
// Tested:
// - https://judge.yosupo.jp/problem/sum_of_floor_of_linear

using ll = long long;
ll sum(ll n) {
    return n * (n-1) / 2;
}
// sum( (a + d*i) / m ) for i in [0, n-1]
ll sum_div(ll a, ll d, ll m, ll n) {
    ll res = d / m * sum(n) + a / m * n;
    d %= m, a %= m;
    if (!d) return res;
    ll to = (n * d + a) / m;
    return res + (n - 1) * to - sum_div(m - 1 - a, m, d, to);
}
// sum( (a + d*i) % m ) for i in [0, n-1]
ll sum_mod(ll a, ll d, ll m, ll n) {
  a = ((a % m) + m) % m, d = ((d % m) + m) % m;
  return n * a + d * sum(n) - m * sum_div(a, d, m, n);
}
//Example Code
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include <bits/stdc++.h>
using namespace std;

#include "../SumDiv_SumMod.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        ll n, m, a, b; cin >> n >> m >> a >> b;
        cout << sum_div(b, a, m, n) << '\n';
    }
    return 0;
}