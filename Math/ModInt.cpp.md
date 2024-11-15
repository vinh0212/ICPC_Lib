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
  bundledCode: "#line 1 \"Math/ModInt.cpp\"\n// ModInt {{{\ntemplate<int MD> struct\
    \ ModInt {\n    using ll = long long;\n    int x;\n\n    constexpr ModInt() :\
    \ x(0) {}\n    constexpr ModInt(ll v) { _set(v % MD + MD); }\n    constexpr static\
    \ int mod() { return MD; }\n    constexpr explicit operator bool() const { return\
    \ x != 0; }\n\n    constexpr ModInt operator + (const ModInt& a) const {\n   \
    \     return ModInt()._set((ll) x + a.x);\n    }\n    constexpr ModInt operator\
    \ - (const ModInt& a) const {\n        return ModInt()._set((ll) x - a.x + MD);\n\
    \    }\n    constexpr ModInt operator * (const ModInt& a) const {\n        return\
    \ ModInt()._set((ll) x * a.x % MD);\n    }\n    constexpr ModInt operator / (const\
    \ ModInt& a) const {\n        return ModInt()._set((ll) x * a.inv().x % MD);\n\
    \    }\n    constexpr ModInt operator - () const {\n        return ModInt()._set(MD\
    \ - x);\n    }\n\n    constexpr ModInt& operator += (const ModInt& a) { return\
    \ *this = *this + a; }\n    constexpr ModInt& operator -= (const ModInt& a) {\
    \ return *this = *this - a; }\n    constexpr ModInt& operator *= (const ModInt&\
    \ a) { return *this = *this * a; }\n    constexpr ModInt& operator /= (const ModInt&\
    \ a) { return *this = *this / a; }\n\n    friend constexpr ModInt operator + (ll\
    \ a, const ModInt& b) {\n        return ModInt()._set(a % MD + b.x);\n    }\n\
    \    friend constexpr ModInt operator - (ll a, const ModInt& b) {\n        return\
    \ ModInt()._set(a % MD - b.x + MD);\n    }\n    friend constexpr ModInt operator\
    \ * (ll a, const ModInt& b) {\n        return ModInt()._set(a % MD * b.x % MD);\n\
    \    }\n    friend constexpr ModInt operator / (ll a, const ModInt& b) {\n   \
    \     return ModInt()._set(a % MD * b.inv().x % MD);\n    }\n\n    constexpr bool\
    \ operator == (const ModInt& a) const { return x == a.x; }\n    constexpr bool\
    \ operator != (const ModInt& a) const { return x != a.x; }\n\n    friend std::istream&\
    \ operator >> (std::istream& is, ModInt& other) {\n        ll val; is >> val;\n\
    \        other = ModInt(val);\n        return is;\n    }\n    constexpr friend\
    \ std::ostream& operator << (std::ostream& os, const ModInt& other) {\n      \
    \  return os << other.x;\n    }\n\n    constexpr ModInt pow(ll k) const {\n  \
    \      ModInt ans = 1, tmp = x;\n        while (k) {\n            if (k & 1) ans\
    \ *= tmp;\n            tmp *= tmp;\n            k >>= 1;\n        }\n        return\
    \ ans;\n    }\n\n    constexpr ModInt inv() const {\n        if (x < 1000111)\
    \ {\n            _precalc(1000111);\n            return invs[x];\n        }\n\
    \        int a = x, b = MD, ax = 1, bx = 0;\n        while (b) {\n           \
    \ int q = a/b, t = a%b;\n            a = b; b = t;\n            t = ax - bx*q;\n\
    \            ax = bx; bx = t;\n        }\n        assert(a == 1);\n        if\
    \ (ax < 0) ax += MD;\n        return ax;\n    }\n\n    static std::vector<ModInt>\
    \ factorials, inv_factorials, invs;\n    constexpr static void _precalc(int n)\
    \ {\n        if (factorials.empty()) {\n            factorials = {1};\n      \
    \      inv_factorials = {1};\n            invs = {0};\n        }\n        if (n\
    \ > MD) n = MD;\n        int old_sz = factorials.size();\n        if (n <= old_sz)\
    \ return;\n\n        factorials.resize(n);\n        inv_factorials.resize(n);\n\
    \        invs.resize(n);\n\n        for (int i = old_sz; i < n; ++i) factorials[i]\
    \ = factorials[i-1] * i;\n        inv_factorials[n-1] = factorials.back().pow(MD\
    \ - 2);\n        for (int i = n - 2; i >= old_sz; --i) inv_factorials[i] = inv_factorials[i+1]\
    \ * (i+1);\n        for (int i = n-1; i >= old_sz; --i) invs[i] = inv_factorials[i]\
    \ * factorials[i-1];\n    }\n\n    static int get_primitive_root() {\n       \
    \ static int primitive_root = 0;\n        if (!primitive_root) {\n           \
    \ primitive_root = [&]() {\n                std::set<int> fac;\n             \
    \   int v = MD - 1;\n                for (ll i = 2; i * i <= v; i++)\n       \
    \             while (v % i == 0) fac.insert(i), v /= i;\n                if (v\
    \ > 1) fac.insert(v);\n                for (int g = 1; g < MD; g++) {\n      \
    \              bool ok = true;\n                    for (auto i : fac)\n     \
    \                   if (ModInt(g).pow((MD - 1) / i) == 1) {\n                \
    \            ok = false;\n                            break;\n               \
    \         }\n                    if (ok) return g;\n                }\n      \
    \          return -1;\n            }();\n        }\n        return primitive_root;\n\
    \    }\n\n    static ModInt C(int n, int k) {\n        _precalc(n + 1);\n    \
    \    return factorials[n] * inv_factorials[k] * inv_factorials[n-k];\n    }\n\
    \    \nprivate:\n    // Internal, DO NOT USE.\n    // val must be in [0, 2*MD)\n\
    \    constexpr inline __attribute__((always_inline)) ModInt& _set(ll v) {\n  \
    \      x = v >= MD ? v - MD : v;\n        return *this;\n    }\n};\ntemplate <int\
    \ MD> std::vector<ModInt<MD>> ModInt<MD>::factorials = {1};\ntemplate <int MD>\
    \ std::vector<ModInt<MD>> ModInt<MD>::inv_factorials = {1};\ntemplate <int MD>\
    \ std::vector<ModInt<MD>> ModInt<MD>::invs = {0};\n// }}}\n\n//Example Code\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n// \u0110\u1EB7t \u0111o\u1EA1\
    n m\xE3 ModInt \u1EDF \u0111\xE2y ho\u1EB7c bao g\u1ED3m n\xF3 t\u1EEB file kh\xE1\
    c\n// ...\n\nconst int MOD = 1000000007;\nusing mint = ModInt<MOD>;\n\nint main()\
    \ {\n    // Kh\u1EDFi t\u1EA1o\n    mint a = 10;\n    mint b = 20;\n    mint c\
    \ = -15;\n    mint d = 1000000017;\n\n    // Hi\u1EC3n th\u1ECB c\xE1c gi\xE1\
    \ tr\u1ECB\n    cout << \"a = \" << a << \"\\n\"; // a = 10\n    cout << \"b =\
    \ \" << b << \"\\n\"; // b = 20\n    cout << \"c = \" << c << \"\\n\"; // c =\
    \ 1000000007 - 15 = 999999992\n    cout << \"d = \" << d << \"\\n\"; // d = 10\n\
    \n    // Ph\xE9p to\xE1n\n    mint sum = a + b;\n    mint diff = a - b;\n    mint\
    \ prod = a * b;\n    mint quot = a / b;\n    mint power = a.pow(5);\n    mint\
    \ combinations = mint::C(5, 2);\n\n    // Hi\u1EC3n th\u1ECB k\u1EBFt qu\u1EA3\
    \ ph\xE9p to\xE1n\n    cout << \"a + b = \" << sum << \"\\n\";           // 30\n\
    \    cout << \"a - b = \" << diff << \"\\n\";          // 999999997\n    cout\
    \ << \"a * b = \" << prod << \"\\n\";          // 200\n    cout << \"a / b = \"\
    \ << quot << \"\\n\";          // 100 * inv(20) = 100 * 850000005 = 500000005\
    \ mod MOD\n    cout << \"a^5 = \" << power << \"\\n\";           // 100000\n \
    \   cout << \"C(5, 2) = \" << combinations << \"\\n\"; // 10\n\n    return 0;\n\
    }\n\n"
  code: "// ModInt {{{\ntemplate<int MD> struct ModInt {\n    using ll = long long;\n\
    \    int x;\n\n    constexpr ModInt() : x(0) {}\n    constexpr ModInt(ll v) {\
    \ _set(v % MD + MD); }\n    constexpr static int mod() { return MD; }\n    constexpr\
    \ explicit operator bool() const { return x != 0; }\n\n    constexpr ModInt operator\
    \ + (const ModInt& a) const {\n        return ModInt()._set((ll) x + a.x);\n \
    \   }\n    constexpr ModInt operator - (const ModInt& a) const {\n        return\
    \ ModInt()._set((ll) x - a.x + MD);\n    }\n    constexpr ModInt operator * (const\
    \ ModInt& a) const {\n        return ModInt()._set((ll) x * a.x % MD);\n    }\n\
    \    constexpr ModInt operator / (const ModInt& a) const {\n        return ModInt()._set((ll)\
    \ x * a.inv().x % MD);\n    }\n    constexpr ModInt operator - () const {\n  \
    \      return ModInt()._set(MD - x);\n    }\n\n    constexpr ModInt& operator\
    \ += (const ModInt& a) { return *this = *this + a; }\n    constexpr ModInt& operator\
    \ -= (const ModInt& a) { return *this = *this - a; }\n    constexpr ModInt& operator\
    \ *= (const ModInt& a) { return *this = *this * a; }\n    constexpr ModInt& operator\
    \ /= (const ModInt& a) { return *this = *this / a; }\n\n    friend constexpr ModInt\
    \ operator + (ll a, const ModInt& b) {\n        return ModInt()._set(a % MD +\
    \ b.x);\n    }\n    friend constexpr ModInt operator - (ll a, const ModInt& b)\
    \ {\n        return ModInt()._set(a % MD - b.x + MD);\n    }\n    friend constexpr\
    \ ModInt operator * (ll a, const ModInt& b) {\n        return ModInt()._set(a\
    \ % MD * b.x % MD);\n    }\n    friend constexpr ModInt operator / (ll a, const\
    \ ModInt& b) {\n        return ModInt()._set(a % MD * b.inv().x % MD);\n    }\n\
    \n    constexpr bool operator == (const ModInt& a) const { return x == a.x; }\n\
    \    constexpr bool operator != (const ModInt& a) const { return x != a.x; }\n\
    \n    friend std::istream& operator >> (std::istream& is, ModInt& other) {\n \
    \       ll val; is >> val;\n        other = ModInt(val);\n        return is;\n\
    \    }\n    constexpr friend std::ostream& operator << (std::ostream& os, const\
    \ ModInt& other) {\n        return os << other.x;\n    }\n\n    constexpr ModInt\
    \ pow(ll k) const {\n        ModInt ans = 1, tmp = x;\n        while (k) {\n \
    \           if (k & 1) ans *= tmp;\n            tmp *= tmp;\n            k >>=\
    \ 1;\n        }\n        return ans;\n    }\n\n    constexpr ModInt inv() const\
    \ {\n        if (x < 1000111) {\n            _precalc(1000111);\n            return\
    \ invs[x];\n        }\n        int a = x, b = MD, ax = 1, bx = 0;\n        while\
    \ (b) {\n            int q = a/b, t = a%b;\n            a = b; b = t;\n      \
    \      t = ax - bx*q;\n            ax = bx; bx = t;\n        }\n        assert(a\
    \ == 1);\n        if (ax < 0) ax += MD;\n        return ax;\n    }\n\n    static\
    \ std::vector<ModInt> factorials, inv_factorials, invs;\n    constexpr static\
    \ void _precalc(int n) {\n        if (factorials.empty()) {\n            factorials\
    \ = {1};\n            inv_factorials = {1};\n            invs = {0};\n       \
    \ }\n        if (n > MD) n = MD;\n        int old_sz = factorials.size();\n  \
    \      if (n <= old_sz) return;\n\n        factorials.resize(n);\n        inv_factorials.resize(n);\n\
    \        invs.resize(n);\n\n        for (int i = old_sz; i < n; ++i) factorials[i]\
    \ = factorials[i-1] * i;\n        inv_factorials[n-1] = factorials.back().pow(MD\
    \ - 2);\n        for (int i = n - 2; i >= old_sz; --i) inv_factorials[i] = inv_factorials[i+1]\
    \ * (i+1);\n        for (int i = n-1; i >= old_sz; --i) invs[i] = inv_factorials[i]\
    \ * factorials[i-1];\n    }\n\n    static int get_primitive_root() {\n       \
    \ static int primitive_root = 0;\n        if (!primitive_root) {\n           \
    \ primitive_root = [&]() {\n                std::set<int> fac;\n             \
    \   int v = MD - 1;\n                for (ll i = 2; i * i <= v; i++)\n       \
    \             while (v % i == 0) fac.insert(i), v /= i;\n                if (v\
    \ > 1) fac.insert(v);\n                for (int g = 1; g < MD; g++) {\n      \
    \              bool ok = true;\n                    for (auto i : fac)\n     \
    \                   if (ModInt(g).pow((MD - 1) / i) == 1) {\n                \
    \            ok = false;\n                            break;\n               \
    \         }\n                    if (ok) return g;\n                }\n      \
    \          return -1;\n            }();\n        }\n        return primitive_root;\n\
    \    }\n\n    static ModInt C(int n, int k) {\n        _precalc(n + 1);\n    \
    \    return factorials[n] * inv_factorials[k] * inv_factorials[n-k];\n    }\n\
    \    \nprivate:\n    // Internal, DO NOT USE.\n    // val must be in [0, 2*MD)\n\
    \    constexpr inline __attribute__((always_inline)) ModInt& _set(ll v) {\n  \
    \      x = v >= MD ? v - MD : v;\n        return *this;\n    }\n};\ntemplate <int\
    \ MD> std::vector<ModInt<MD>> ModInt<MD>::factorials = {1};\ntemplate <int MD>\
    \ std::vector<ModInt<MD>> ModInt<MD>::inv_factorials = {1};\ntemplate <int MD>\
    \ std::vector<ModInt<MD>> ModInt<MD>::invs = {0};\n// }}}\n\n//Example Code\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n// \u0110\u1EB7t \u0111o\u1EA1\
    n m\xE3 ModInt \u1EDF \u0111\xE2y ho\u1EB7c bao g\u1ED3m n\xF3 t\u1EEB file kh\xE1\
    c\n// ...\n\nconst int MOD = 1000000007;\nusing mint = ModInt<MOD>;\n\nint main()\
    \ {\n    // Kh\u1EDFi t\u1EA1o\n    mint a = 10;\n    mint b = 20;\n    mint c\
    \ = -15;\n    mint d = 1000000017;\n\n    // Hi\u1EC3n th\u1ECB c\xE1c gi\xE1\
    \ tr\u1ECB\n    cout << \"a = \" << a << \"\\n\"; // a = 10\n    cout << \"b =\
    \ \" << b << \"\\n\"; // b = 20\n    cout << \"c = \" << c << \"\\n\"; // c =\
    \ 1000000007 - 15 = 999999992\n    cout << \"d = \" << d << \"\\n\"; // d = 10\n\
    \n    // Ph\xE9p to\xE1n\n    mint sum = a + b;\n    mint diff = a - b;\n    mint\
    \ prod = a * b;\n    mint quot = a / b;\n    mint power = a.pow(5);\n    mint\
    \ combinations = mint::C(5, 2);\n\n    // Hi\u1EC3n th\u1ECB k\u1EBFt qu\u1EA3\
    \ ph\xE9p to\xE1n\n    cout << \"a + b = \" << sum << \"\\n\";           // 30\n\
    \    cout << \"a - b = \" << diff << \"\\n\";          // 999999997\n    cout\
    \ << \"a * b = \" << prod << \"\\n\";          // 200\n    cout << \"a / b = \"\
    \ << quot << \"\\n\";          // 100 * inv(20) = 100 * 850000005 = 500000005\
    \ mod MOD\n    cout << \"a^5 = \" << power << \"\\n\";           // 100000\n \
    \   cout << \"C(5, 2) = \" << combinations << \"\\n\"; // 10\n\n    return 0;\n\
    }\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/ModInt.cpp
  requiredBy: []
  timestamp: '2024-11-15 23:57:47+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/ModInt.cpp
layout: document
redirect_from:
- /library/Math/ModInt.cpp
- /library/Math/ModInt.cpp.html
title: Math/ModInt.cpp
---
