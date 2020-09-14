#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<int> a, b, c, tmp(n, 0);
    vector<vector<int>> dp(3, tmp);
    rep(i, n){
        int x, y, z;
        cin >> x >> y >> z;
        a.push_back(x);
        b.push_back(y);
        c.push_back(z);
    }

    dp[0][0] = a[0];
    dp[1][0] = b[0];
    dp[2][0] = c[0];
    rep2(i, 1, n){
        dp[0][i] = max(dp[1][i-1] + a[i], dp[2][i-1] + a[i]);
        dp[1][i] = max(dp[0][i - 1] + b[i], dp[2][i - 1] + b[i]);
        dp[2][i] = max(dp[1][i - 1] + c[i], dp[0][i - 1] + c[i]);
    }

    int ans=dp[0][n-1];
    ans = max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1]));
    cout << ans << endl;
    return 0;
}