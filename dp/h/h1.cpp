#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1e9+7

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int h, w;
    ll m = MOD;
    cin >> h >> w;
    vector<ll> tmp(w+1, 0);
    vector<vector<ll>> dp(h+1, tmp);
    vector<string> a;
    rep(i, h){
        string s;
        cin >> s;
        a.push_back(s);
    }

    dp[0][1] = 1;
    rep2(i, 1, h+1){
        rep2(j, 1, w+1){
            if(a[i-1][j-1]=='.'){
              dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % m;
            }
        }
    }
    cout << dp[h][w] << endl;
    return 0;
}