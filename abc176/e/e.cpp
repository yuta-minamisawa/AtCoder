#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int n;
vector<int> a;

void update(int i, int x);
int query(int x, int y, int k, int l, int r);

int main(){
    int h, w, m, colmax=0;
    cin >> h >> w >> m;
    n = w;
    rep(i, 30) {
      if ((n - 1) < 1 << i) {
        n = 1 << i;
        break;
      }
    }

    rep(i, 2 * n - 1) { a.push_back(0); }

    vector<int> col(h, 0), row(w, 0);
    vector<int> tmph;
    vector<vector<int>> collist(h, tmph);
    rep(i, m){
        int x, y;
        cin >> x >> y;
        col[x-1]++;
        row[y-1]++;
        colmax = max(colmax, col[x-1]);
        collist[x-1].push_back(y-1);
    }
    vector<int> cind;
    vector<vector<int>> cmax;
    rep(i, h){
        if(col[i]==colmax){
            cind.push_back(i);
            cmax.push_back(collist[i]);    
        }
    }
    rep(i, w){
        update(i, row[i]);
    }
    int clen=cmax.size(), res=0;
    rep(i, clen){
        int clislen = cmax[i].size();
        rep(j, clislen){
            update(cmax[i][j], row[cmax[i][j]]-1);
        }
        res = max(res, query(0, n, 0, 0, n));
        rep(j, clislen) { 
            update(cmax[i][j], row[cmax[i][j]]); 
        }
    }
    cout << colmax + res << endl;
    return 0;
}

void update(int i, int x) {
  i += n - 1;
  a[i] = x;
  while (i > 0) {
    i = (i - 1) / 2;
    a[i] = max(a[i * 2 + 1], a[i * 2 + 2]);
  }
}

int query(int x, int y, int k, int l, int r) {
  if (r <= x || y <= l) return 0;
  if (x <= l && r <= y)
    return a[k];
  else {
    int vl = query(x, y, k * 2 + 1, l, (l + r) / 2);
    int vr = query(x, y, k * 2 + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
}