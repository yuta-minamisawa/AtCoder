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
  string d;
  cin >> d;

  vector<P> lr;

  rep(i, h){
      rep(j, w){
          if(s[i][j]=='#'){
              lr.push_back(make_pair(i, j));
          }
      }
  }

  int lrlen = lr.size(), res=0;
  if (d[0] == 'N') {
    if (d.size() == 1) {
      rep(i, lrlen) { res = max(res, h - lr[i].first); }
    } else {
      if (d[1] == 'E') {
        rep(i, lrlen) {
          res = max(res, min(h - lr[i].first, lr[i].second + 1));
        }
      }
      if (d[1] == 'W') {
        rep(i, lrlen) {
          res = max(res, min(h - lr[i].first, w - lr[i].second));
        }
      }
    }
  }
  if(d[0]=='S'){
    if (d.size() == 1) {
      rep(i, lrlen) { res = max(res, lr[i].first + 1); }
    } else {
      if (d[1] == 'E') {
        rep(i, lrlen) {
          res = max(res, min(lr[i].first + 1, lr[i].second + 1));
        }
      }
      if (d[1] == 'W') {
        rep(i, lrlen) {
          res = max(res, min(lr[i].first + 1, w - lr[i].second));
        }
      }
    }
  }
  if(d[0]=='E'){
    rep(i, lrlen){
      res = max(res, lr[i].second+1);
    }
  }
  if(d[0]=='W'){
    rep(i, lrlen) { 
      res = max(res, w - lr[i].second); 
    }
  }

  cout << res << endl;
  return 0;
}
