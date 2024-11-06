#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;

ll n, res[500005] = {0}, dem1 = 0, sum[500005];
string s;
vector<ll> v;

ll tinh(ll l, ll r){
    if(l == 0) return sum[r];
    return sum[r] - sum[l-1];
}

ll f(ll t){
    if(res[t] != 0) return res[t];
    ll cnt = 0, tmp = 0, m = INT_MAX;
    for(ll i = 0; i < v.size(); i++){
        if(tinh(i, v.size()-1) < t) break;
        ll l = 0, r = v.size()-1, ans;
        while(l <= r){
            ll mid = (l+r) >> 1;
            ll tmp = tinh(i, mid);
            if(tmp >= t){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        m = min(m, tinh(i, ans));
        cnt++;
        i = ans;
    }
    if(cnt == 0 || cnt == 1){
        return 0;
    }
    for(ll i = t; i <= m; i++){
        res[i] = i * cnt + cnt - 1;
    }
    return res[t];
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    ll tmp = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == '1') {
            dem1++;
            if(tmp) v.push_back(tmp);
            tmp = 0;
        }
        else tmp++;
    }
    if(tmp) v.push_back(tmp);
    if(v.empty()){
        cout << dem1;
        return 0;
    }
    sum[0] = v[0];
    for(ll i = 1; i < v.size(); i++) sum[i] = sum[i-1] + v[i];
    ll ans = dem1;
    for(ll t = 1; t <= 500000; t++){
        ll tmp = f(t);
        if(tmp == 0) break;
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}
