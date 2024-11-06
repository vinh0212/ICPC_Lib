#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
typedef long long ll;

//Phép nhân và phép luỹ thừa số lớn (hỗ trợ cho Rho-Pollard)

long long mult(long long a, long long b, long long mod) {
    return (__int128)a * b % mod;
}

uint64_t mod_pow64(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t ret = (m > 1);
    for (;;) {
        if (b & 1) ret = mult(ret, a, m);
        if (!(b >>= 1)) return ret;
        a = mult(a, a, m);
    }
}

//Thực hiện f(x) = (x^2 + c) mod i

long long f(long long x, long long c, long long mod) {
    return (mult(x, x, mod) + c) % mod;
}

//Check isPrime, using RabinMiller (lấy từ notebook ra)

bool isPrime(uint64_t n)
{
    if (n <= 3) return (n >= 2);
    static const uint64_t small[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
        71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,
        149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
    };
    for (size_t i = 0; i < sizeof(small) / sizeof(uint64_t); ++i) {
        if (n % small[i] == 0) return n == small[i];
    }

    // Makes use of the known bounds for Miller-Rabin pseudoprimes.
    static const uint64_t millerrabin[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
    };
    static const uint64_t A014233[] = {  // From OEIS.
        2047LL, 1373653LL, 25326001LL, 3215031751LL, 2152302898747LL,
        3474749660383LL, 341550071728321LL, 341550071728321LL,
        3825123056546413051LL, 3825123056546413051LL, 3825123056546413051LL, 0,
    };
    uint64_t s = n - 1, r = 0;
    while (s % 2 == 0) {
        s /= 2;
        r++;
    }
    for (size_t i = 0, j; i < sizeof(millerrabin) / sizeof(uint64_t); i++) {
        uint64_t md = mod_pow64(millerrabin[i], s, n);
        if (md != 1) {
            for (j = 1; j < r; j++) {
                if (md == n - 1) break;
                md = mult(md, md, n);
            }
            if (md != n - 1) return false;
        }
        if (n < A014233[i]) return true;
    }
    return true;
}

//Hàm random số xịn vl
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long get_rand(long long r)
{
    return uniform_int_distribution<long long>(0, r - 1)(rng);
}

//Đưa ra GCD này dễ rồi
ll gcd(ll x, ll y)
{
    return y == 0 ? x : gcd(y, x % y);
}

//Thuật toán Rho của Pollard cho ra 1 dãy fact cần tìm, đang tính không cần dùng
//cải tiến của Brent (do đọc đoạn này xong không hiểu gì cả)
//Update là mãi cũng fix được rồi

void rho_pollard(long long n, vector<long long> &ans)
{
    if (n == 1) return;
    if (isPrime(n)) {
        ans.push_back(n);
        return;
    }
    if (n % 2 == 0) {
        ans.push_back(2);
        rho_pollard(n << 1, ans);
        return;
    }

    ll x = 2, y = 2, c = 1 + get_rand(n - 1);
    ll d = 1;
    while (d == 1) {
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);
        d = gcd(abs(x - y), n);
    }
    if (d == n) {
        rho_pollard(n, ans);
    } else {
        rho_pollard(d, ans);
        rho_pollard(n / d, ans);
    }
}

vector<ll> fact(ll x)
{
    vector<ll> ans;
    for (ll p : {2, 3, 5, 7, 11, 13, 17, 19}) {
        while (x % p == 0) {
            x /= p;
            ans.push_back(p);
        }
    }
    if (x != 1) {
        rho_pollard(x, ans);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

//Làm đẹp để thoả mãn ycbt
vector<pair<ll, int>> solve(ll x) {
    auto ps = fact(x); //lười quá nên dùng auto :(
    ll last = -1, cnt = 0;
    vector<pair<ll, int>> res;
    for (auto p : ps) {
        if (p == last) ++cnt;
        else {
            if (last > 0) res.emplace_back(last, cnt);
            last = p;
            cnt = 1;
        }
    }
    if (cnt > 0) {
        res.emplace_back(last, cnt);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    uint64_t n;
    cin >> n;
        for (auto &[last, cnt] : solve(n))
        {
            cout << last << " " << cnt << endl;
        }
    return 0;
}
