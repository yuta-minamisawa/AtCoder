#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s;
  rep(i, h) {
    string x;
    cin >> x;
    s.push_back(x);
  }
  vector<int> tmp(1, -1);
  vector<vector<int>> col(h, tmp), row(w, tmp);
  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '#') {
        col[i].push_back(j);
        row[j].push_back(i);
      }
    }
    col[i].push_back(w);
  }
    rep(i, w) { 
      row[i].push_back(h);
      sort(row[i].begin(), row[i].end());
    }
  int maxim = 0;
  rep(i, h){
      rep(j, w){
          if(s[i][j]=='.'){
              int tmp = 0;
              auto it = upper_bound(col[i].begin(), col[i].end(), j);
              tmp = *it - *(--it) - 1;
              auto it2 = upper_bound(row[j].begin(), row[j].end(), i);
              tmp += *it2 - *(--it2) - 1;
              maxim = max(maxim, tmp-1);
          }
      }
  }
  cout << maxim << endl;
  return 0;
}