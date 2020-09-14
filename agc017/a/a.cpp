#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

template <typename T>
vector<vector<T>> binomial_table(int N) {
  vector<vector<T>> mat(N + 1, vector<T>(N + 1));
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        mat[i][j] = 1;
      else
        mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
    }
  }
  return mat;
}

int main(){
    int n, p;
    cin >> n >> p;
    int cnt=0;
    rep(i, n){
        int a;
        cin >> a;
        if(a%2){
            cnt++;
        }
    }
    vector<vector<ll>> memo = binomial_table<ll>(n);
    ll ans=0;
    int s;
    if(p){
        s = 1;
    }else{
        s = 0;
    }
    rep3(i, s, n+1, 2){
        ll tmp = memo[cnt][i];
        rep(j, n-cnt+1){
            ans += tmp * memo[n-cnt][j];
        }
    }
    cout << ans << endl;
    return 0;
}