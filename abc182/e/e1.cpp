#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

bool isok(int wl, int l, int r, int wr, int wu, int u, int d, int wd);

int main() {
  int h, w, n, m;
  cin >> h >> w >> n >> m;

  vector<vector<int>> lighth(h), lightw(w), board(h, vector<int>(w, 0));
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    lighth[a].push_back(b);
    lightw[b].push_back(a);
    board[a][b] = 1;
  }
  rep(i, h) { sort(lighth[i].begin(), lighth[i].end()); }
  rep(i, w) { sort(lightw[i].begin(), lightw[i].end()); }

  vector<vector<int>> wallh(h), wallw(w);
  rep(i, m) {
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    wallh[c].push_back(d);
    wallw[d].push_back(c);
    board[c][d] = -1;
  }
  rep(i, h) {
    wallh[i].push_back(-1);
    wallh[i].push_back(w);
    sort(wallh[i].begin(), wallh[i].end());
  }
  rep(i, w) {
    wallw[i].push_back(-1);
    wallw[i].push_back(h);
    sort(wallw[i].begin(), wallw[i].end());
  }
  ll res = h * w - m;

  rep(i, h) {
    rep(j, w) {
      if (board[i][j] == 0) {
        int right = w + 1, left = -2;
        auto it = upper_bound(lighth[i].begin(), lighth[i].end(), j);
        if (it != lighth[i].end()) {
          right = *it;
        }
        if (it != lighth[i].begin()) {
          left = *(it - 1);
        }

        int up = -2, down = h + 1;
        it = upper_bound(lightw[j].begin(), lightw[j].end(), i);
        if (it != lightw[j].end()) {
          down = *it;
        }
        if (it != lightw[j].begin()) {
          up = *(it - 1);
        }

        int wallr, walll;
        it = upper_bound(wallh[i].begin(), wallh[i].end(), j);
        wallr = *it;
        walll = *(it - 1);

        int wallu = -2, walld = h + 1;
        it = upper_bound(wallw[j].begin(), wallw[j].end(), i);
        walld = *it;
        wallu = *(it - 1);

        if (!isok(walll, left, right, wallr, wallu, up, down, walld)) {
          res--;
        }
      }
    }
  }

  cout << res << endl;
  return 0;
}

bool isok(int wl, int l, int r, int wr, int wu, int u, int d, int wd) {
  return (wl < l) || (r < wr) || (wu < u) || (d < wd);
}