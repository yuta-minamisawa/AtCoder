#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, W;
    cin >> n >> W;
    vector<ll> w, v, tmp(W+1, 0);
    vector<vector<ll>> dp(n+1, tmp);
    rep(i, n){
        ll x, y;
        cin >> x >> y;
        w.push_back(x);
        v.push_back(y);
    }

    rep2(i, 1, n+1){
        rep2(j, 1, W+1){
            if(j-w[i-1]>=0){
                dp[i][j] = max(dp[i - 1][j - w[i-1]] + v[i-1], dp[i - 1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][W] << endl;
    return 0;
}