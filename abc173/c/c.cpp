#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1000000007

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int binary_square(int x, int n);

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> c;
  vector<vector<int>> col(h);
  vector<int> row(w, 0), tmp(w, 0);
  rep(i, h) {
    string s;
    cin >> s;
    c.push_back(s);
  }
  rep(i, h) {
    rep(j, w) {
      if (c[i][j] == '#') {
        col[i].push_back(j);
        row[j]++;
        tmp[j]++;
      }
    }
  }
  int cnt=0;
  // int check = binary_square(2, h+w);
  int check = 1<<(h+w);
  rep(x, check){
      int xnum = x;
      rep(i, h){
          if((xnum>>i)&1){
              int len = col[i].size();
              rep(j, len){
                  tmp[col[i][j]]--;
              }
          }
          // xnum >>= 1;
      }
      int sum = 0;
      rep(i, w){
          if((xnum>>(h+i))&1){
              sum += tmp[i];
          }
          tmp[i] = row[i];
          // xnum >>= 1;
      }
      if(sum==k){
          cnt++;
      }
  }
  cout << cnt << endl;
  return 0;
}

int binary_square(int x, int n) {
  int m = MOD;
  int ans = 1;
  while (n) {
    if(n&1) {
      ans = ans * x % m;
    }
    x = x * x % m;
    n >>= 1;
  }
  return ans % m;
}