#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
  ll infty = 1e12;
  int n, W, vsum=0;
  cin >> n >> W;
  vector<ll> w, v;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    w.push_back(x);
    v.push_back(y);
    vsum += y;
  }
  vector<ll>tmp(vsum + 1, infty);
  vector<vector<ll>> dp(n + 1, tmp);

  dp[0][0] = 0;
  rep2(i, 1, n+1){
      dp[i][0] = 0;
      rep2(j, 1, vsum+1){
        if (j - v[i - 1] >= 0) {
          dp[i][j] = min(dp[i - 1][j - v[i - 1]] + w[i - 1], dp[i - 1][j]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
  }

  auto it = upper_bound(dp[n].begin(), dp[n].end(), W);
  cout << it - dp[n].begin() - 1 << endl;
  return 0;
}