// Chinese Remainder Theorem {{{
// Tested:
// - https://oj.vnoi.info/problem/icpc21_mt_d
// - (__int128_t) https://judge.yosupo.jp/problem/convolution_mod_1000000007
template<typename T>
struct CRT {
    T res;

    CRT() {
        res = 0, prd = 1;
    }
    
    // Add condition: res % p == r
    void add(T p, T r) {
        res += mul(r - res % p + p, euclid(prd, p).first + p, p) * prd;
        prd *= p;
        if (res >= prd) res -= prd;
    }

private:
    T prd;
    T mul(T a, T b, T p) {
        a %= p, b %= p;
        T q = (T) ((long double) a * b / p);
        T r = a * b - q * p;
        while (r < 0) r += p;
        while (r >= p) r -= p;
        return r;
    }
    pair<T, T> euclid(T a, T b) {
        if (!b) return make_pair(1, 0);
        pair<T, T> r = euclid(b, a % b);
        return make_pair(r.second, r.first - a / b * r.second);
    }
};
// }}}
//Example Code
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <bits/stdc++.h>
using namespace std;

#include "../Polynomial/NTT_chemthan.h"
#include "../NumberTheory/CRT_chemthan.h"

const int MOD0 = 167772161;
const int MOD1 = 469762049;
const int MOD2 = 754974721;
NTT<MOD0, 1 << 20> ntt0;
NTT<MOD1, 1 << 20> ntt1;
NTT<MOD2, 1 << 20> ntt2;

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n); REP(i,n) cin >> a[i];
    vector<int> b(m); REP(i,m) cin >> b[i];

    auto c0 = ntt0.multiply(a, b);
    auto c1 = ntt1.multiply(a, b);
    auto c2 = ntt2.multiply(a, b);

    const int MOD = 1e9 + 7;
    REP(i,n+m-1) {
        CRT<__int128_t> crt;
        crt.add(MOD0, c0[i]);
        crt.add(MOD1, c1[i]);
        crt.add(MOD2, c2[i]);
        cout << (int) (crt.res % MOD) << ' ';
    }
    cout << endl;
    return 0;
}