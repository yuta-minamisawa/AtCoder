#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

template <int mod = (int)(998244353)>
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

const int MOD = 998244353;

using mint = ModInt<MOD>;

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

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  rep(i, n) {
    rep(j, n) {
      int x;
      cin >> x;
      a[i][j] = x;
    }
  }

  vector<mint> fact(51, 0);
  mint f = 1;
  rep(i, 51) {
    if (i != 0) {
      f *= (mint)i;
    }
    fact[i] = f;
  }

  UnionFind row(n), col(n);

  rep(i, n - 1) {
    rep2(j, i + 1, n) {
      bool flag = true;
      rep(l, n) {
        if (a[i][l] + a[j][l] > k) {
          flag = false;
          break;
        }
      }
      if (flag) {
        row.merge(i, j);
      }
    }
  }

  rep(i, n - 1) {
    rep2(j, i + 1, n) {
      bool flag = true;
      rep(l, n) {
        if (a[l][i] + a[l][j] > k) {
          flag = false;
          break;
        }
      }
      if (flag) {
        col.merge(i, j);
      }
    }
  }

  mint res = 1;
  vector<bool> crow(n, true), ccol(n, true);
  rep(i, n) {
    if (crow[row.root(i)]) {
      res *= fact[row.size(i)];
      crow[row.root(i)] = false;
    }
    if (ccol[col.root(i)]) {
      res *= fact[col.size(i)];
      ccol[col.root(i)] = false;
    }
  }

  cout << res << endl;
  return 0;
}