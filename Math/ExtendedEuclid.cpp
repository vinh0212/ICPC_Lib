// Dùng Extended Euclid để tìm nghiệm của phương trình ax + by = gcd(a, b).
// Giả sử kết quả trả về là (x0, y0), họ nghiệm của phương trình sẽ là (x_0+kb/d,y_0-ka/d) với k∈Z.
// Phương trình tổng quát ax + by = d chỉ có nghiệm khi d chia hết cho gcd(a, b).
// a x + b y = gcd(a, b)
template<typename T>
T extgcd(T a, T b, T &x, T &y) {
    T g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}
//Example Code
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "../../template.h"
#include "../NumberTheory/ExtendedEuclid.h"

using ll = long long;
void solve() {
    ll a, b; cin >> a >> b;
    ll x, y;
    extgcd(a, b, x, y);
    cout << x << ' ' << y << endl;
}