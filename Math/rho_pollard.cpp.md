---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/rho_pollard.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"Math/rho_pollard.cpp\"\nusing namespace std;\ntypedef long long ll;\n\n\
    //Ph\xE9p nh\xE2n v\xE0 ph\xE9p lu\u1EF9 th\u1EEBa s\u1ED1 l\u1EDBn (h\u1ED7 tr\u1EE3\
    \ cho Rho-Pollard)\n\nlong long mult(long long a, long long b, long long mod)\
    \ {\n    return (__int128)a * b % mod;\n}\n\nuint64_t mod_pow64(uint64_t a, uint64_t\
    \ b, uint64_t m) {\n    uint64_t ret = (m > 1);\n    for (;;) {\n        if (b\
    \ & 1) ret = mult(ret, a, m);\n        if (!(b >>= 1)) return ret;\n        a\
    \ = mult(a, a, m);\n    }\n}\n\n//Th\u1EF1c hi\u1EC7n f(x) = (x^2 + c) mod i\n\
    \nlong long f(long long x, long long c, long long mod) {\n    return (mult(x,\
    \ x, mod) + c) % mod;\n}\n\n//Check isPrime, using RabinMiller (l\u1EA5y t\u1EEB\
    \ notebook ra)\n\nbool isPrime(uint64_t n)\n{\n    if (n <= 3) return (n >= 2);\n\
    \    static const uint64_t small[] = {\n        2, 3, 5, 7, 11, 13, 17, 19, 23,\
    \ 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,\n        71, 73, 79, 83, 89, 97, 101,\
    \ 103, 107, 109, 113, 127, 131, 137, 139,\n        149, 151, 157, 163, 167, 173,\
    \ 179, 181, 191, 193, 197, 199,\n    };\n    for (size_t i = 0; i < sizeof(small)\
    \ / sizeof(uint64_t); ++i) {\n        if (n % small[i] == 0) return n == small[i];\n\
    \    }\n\n    // Makes use of the known bounds for Miller-Rabin pseudoprimes.\n\
    \    static const uint64_t millerrabin[] = {\n        2, 3, 5, 7, 11, 13, 17,\
    \ 19, 23, 29, 31, 37,\n    };\n    static const uint64_t A014233[] = {  // From\
    \ OEIS.\n        2047LL, 1373653LL, 25326001LL, 3215031751LL, 2152302898747LL,\n\
    \        3474749660383LL, 341550071728321LL, 341550071728321LL,\n        3825123056546413051LL,\
    \ 3825123056546413051LL, 3825123056546413051LL, 0,\n    };\n    uint64_t s = n\
    \ - 1, r = 0;\n    while (s % 2 == 0) {\n        s /= 2;\n        r++;\n    }\n\
    \    for (size_t i = 0, j; i < sizeof(millerrabin) / sizeof(uint64_t); i++) {\n\
    \        uint64_t md = mod_pow64(millerrabin[i], s, n);\n        if (md != 1)\
    \ {\n            for (j = 1; j < r; j++) {\n                if (md == n - 1) break;\n\
    \                md = mult(md, md, n);\n            }\n            if (md != n\
    \ - 1) return false;\n        }\n        if (n < A014233[i]) return true;\n  \
    \  }\n    return true;\n}\n\n//H\xE0m random s\u1ED1 x\u1ECBn vl\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    long long get_rand(long long r)\n{\n    return uniform_int_distribution<long long>(0,\
    \ r - 1)(rng);\n}\n\n//\u0110\u01B0a ra GCD n\xE0y d\u1EC5 r\u1ED3i\nll gcd(ll\
    \ x, ll y)\n{\n    return y == 0 ? x : gcd(y, x % y);\n}\n\n//Thu\u1EADt to\xE1\
    n Rho c\u1EE7a Pollard cho ra 1 d\xE3y fact c\u1EA7n t\xECm, \u0111ang t\xEDnh\
    \ kh\xF4ng c\u1EA7n d\xF9ng\n//c\u1EA3i ti\u1EBFn c\u1EE7a Brent (do \u0111\u1ECD\
    c \u0111o\u1EA1n n\xE0y xong kh\xF4ng hi\u1EC3u g\xEC c\u1EA3)\n//Update l\xE0\
    \ m\xE3i c\u0169ng fix \u0111\u01B0\u1EE3c r\u1ED3i\n\nvoid rho_pollard(long long\
    \ n, vector<long long> &ans)\n{\n    if (n == 1) return;\n    if (isPrime(n))\
    \ {\n        ans.push_back(n);\n        return;\n    }\n    if (n % 2 == 0) {\n\
    \        ans.push_back(2);\n        rho_pollard(n << 1, ans);\n        return;\n\
    \    }\n\n    ll x = 2, y = 2, c = 1 + get_rand(n - 1);\n    ll d = 1;\n    while\
    \ (d == 1) {\n        x = f(x, c, n);\n        y = f(f(y, c, n), c, n);\n    \
    \    d = gcd(abs(x - y), n);\n    }\n    if (d == n) {\n        rho_pollard(n,\
    \ ans);\n    } else {\n        rho_pollard(d, ans);\n        rho_pollard(n / d,\
    \ ans);\n    }\n}\n\nvector<ll> fact(ll x)\n{\n    vector<ll> ans;\n    for (ll\
    \ p : {2, 3, 5, 7, 11, 13, 17, 19}) {\n        while (x % p == 0) {\n        \
    \    x /= p;\n            ans.push_back(p);\n        }\n    }\n    if (x != 1)\
    \ {\n        rho_pollard(x, ans);\n    }\n    sort(ans.begin(), ans.end());\n\
    \    return ans;\n}\n\n//L\xE0m \u0111\u1EB9p \u0111\u1EC3 tho\u1EA3 m\xE3n ycbt\n\
    vector<pair<ll, int>> solve(ll x) {\n    auto ps = fact(x); //l\u01B0\u1EDDi qu\xE1\
    \ n\xEAn d\xF9ng auto :(\n    ll last = -1, cnt = 0;\n    vector<pair<ll, int>>\
    \ res;\n    for (auto p : ps) {\n        if (p == last) ++cnt;\n        else {\n\
    \            if (last > 0) res.emplace_back(last, cnt);\n            last = p;\n\
    \            cnt = 1;\n        }\n    }\n    if (cnt > 0) {\n        res.emplace_back(last,\
    \ cnt);\n    }\n    return res;\n}\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(NULL);\n\n    uint64_t n;\n    cin >> n;\n        for (auto &[last,\
    \ cnt] : solve(n))\n        {\n            cout << last << \" \" << cnt << endl;\n\
    \        }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n#include <cstdint>\nusing namespace std;\ntypedef\
    \ long long ll;\n\n//Ph\xE9p nh\xE2n v\xE0 ph\xE9p lu\u1EF9 th\u1EEBa s\u1ED1\
    \ l\u1EDBn (h\u1ED7 tr\u1EE3 cho Rho-Pollard)\n\nlong long mult(long long a, long\
    \ long b, long long mod) {\n    return (__int128)a * b % mod;\n}\n\nuint64_t mod_pow64(uint64_t\
    \ a, uint64_t b, uint64_t m) {\n    uint64_t ret = (m > 1);\n    for (;;) {\n\
    \        if (b & 1) ret = mult(ret, a, m);\n        if (!(b >>= 1)) return ret;\n\
    \        a = mult(a, a, m);\n    }\n}\n\n//Th\u1EF1c hi\u1EC7n f(x) = (x^2 + c)\
    \ mod i\n\nlong long f(long long x, long long c, long long mod) {\n    return\
    \ (mult(x, x, mod) + c) % mod;\n}\n\n//Check isPrime, using RabinMiller (l\u1EA5\
    y t\u1EEB notebook ra)\n\nbool isPrime(uint64_t n)\n{\n    if (n <= 3) return\
    \ (n >= 2);\n    static const uint64_t small[] = {\n        2, 3, 5, 7, 11, 13,\
    \ 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,\n        71, 73, 79, 83,\
    \ 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,\n        149, 151, 157,\
    \ 163, 167, 173, 179, 181, 191, 193, 197, 199,\n    };\n    for (size_t i = 0;\
    \ i < sizeof(small) / sizeof(uint64_t); ++i) {\n        if (n % small[i] == 0)\
    \ return n == small[i];\n    }\n\n    // Makes use of the known bounds for Miller-Rabin\
    \ pseudoprimes.\n    static const uint64_t millerrabin[] = {\n        2, 3, 5,\
    \ 7, 11, 13, 17, 19, 23, 29, 31, 37,\n    };\n    static const uint64_t A014233[]\
    \ = {  // From OEIS.\n        2047LL, 1373653LL, 25326001LL, 3215031751LL, 2152302898747LL,\n\
    \        3474749660383LL, 341550071728321LL, 341550071728321LL,\n        3825123056546413051LL,\
    \ 3825123056546413051LL, 3825123056546413051LL, 0,\n    };\n    uint64_t s = n\
    \ - 1, r = 0;\n    while (s % 2 == 0) {\n        s /= 2;\n        r++;\n    }\n\
    \    for (size_t i = 0, j; i < sizeof(millerrabin) / sizeof(uint64_t); i++) {\n\
    \        uint64_t md = mod_pow64(millerrabin[i], s, n);\n        if (md != 1)\
    \ {\n            for (j = 1; j < r; j++) {\n                if (md == n - 1) break;\n\
    \                md = mult(md, md, n);\n            }\n            if (md != n\
    \ - 1) return false;\n        }\n        if (n < A014233[i]) return true;\n  \
    \  }\n    return true;\n}\n\n//H\xE0m random s\u1ED1 x\u1ECBn vl\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    long long get_rand(long long r)\n{\n    return uniform_int_distribution<long long>(0,\
    \ r - 1)(rng);\n}\n\n//\u0110\u01B0a ra GCD n\xE0y d\u1EC5 r\u1ED3i\nll gcd(ll\
    \ x, ll y)\n{\n    return y == 0 ? x : gcd(y, x % y);\n}\n\n//Thu\u1EADt to\xE1\
    n Rho c\u1EE7a Pollard cho ra 1 d\xE3y fact c\u1EA7n t\xECm, \u0111ang t\xEDnh\
    \ kh\xF4ng c\u1EA7n d\xF9ng\n//c\u1EA3i ti\u1EBFn c\u1EE7a Brent (do \u0111\u1ECD\
    c \u0111o\u1EA1n n\xE0y xong kh\xF4ng hi\u1EC3u g\xEC c\u1EA3)\n//Update l\xE0\
    \ m\xE3i c\u0169ng fix \u0111\u01B0\u1EE3c r\u1ED3i\n\nvoid rho_pollard(long long\
    \ n, vector<long long> &ans)\n{\n    if (n == 1) return;\n    if (isPrime(n))\
    \ {\n        ans.push_back(n);\n        return;\n    }\n    if (n % 2 == 0) {\n\
    \        ans.push_back(2);\n        rho_pollard(n << 1, ans);\n        return;\n\
    \    }\n\n    ll x = 2, y = 2, c = 1 + get_rand(n - 1);\n    ll d = 1;\n    while\
    \ (d == 1) {\n        x = f(x, c, n);\n        y = f(f(y, c, n), c, n);\n    \
    \    d = gcd(abs(x - y), n);\n    }\n    if (d == n) {\n        rho_pollard(n,\
    \ ans);\n    } else {\n        rho_pollard(d, ans);\n        rho_pollard(n / d,\
    \ ans);\n    }\n}\n\nvector<ll> fact(ll x)\n{\n    vector<ll> ans;\n    for (ll\
    \ p : {2, 3, 5, 7, 11, 13, 17, 19}) {\n        while (x % p == 0) {\n        \
    \    x /= p;\n            ans.push_back(p);\n        }\n    }\n    if (x != 1)\
    \ {\n        rho_pollard(x, ans);\n    }\n    sort(ans.begin(), ans.end());\n\
    \    return ans;\n}\n\n//L\xE0m \u0111\u1EB9p \u0111\u1EC3 tho\u1EA3 m\xE3n ycbt\n\
    vector<pair<ll, int>> solve(ll x) {\n    auto ps = fact(x); //l\u01B0\u1EDDi qu\xE1\
    \ n\xEAn d\xF9ng auto :(\n    ll last = -1, cnt = 0;\n    vector<pair<ll, int>>\
    \ res;\n    for (auto p : ps) {\n        if (p == last) ++cnt;\n        else {\n\
    \            if (last > 0) res.emplace_back(last, cnt);\n            last = p;\n\
    \            cnt = 1;\n        }\n    }\n    if (cnt > 0) {\n        res.emplace_back(last,\
    \ cnt);\n    }\n    return res;\n}\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(NULL);\n\n    uint64_t n;\n    cin >> n;\n        for (auto &[last,\
    \ cnt] : solve(n))\n        {\n            cout << last << \" \" << cnt << endl;\n\
    \        }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/rho_pollard.cpp
  requiredBy: []
  timestamp: '2024-11-10 11:32:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/rho_pollard.cpp
layout: document
redirect_from:
- /library/Math/rho_pollard.cpp
- /library/Math/rho_pollard.cpp.html
title: Math/rho_pollard.cpp
---
