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
    ll n;
    cin >> n;
    vector<ll> a;
    rep(i, n){
        ll x;
        cin >> x;
        a.push_back(x);
    }
    ll ans=0;
    rep(i, 61){
        ll cnt=0;
        rep(j, n){
            if((a[j]>>i)&1){
                cnt++;
            }
        }
        // cout << cnt << endl;
        ans = (ans + ((((((1LL << i) % m) * cnt) % m) * (n - cnt)) % m)) % m;
    }
    cout << ans << endl;
    return 0;
}