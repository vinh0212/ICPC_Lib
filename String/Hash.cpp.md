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
  bundledCode: "#line 1 \"String/Hash.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// \u0110\u1ECBnh ngh\u0129a c\xE1c h\u1EB1ng s\u1ED1 modulo v\xE0 base\n\
    const long long MOD1 = 1000000007;\nconst long long MOD2 = 1000000009;\nconst\
    \ int BASE = 911382629; // B\u1EA1n c\xF3 th\u1EC3 ch\u1ECDn m\u1ED9t base kh\xE1\
    c t\xF9y \xFD\n\n// C\u1EA5u tr\xFAc Hash ch\u1EE9a hai gi\xE1 tr\u1ECB hash\n\
    struct Hash {\n    long long x; // Hash v\u1EDBi MOD1\n    long long y; // Hash\
    \ v\u1EDBi MOD2\n\n    // Constructor m\u1EB7c \u0111\u1ECBnh\n    Hash() : x(0),\
    \ y(0) {}\n\n    // Constructor v\u1EDBi gi\xE1 tr\u1ECB c\u1EE5 th\u1EC3\n  \
    \  Hash(long long _x, long long _y) : x(_x), y(_y) {}\n\n    // Overload c\xE1\
    c ph\xE9p to\xE1n c\u1ED9ng, tr\u1EEB, nh\xE2n\n    Hash operator + (const Hash&\
    \ other) const {\n        return Hash((x + other.x) % MOD1, (y + other.y) % MOD2);\n\
    \    }\n\n    Hash operator - (const Hash& other) const {\n        return Hash((x\
    \ - other.x + MOD1) % MOD1, (y - other.y + MOD2) % MOD2);\n    }\n\n    Hash operator\
    \ * (const Hash& other) const {\n        return Hash((x * other.x) % MOD1, (y\
    \ * other.y) % MOD2);\n    }\n\n    // Ph\xE9p nh\xE2n v\u1EDBi m\u1ED9t s\u1ED1\
    \ nguy\xEAn\n    Hash operator * (long long k) const {\n        return Hash((x\
    \ * k) % MOD1, (y * k) % MOD2);\n    }\n\n    // Overload c\xE1c ph\xE9p to\xE1\
    n g\xE1n k\u1EBFt h\u1EE3p\n    Hash& operator += (const Hash& other) {\n    \
    \    x = (x + other.x) % MOD1;\n        y = (y + other.y) % MOD2;\n        return\
    \ *this;\n    }\n\n    Hash& operator -= (const Hash& other) {\n        x = (x\
    \ - other.x + MOD1) % MOD1;\n        y = (y - other.y + MOD2) % MOD2;\n      \
    \  return *this;\n    }\n\n    Hash& operator *= (const Hash& other) {\n     \
    \   x = (x * other.x) % MOD1;\n        y = (y * other.y) % MOD2;\n        return\
    \ *this;\n    }\n\n    // So s\xE1nh hai Hash\n    bool operator == (const Hash&\
    \ other) const {\n        return (x == other.x) && (y == other.y);\n    }\n\n\
    \    bool operator < (const Hash& other) const {\n        if(x != other.x) return\
    \ x < other.x;\n        return y < other.y;\n    }\n};\n\n// Overload operator\
    \ << \u0111\u1EC3 d\u1EC5 d\xE0ng in Hash (ch\u1EC9 d\xF9ng cho debug)\nostream&\
    \ operator << (ostream& out, const Hash& h) {\n    out << '(' << h.x << \", \"\
    \ << h.y << ')';\n    return out;\n}\n\n// \u0110\u1ECBnh ngh\u0129a h\xE0m b\u0103\
    m cho std::unordered_map\nnamespace std {\n    template<>\n    struct hash<Hash>\
    \ {\n        size_t operator() (const Hash& h) const {\n            return hash<long\
    \ long>()(h.x) * 1000000007 + hash<long long>()(h.y);\n        }\n    };\n}\n\n\
    // L\u1EDBp HashGenerator \u0111\u1EC3 t\xEDnh to\xE1n v\xE0 qu\u1EA3n l\xFD c\xE1\
    c gi\xE1 tr\u1ECB hash\nstruct HashGenerator {\n    // L\u01B0u tr\u1EEF c\xE1\
    c gi\xE1 tr\u1ECB base^i mod MOD1 v\xE0 MOD2\n    vector<long long> power1;\n\
    \    vector<long long> power2;\n    int base;\n\n    // Constructor\n    HashGenerator(int\
    \ maxLen, int _base = BASE) : base(_base) {\n        power1.resize(maxLen + 1);\n\
    \        power2.resize(maxLen + 1);\n        power1[0] = 1;\n        power2[0]\
    \ = 1;\n        for(int i = 1; i <= maxLen; i++) {\n            power1[i] = (power1[i-1]\
    \ * base) % MOD1;\n            power2[i] = (power2[i-1] * base) % MOD2;\n    \
    \    }\n    }\n\n    // T\xEDnh hash prefix cho m\u1ED9t chu\u1ED7i\n    template<typename\
    \ Container>\n    vector<Hash> computeHash(const Container& s) const {\n     \
    \   int n = s.size();\n        vector<Hash> prefixHash(n, Hash(0, 0));\n     \
    \   if(n == 0) return prefixHash;\n        prefixHash[0] = Hash(s[0], s[0]);\n\
    \        for(int i = 1; i < n; i++) {\n            prefixHash[i].x = (prefixHash[i-1].x\
    \ * base + s[i]) % MOD1;\n            prefixHash[i].y = (prefixHash[i-1].y * base\
    \ + s[i]) % MOD2;\n        }\n        return prefixHash;\n    }\n\n    // L\u1EA5\
    y hash c\u1EE7a chu\u1ED7i con [l, r]\n    Hash getHash(const vector<Hash>& prefixHash,\
    \ int l, int r) const {\n        if(l > r) return Hash(0, 0);\n        if(l ==\
    \ 0) return prefixHash[r];\n        long long hash1 = (prefixHash[r].x - (prefixHash[l-1].x\
    \ * power1[r-l+1]) % MOD1 + MOD1) % MOD1;\n        long long hash2 = (prefixHash[r].y\
    \ - (prefixHash[l-1].y * power2[r-l+1]) % MOD2 + MOD2) % MOD2;\n        return\
    \ Hash(hash1, hash2);\n    }\n\n    // So s1[l1, r1] v\xE0 s2[l2, r2] c\xF3 b\u1EB1\
    ng nhau hay kh\xF4ng\n    bool equals(\n        const vector<Hash>& h1, int l1,\
    \ int r1,\n        const vector<Hash>& h2, int l2, int r2\n    ) const {\n   \
    \     if((r1 - l1) != (r2 - l2)) return false;\n        Hash hash1 = getHash(h1,\
    \ l1, r1);\n        Hash hash2 = getHash(h2, l2, r2);\n        return hash1 ==\
    \ hash2;\n    }\n\n    // Tr\u1EA3 v\u1EC1 \u0111\u1ED9 d\xE0i c\u1EE7a ti\u1EC1\
    n t\u1ED1 chung l\u1EDBn nh\u1EA5t gi\u1EEFa s1[l1, r1] v\xE0 s2[l2, r2]\n   \
    \ int maxCommonPrefix(\n        const vector<Hash>& h1, int l1, int r1,\n    \
    \    const vector<Hash>& h2, int l2, int r2\n    ) const {\n        int len1 =\
    \ r1 - l1 + 1;\n        int len2 = r2 - l2 + 1;\n        int low = 0;\n      \
    \  int high = min(len1, len2);\n        int res = 0;\n        while(low <= high)\
    \ {\n            int mid = low + (high - low) / 2;\n            if(mid == 0) {\n\
    \                res = 0;\n                low = mid + 1;\n                continue;\n\
    \            }\n            Hash subHash1 = getHash(h1, l1, l1 + mid - 1);\n \
    \           Hash subHash2 = getHash(h2, l2, l2 + mid - 1);\n            if(subHash1\
    \ == subHash2) {\n                res = mid;\n                low = mid + 1;\n\
    \            }\n            else {\n                high = mid - 1;\n        \
    \    }\n        }\n        return res;\n    }\n\n    // So s1[l1, r1] v\xE0 s2[l2,\
    \ r2]\n    template<typename Container1, typename Container2>\n    int cmp(\n\
    \        const Container1& s1, const vector<Hash>& h1, int l1, int r1,\n     \
    \   const Container2& s2, const vector<Hash>& h2, int l2, int r2\n    ) const\
    \ {\n        int common = maxCommonPrefix(h1, l1, r1, h2, l2, r2);\n        char\
    \ c1 = (l1 + common <= r1) ? s1[l1 + common] : '\\0';\n        char c2 = (l2 +\
    \ common <= r2) ? s2[l2 + common] : '\\0';\n        if(c1 == c2) return 0;\n \
    \       return (c1 < c2) ? -1 : 1;\n    }\n};\n\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// \u0110\u1ECBnh ngh\u0129\
    a c\xE1c h\u1EB1ng s\u1ED1 modulo v\xE0 base\nconst long long MOD1 = 1000000007;\n\
    const long long MOD2 = 1000000009;\nconst int BASE = 911382629; // B\u1EA1n c\xF3\
    \ th\u1EC3 ch\u1ECDn m\u1ED9t base kh\xE1c t\xF9y \xFD\n\n// C\u1EA5u tr\xFAc\
    \ Hash ch\u1EE9a hai gi\xE1 tr\u1ECB hash\nstruct Hash {\n    long long x; //\
    \ Hash v\u1EDBi MOD1\n    long long y; // Hash v\u1EDBi MOD2\n\n    // Constructor\
    \ m\u1EB7c \u0111\u1ECBnh\n    Hash() : x(0), y(0) {}\n\n    // Constructor v\u1EDB\
    i gi\xE1 tr\u1ECB c\u1EE5 th\u1EC3\n    Hash(long long _x, long long _y) : x(_x),\
    \ y(_y) {}\n\n    // Overload c\xE1c ph\xE9p to\xE1n c\u1ED9ng, tr\u1EEB, nh\xE2\
    n\n    Hash operator + (const Hash& other) const {\n        return Hash((x + other.x)\
    \ % MOD1, (y + other.y) % MOD2);\n    }\n\n    Hash operator - (const Hash& other)\
    \ const {\n        return Hash((x - other.x + MOD1) % MOD1, (y - other.y + MOD2)\
    \ % MOD2);\n    }\n\n    Hash operator * (const Hash& other) const {\n       \
    \ return Hash((x * other.x) % MOD1, (y * other.y) % MOD2);\n    }\n\n    // Ph\xE9\
    p nh\xE2n v\u1EDBi m\u1ED9t s\u1ED1 nguy\xEAn\n    Hash operator * (long long\
    \ k) const {\n        return Hash((x * k) % MOD1, (y * k) % MOD2);\n    }\n\n\
    \    // Overload c\xE1c ph\xE9p to\xE1n g\xE1n k\u1EBFt h\u1EE3p\n    Hash& operator\
    \ += (const Hash& other) {\n        x = (x + other.x) % MOD1;\n        y = (y\
    \ + other.y) % MOD2;\n        return *this;\n    }\n\n    Hash& operator -= (const\
    \ Hash& other) {\n        x = (x - other.x + MOD1) % MOD1;\n        y = (y - other.y\
    \ + MOD2) % MOD2;\n        return *this;\n    }\n\n    Hash& operator *= (const\
    \ Hash& other) {\n        x = (x * other.x) % MOD1;\n        y = (y * other.y)\
    \ % MOD2;\n        return *this;\n    }\n\n    // So s\xE1nh hai Hash\n    bool\
    \ operator == (const Hash& other) const {\n        return (x == other.x) && (y\
    \ == other.y);\n    }\n\n    bool operator < (const Hash& other) const {\n   \
    \     if(x != other.x) return x < other.x;\n        return y < other.y;\n    }\n\
    };\n\n// Overload operator << \u0111\u1EC3 d\u1EC5 d\xE0ng in Hash (ch\u1EC9 d\xF9\
    ng cho debug)\nostream& operator << (ostream& out, const Hash& h) {\n    out <<\
    \ '(' << h.x << \", \" << h.y << ')';\n    return out;\n}\n\n// \u0110\u1ECBnh\
    \ ngh\u0129a h\xE0m b\u0103m cho std::unordered_map\nnamespace std {\n    template<>\n\
    \    struct hash<Hash> {\n        size_t operator() (const Hash& h) const {\n\
    \            return hash<long long>()(h.x) * 1000000007 + hash<long long>()(h.y);\n\
    \        }\n    };\n}\n\n// L\u1EDBp HashGenerator \u0111\u1EC3 t\xEDnh to\xE1\
    n v\xE0 qu\u1EA3n l\xFD c\xE1c gi\xE1 tr\u1ECB hash\nstruct HashGenerator {\n\
    \    // L\u01B0u tr\u1EEF c\xE1c gi\xE1 tr\u1ECB base^i mod MOD1 v\xE0 MOD2\n\
    \    vector<long long> power1;\n    vector<long long> power2;\n    int base;\n\
    \n    // Constructor\n    HashGenerator(int maxLen, int _base = BASE) : base(_base)\
    \ {\n        power1.resize(maxLen + 1);\n        power2.resize(maxLen + 1);\n\
    \        power1[0] = 1;\n        power2[0] = 1;\n        for(int i = 1; i <= maxLen;\
    \ i++) {\n            power1[i] = (power1[i-1] * base) % MOD1;\n            power2[i]\
    \ = (power2[i-1] * base) % MOD2;\n        }\n    }\n\n    // T\xEDnh hash prefix\
    \ cho m\u1ED9t chu\u1ED7i\n    template<typename Container>\n    vector<Hash>\
    \ computeHash(const Container& s) const {\n        int n = s.size();\n       \
    \ vector<Hash> prefixHash(n, Hash(0, 0));\n        if(n == 0) return prefixHash;\n\
    \        prefixHash[0] = Hash(s[0], s[0]);\n        for(int i = 1; i < n; i++)\
    \ {\n            prefixHash[i].x = (prefixHash[i-1].x * base + s[i]) % MOD1;\n\
    \            prefixHash[i].y = (prefixHash[i-1].y * base + s[i]) % MOD2;\n   \
    \     }\n        return prefixHash;\n    }\n\n    // L\u1EA5y hash c\u1EE7a chu\u1ED7\
    i con [l, r]\n    Hash getHash(const vector<Hash>& prefixHash, int l, int r) const\
    \ {\n        if(l > r) return Hash(0, 0);\n        if(l == 0) return prefixHash[r];\n\
    \        long long hash1 = (prefixHash[r].x - (prefixHash[l-1].x * power1[r-l+1])\
    \ % MOD1 + MOD1) % MOD1;\n        long long hash2 = (prefixHash[r].y - (prefixHash[l-1].y\
    \ * power2[r-l+1]) % MOD2 + MOD2) % MOD2;\n        return Hash(hash1, hash2);\n\
    \    }\n\n    // So s1[l1, r1] v\xE0 s2[l2, r2] c\xF3 b\u1EB1ng nhau hay kh\xF4\
    ng\n    bool equals(\n        const vector<Hash>& h1, int l1, int r1,\n      \
    \  const vector<Hash>& h2, int l2, int r2\n    ) const {\n        if((r1 - l1)\
    \ != (r2 - l2)) return false;\n        Hash hash1 = getHash(h1, l1, r1);\n   \
    \     Hash hash2 = getHash(h2, l2, r2);\n        return hash1 == hash2;\n    }\n\
    \n    // Tr\u1EA3 v\u1EC1 \u0111\u1ED9 d\xE0i c\u1EE7a ti\u1EC1n t\u1ED1 chung\
    \ l\u1EDBn nh\u1EA5t gi\u1EEFa s1[l1, r1] v\xE0 s2[l2, r2]\n    int maxCommonPrefix(\n\
    \        const vector<Hash>& h1, int l1, int r1,\n        const vector<Hash>&\
    \ h2, int l2, int r2\n    ) const {\n        int len1 = r1 - l1 + 1;\n       \
    \ int len2 = r2 - l2 + 1;\n        int low = 0;\n        int high = min(len1,\
    \ len2);\n        int res = 0;\n        while(low <= high) {\n            int\
    \ mid = low + (high - low) / 2;\n            if(mid == 0) {\n                res\
    \ = 0;\n                low = mid + 1;\n                continue;\n          \
    \  }\n            Hash subHash1 = getHash(h1, l1, l1 + mid - 1);\n           \
    \ Hash subHash2 = getHash(h2, l2, l2 + mid - 1);\n            if(subHash1 == subHash2)\
    \ {\n                res = mid;\n                low = mid + 1;\n            }\n\
    \            else {\n                high = mid - 1;\n            }\n        }\n\
    \        return res;\n    }\n\n    // So s1[l1, r1] v\xE0 s2[l2, r2]\n    template<typename\
    \ Container1, typename Container2>\n    int cmp(\n        const Container1& s1,\
    \ const vector<Hash>& h1, int l1, int r1,\n        const Container2& s2, const\
    \ vector<Hash>& h2, int l2, int r2\n    ) const {\n        int common = maxCommonPrefix(h1,\
    \ l1, r1, h2, l2, r2);\n        char c1 = (l1 + common <= r1) ? s1[l1 + common]\
    \ : '\\0';\n        char c2 = (l2 + common <= r2) ? s2[l2 + common] : '\\0';\n\
    \        if(c1 == c2) return 0;\n        return (c1 < c2) ? -1 : 1;\n    }\n};\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: String/Hash.cpp
  requiredBy: []
  timestamp: '2024-11-15 23:57:47+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Hash.cpp
layout: document
redirect_from:
- /library/String/Hash.cpp
- /library/String/Hash.cpp.html
title: String/Hash.cpp
---
