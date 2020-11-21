#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define INF 1e9

const int MAXN = 17;
int n;
int d[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

int rec(int S, int v) { // 状態S, 現在の頂点vから残り全部通って頂点0に戻るための最小コスト
  if(dp[S][v]>=0)   return dp[S][v];
  if(S == (1 << n) - 1 && v == 0)    return dp[S][v] = 0;
  int tmp = INF;
  rep(u, n){
      if(((S>>u)&1)==0){
          tmp = min(tmp, rec(S|(1<<u), u) + d[v][u]);
      }
  }
  return dp[S][v] = tmp;
}

int main() {
  cin >> n;
  vector<int> x, y, z;
  rep(i, n){
      int a, b, c;
      cin >> a >> b >> c;
      x.push_back(a);
      y.push_back(b);
      z.push_back(c);
  }
  REP(i, n) REP(j, n) d[i][j] = d[j][i] = INF;


  rep(i, n){
      rep(j, n){
          if(i==j){
              continue;
          }else{
              d[i][j] = abs(x[j]-x[i]) + abs(y[j]-y[i]) + max(0, z[j]-z[i]);
          }
      }
  }
  fill((int *)dp, (int *)(dp + (1 << MAXN)), -1);
  cout << rec(0, 0) << endl;
  return 0;
}