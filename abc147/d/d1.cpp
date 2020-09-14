#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1e9+7

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

ll m = MOD;

int main(){
    int n;
    cin >> n;
    vector<ll> a, sum;
    rep(i, n){
        ll x;
        cin >> x;
        a.push_back(x);
    }
    ll tmp = 0;
    rep(i, n){
        tmp = (tmp + a[n-1-i]) % m;
        sum.push_back(tmp);
    }
    ll ans=0;
    rep(i, n-1){
        // cout << sum[n-2-i] << endl;
        tmp = a[i] ^ sum[n-2-i];
        cout << tmp << endl;
        ans = (ans + tmp) % m;
    }
    cout << ans << endl;
    return 0;
}