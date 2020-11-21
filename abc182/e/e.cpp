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

    vector<vector<int>> col(h, vector<int>(w, 0)), row(h, vector<int>(w, 0));

    rep(i, n){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        col[a][b] = 1;
        row[a][b] = 1;
    }

    rep(i, m){
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        col[c][d] = -1;
        row[c][d] = -1;
    }

    rep(i, h){
        rep(j, w-1){
            if(col[i][j+1]!=-1){
                col[i][j+1] = max(col[i][j], col[i][j+1]);
            }
        }
    }

    rep(i, h) {
      for(int j=w-1;j>=1;j--) {
        if (col[i][j - 1] != -1) {
          col[i][j - 1] = max(col[i][j], col[i][j - 1]);
        }
      }
    }

    rep(i, w) {
      rep(j, h - 1) {
        if (row[j+1][i] != -1) {
          row[j + 1][i] = max(row[j][i], row[j+1][i]);
        }
      }
    }

    rep(i, w) {
      for(int j=h - 1;j>=1;j--) {
        if (row[j - 1][i] != -1) {
          row[j - 1][i] = max(row[j][i], row[j - 1][i]);
        }
      }
    }

    int res = 0;
    rep(i, h){
        rep(j, w){
            // cout << board[i][j] << " ";
            if(col[i][j]==1||row[i][j]==1){
                res++;
            }
        }
    }

    cout << res << endl;
    return 0; 
}
