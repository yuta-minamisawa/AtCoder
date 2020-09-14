#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n, -1) {}
  // assign: 総とっかえ
  void init(int n) { par.assign(n, -1); }

  int root(int x) {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;

    // xにyをmerge
    if (par[x] > par[y]) swap(x, y);  // merge technique
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) { return -par[root(x)]; }
};

int main(){
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        uf.merge(a, b);
    }
    int res=0;
    rep(i, n){
        res = max(res, uf.size(i));
    }
    cout << res << endl;
    return 0;
}