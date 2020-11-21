#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    ll n, x;
    cin >> n >> x;
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    vector<ll> a(n), num(n);
    a.assign(n, 0);
    for(auto &p : a) cin >> p;
    ll now = x;
    for(ll i=n-1;i>=0;i--){
        num[i] = now/a[i];
        now -= a[i] * num[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][0] = 1;
    if(num[0]){
        dp[0][1] = 1;
    }

    rep2(i, 1, n-1){
        dp[i][0] = dp[i-1][0];
        if(num[i] != a[i+1]/a[i]-1){
            dp[i][0] += dp[i-1][1];
        }

        dp[i][1] += dp[i-1][1];
        if(num[i]){
            dp[i][1] += dp[i-1][0];
        }
    }

    cout << dp[n-2][0] + dp[n-2][1] << endl;
    return 0; 
}