#include <bits/stdc++.h>
using namespace std;

// Định nghĩa các hằng số modulo và base
const long long MOD1 = 1000000007;
const long long MOD2 = 1000000009;
const int BASE = 911382629; // Bạn có thể chọn một base khác tùy ý

// Cấu trúc Hash chứa hai giá trị hash
struct Hash {
    long long x; // Hash với MOD1
    long long y; // Hash với MOD2

    // Constructor mặc định
    Hash() : x(0), y(0) {}

    // Constructor với giá trị cụ thể
    Hash(long long _x, long long _y) : x(_x), y(_y) {}

    // Overload các phép toán cộng, trừ, nhân
    Hash operator + (const Hash& other) const {
        return Hash((x + other.x) % MOD1, (y + other.y) % MOD2);
    }

    Hash operator - (const Hash& other) const {
        return Hash((x - other.x + MOD1) % MOD1, (y - other.y + MOD2) % MOD2);
    }

    Hash operator * (const Hash& other) const {
        return Hash((x * other.x) % MOD1, (y * other.y) % MOD2);
    }

    // Phép nhân với một số nguyên
    Hash operator * (long long k) const {
        return Hash((x * k) % MOD1, (y * k) % MOD2);
    }

    // Overload các phép toán gán kết hợp
    Hash& operator += (const Hash& other) {
        x = (x + other.x) % MOD1;
        y = (y + other.y) % MOD2;
        return *this;
    }

    Hash& operator -= (const Hash& other) {
        x = (x - other.x + MOD1) % MOD1;
        y = (y - other.y + MOD2) % MOD2;
        return *this;
    }

    Hash& operator *= (const Hash& other) {
        x = (x * other.x) % MOD1;
        y = (y * other.y) % MOD2;
        return *this;
    }

    // So sánh hai Hash
    bool operator == (const Hash& other) const {
        return (x == other.x) && (y == other.y);
    }

    bool operator < (const Hash& other) const {
        if(x != other.x) return x < other.x;
        return y < other.y;
    }
};

// Overload operator << để dễ dàng in Hash (chỉ dùng cho debug)
ostream& operator << (ostream& out, const Hash& h) {
    out << '(' << h.x << ", " << h.y << ')';
    return out;
}

// Định nghĩa hàm băm cho std::unordered_map
namespace std {
    template<>
    struct hash<Hash> {
        size_t operator() (const Hash& h) const {
            return hash<long long>()(h.x) * 1000000007 + hash<long long>()(h.y);
        }
    };
}

// Lớp HashGenerator để tính toán và quản lý các giá trị hash
struct HashGenerator {
    // Lưu trữ các giá trị base^i mod MOD1 và MOD2
    vector<long long> power1;
    vector<long long> power2;
    int base;

    // Constructor
    HashGenerator(int maxLen, int _base = BASE) : base(_base) {
        power1.resize(maxLen + 1);
        power2.resize(maxLen + 1);
        power1[0] = 1;
        power2[0] = 1;
        for(int i = 1; i <= maxLen; i++) {
            power1[i] = (power1[i-1] * base) % MOD1;
            power2[i] = (power2[i-1] * base) % MOD2;
        }
    }

    // Tính hash prefix cho một chuỗi
    template<typename Container>
    vector<Hash> computeHash(const Container& s) const {
        int n = s.size();
        vector<Hash> prefixHash(n, Hash(0, 0));
        if(n == 0) return prefixHash;
        prefixHash[0] = Hash(s[0], s[0]);
        for(int i = 1; i < n; i++) {
            prefixHash[i].x = (prefixHash[i-1].x * base + s[i]) % MOD1;
            prefixHash[i].y = (prefixHash[i-1].y * base + s[i]) % MOD2;
        }
        return prefixHash;
    }

    // Lấy hash của chuỗi con [l, r]
    Hash getHash(const vector<Hash>& prefixHash, int l, int r) const {
        if(l > r) return Hash(0, 0);
        if(l == 0) return prefixHash[r];
        long long hash1 = (prefixHash[r].x - (prefixHash[l-1].x * power1[r-l+1]) % MOD1 + MOD1) % MOD1;
        long long hash2 = (prefixHash[r].y - (prefixHash[l-1].y * power2[r-l+1]) % MOD2 + MOD2) % MOD2;
        return Hash(hash1, hash2);
    }

    // So s1[l1, r1] và s2[l2, r2] có bằng nhau hay không
    bool equals(
        const vector<Hash>& h1, int l1, int r1,
        const vector<Hash>& h2, int l2, int r2
    ) const {
        if((r1 - l1) != (r2 - l2)) return false;
        Hash hash1 = getHash(h1, l1, r1);
        Hash hash2 = getHash(h2, l2, r2);
        return hash1 == hash2;
    }

    // Trả về độ dài của tiền tố chung lớn nhất giữa s1[l1, r1] và s2[l2, r2]
    int maxCommonPrefix(
        const vector<Hash>& h1, int l1, int r1,
        const vector<Hash>& h2, int l2, int r2
    ) const {
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        int low = 0;
        int high = min(len1, len2);
        int res = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(mid == 0) {
                res = 0;
                low = mid + 1;
                continue;
            }
            Hash subHash1 = getHash(h1, l1, l1 + mid - 1);
            Hash subHash2 = getHash(h2, l2, l2 + mid - 1);
            if(subHash1 == subHash2) {
                res = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return res;
    }

    // So s1[l1, r1] và s2[l2, r2]
    template<typename Container1, typename Container2>
    int cmp(
        const Container1& s1, const vector<Hash>& h1, int l1, int r1,
        const Container2& s2, const vector<Hash>& h2, int l2, int r2
    ) const {
        int common = maxCommonPrefix(h1, l1, r1, h2, l2, r2);
        char c1 = (l1 + common <= r1) ? s1[l1 + common] : '\0';
        char c2 = (l2 + common <= r2) ? s2[l2 + common] : '\0';
        if(c1 == c2) return 0;
        return (c1 < c2) ? -1 : 1;
    }
};

