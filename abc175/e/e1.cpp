#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int R, C, k;
    cin >> R >> C >> k;
    vector<ll> tmp(C+1, 0);
    vector<vector<ll>> v(R+1, tmp), tmp2(R+1, tmp), ans(R+1, tmp);
    vector<vector<vector<ll>>> dp(4, tmp2);
    rep(i, k){
        ll x, y, z;
        cin >> x >> y >> z;
        v[x][y] = z;
    }

    rep2(i, 1, R+1){
        rep2(j, 1, C+1){
            dp[0][i][j] = max(dp[0][i][j-1], ans[i-1][j]);
            if (v[i][j]) {
                rep2(k, 1, 4) {
                  dp[k][i][j] = max(dp[k][i][j - 1], max(dp[k-1][i][j - 1], ans[i - 1][j]) + v[i][j]);
                }
            }else{
                rep2(k, 1, 4) { dp[k][i][j] = max(dp[k][i][j - 1], ans[i - 1][j]); }
            }
            rep(k, 4) { ans[i][j] = max(ans[i][j], dp[k][i][j]); }
        }
    }

    cout << ans[R][C] << endl;
    return 0;
}