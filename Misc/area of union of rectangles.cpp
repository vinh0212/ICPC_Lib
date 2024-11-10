//Tested: 
// - https://codeforces.com/contest/610/problem/D
// - https://oj.vnoi.info/problem/icpc23_mb_b
// From CTP.LTT
#include <bits/stdc++.h>
using namespace std;
#define maxn 400005
#define maxm 1000005

int a[maxn], sum[maxn*4], cnt[maxn*4];

void update(int l, int r, int low, int high, int id, int gt) {//range: [a[l], a[r])
    if (high <= a[l] || a[r] <= low) return;
    if (low <= a[l] && a[r] <= high) {
        cnt[id] += gt;
        if (cnt[id]) sum[id] = a[r]-a[l];
        else sum[id] = sum[2*id] + sum[2*id+1];
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, low, high, 2*id, gt);
    update(mid, r, low, high, 2*id+1, gt);
    if (!cnt[id]) sum[id] = sum[2*id] + sum[2*id+1];
}

int main() {
    fastio;
    int n; cin >> n;
    vector<int> tmp;
    vector< pair<ii, ii> > sweepline; //sweepline: (x, type), (y1, y2)
    fto (i, 1, n) {
        int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        ++y2; ++x2;
        sweepline.pb(mp(mp(x1, 1), mp(y1, y2)));
        sweepline.pb(mp(mp(x2, -1), mp(y1, y2)));
        tmp.pb(y1); tmp.pb(y2);
    }
    int r = 0;
    sort(tmp.begin(), tmp.end());
    sort(sweepline.begin(), sweepline.end(), [&](pair<ii, ii> left, pair<ii, ii> right) {
        return left.ff.ff < right.ff.ff;
    });
    fto (i, 0, (int)tmp.size()-1) {
        a[++r] = tmp[i];
        while (i+1 < tmp.size() && tmp[i] == tmp[i+1]) ++i;
    }
    long long ans = 0;
    int pre = sweepline[0].ff.ff;
    fto (i, 0, (int)sweepline.size()-1) {
        ans = ans + (long long)(sweepline[i].ff.ff-pre)*sum[1];
        pre = sweepline[i].ff.ff;
        update(1, r, sweepline[i].ss.ff, sweepline[i].ss.ss, 1, sweepline[i].ff.ss);
        while (i+1 < sweepline.size() && sweepline[i+1].ff.ff == sweepline[i].ff.ff) {
            ++i;
            update(1, r, sweepline[i].ss.ff, sweepline[i].ss.ss, 1, sweepline[i].ff.ss);
        }
    }
    cout << ans << endl;
    return 0;
}