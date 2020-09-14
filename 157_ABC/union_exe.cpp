#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

struct UnionFind{
	vector<int> par;
	UnionFind(int n): par(n, -1){}
	void init(int n){
		par.assign(n, -1);
	}

	int root(int x){
		if(par[x]<0){
			return x;
		}else{
			return par[x] = root(par[x]);
		}
	}

	bool issame(int x, int y){
		return root(x)==root(y);
	}

	bool merge(int x, int y){
		x = root(x);
		y = root(y);
		if(x==y) return false;
		if(par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x){
		return -par[root(x)];
	}
};

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  UnionFind uf(n);
  vector<int> frnum(n, 0);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    uf.merge(a - 1, b - 1);
    frnum[a - 1]++;
    frnum[b - 1]++;
  }

  vector<int> tmp;
  vector<vector<int>> bl(n, tmp);
  rep(i, k) {
    int c, d;
    cin >> c >> d;
    bl[c - 1].push_back(d - 1);
    bl[d - 1].push_back(c - 1);
  }

  rep(i, n) {
    int ans = uf.size(i) - frnum[i] - 1;
    int blsize = bl[i].size();
    rep(j, blsize) {
      if (uf.issame(i, bl[i][j])) {
        ans--;
      }
    }
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}