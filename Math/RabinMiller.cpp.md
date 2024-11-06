---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/SnapDragon64/ContestLibrary/blob/master/math.h
    - https://judge.yosupo.jp/problem/primality_test
    - https://oj.vnoi.info/problem/icpc22_national_c
    - https://www.spoj.com/problems/PON/
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../template.h:\
    \ line -1: no such header\n"
  code: "// From https://github.com/SnapDragon64/ContestLibrary/blob/master/math.h\n\
    // which also has specialized versions for 32-bit and 42-bit\n//\n// Tested:\n\
    // - https://oj.vnoi.info/problem/icpc22_national_c (fastest solution)\n// - https://www.spoj.com/problems/PON/\n\
    \n// Rabin miller {{{\ninline uint64_t mod_mult64(uint64_t a, uint64_t b, uint64_t\
    \ m) {\n    return __int128_t(a) * b % m;\n}\nuint64_t mod_pow64(uint64_t a, uint64_t\
    \ b, uint64_t m) {\n    uint64_t ret = (m > 1);\n    for (;;) {\n        if (b\
    \ & 1) ret = mod_mult64(ret, a, m);\n        if (!(b >>= 1)) return ret;\n   \
    \     a = mod_mult64(a, a, m);\n    }\n}\n\n// Works for all primes p < 2^64\n\
    bool is_prime(uint64_t n) {\n    if (n <= 3) return (n >= 2);\n    static const\
    \ uint64_t small[] = {\n        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,\
    \ 43, 47, 53, 59, 61, 67,\n        71, 73, 79, 83, 89, 97, 101, 103, 107, 109,\
    \ 113, 127, 131, 137, 139,\n        149, 151, 157, 163, 167, 173, 179, 181, 191,\
    \ 193, 197, 199,\n    };\n    for (size_t i = 0; i < sizeof(small) / sizeof(uint64_t);\
    \ ++i) {\n        if (n % small[i] == 0) return n == small[i];\n    }\n\n    //\
    \ Makes use of the known bounds for Miller-Rabin pseudoprimes.\n    static const\
    \ uint64_t millerrabin[] = {\n        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,\
    \ 37,\n    };\n    static const uint64_t A014233[] = {  // From OEIS.\n      \
    \  2047LL, 1373653LL, 25326001LL, 3215031751LL, 2152302898747LL,\n        3474749660383LL,\
    \ 341550071728321LL, 341550071728321LL,\n        3825123056546413051LL, 3825123056546413051LL,\
    \ 3825123056546413051LL, 0,\n    };\n    uint64_t s = n-1, r = 0;\n    while (s\
    \ % 2 == 0) {\n        s /= 2;\n        r++;\n    }\n    for (size_t i = 0, j;\
    \ i < sizeof(millerrabin) / sizeof(uint64_t); i++) {\n        uint64_t md = mod_pow64(millerrabin[i],\
    \ s, n);\n        if (md != 1) {\n            for (j = 1; j < r; j++) {\n    \
    \            if (md == n-1) break;\n                md = mod_mult64(md, md, n);\n\
    \            }\n            if (md != n-1) return false;\n        }\n        if\
    \ (n < A014233[i]) return true;\n    }\n    return true;\n}\n// }}}\n//Example\
    \ Code\n#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n\
    #include \"../../template.h\"\n#include \"../Prime/RabinMiller.h\"\n\nvoid solve()\
    \ {\n    int q; cin >> q;\n    while (q--) {\n        int64_t n; cin >> n;\n \
    \       cout << (is_prime(n) ? \"Yes\" : \"No\") << '\\n';\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/RabinMiller.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/RabinMiller.cpp
layout: document
redirect_from:
- /library/Math/RabinMiller.cpp
- /library/Math/RabinMiller.cpp.html
title: Math/RabinMiller.cpp
---
