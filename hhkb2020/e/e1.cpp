#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

template <int mod = (int)(1e9 + 7)>
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

const int MOD = 1e9 + 7;

using mint = ModInt<MOD>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s;
  rep(i, h) {
    string x;
    cin >> x;
    s.push_back(x);
  }

  vector<vector<int>> hbox(h), wbox(w);
  rep(i, h) {
    hbox[i].push_back(-1);
    hbox[i].push_back(w);
  }
  rep(i, w) {
    wbox[i].push_back(-1);
    wbox[i].push_back(h);
  }

  int messcnt = 0;

  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '#') {
        messcnt++;
        hbox[i].push_back(j);
        wbox[j].push_back(i);
      }
    }
  }

  rep(i, h) { sort(hbox[i].begin(), hbox[i].end()); }

  rep(i, w) { sort(wbox[i].begin(), wbox[i].end()); }

  vector<mint> two(h * w - messcnt + 1);
  two[0] = 1;
  rep2(i, 1, h * w - messcnt + 1) { two[i] = two[i - 1] * 2; }

  mint res = 0;

  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '.') {
        auto it = upper_bound(hbox[i].begin(), hbox[i].end(), j);
        int hnum = (*(it) - *(--it)) - 1;
        it = upper_bound(wbox[j].begin(), wbox[j].end(), i);
        int wnum = (*(it) - *(--it)) - 1;
        int x = hnum + wnum - 1;
        res += two[h * w - messcnt] - two[h * w - messcnt - x];
      }
    }
  }

  cout << res << endl;
  return 0;
}