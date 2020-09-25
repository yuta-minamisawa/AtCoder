#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using Pll = pair<ll, ll>;

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

void update(int i, mint x);
mint query(int x, int y, int k, int l, int r);

ll n;
vector<mint> a;

int main(){
    int k;
    cin >> n >> k;
    ll pren = n;
    n++;

    rep(i, 30) {
        if ((n - 1) < 1 << i) {
            n = 1 << i;
            break;
        }
    }
    rep(i, 2 * n - 1) {
        a.push_back(0); 
    }
    update(1, 1);

    vector<Pll> lr;

    rep(i, k) {
        ll l, r;
        cin >> l >> r;
        lr.push_back(make_pair(l, r));
    }

    rep2(i, 2, pren+1){
        mint total=0;
        rep(j, k) {
            total += query(i-lr[j].second, i-lr[j].first+1, 0, 0, n);
        }
        update(i, total);
    }
    cout << a[pren + n - 1] << endl;
    return 0;
}

void update(int i, mint x) {
  i += n - 1;
  a[i] = x;
  while (i > 0) {
    i = (i - 1) / 2;
    a[i] = a[i * 2 + 1] + a[i * 2 + 2];
  }
}

mint query(int x, int y, int k, int l, int r) {
  if (r <= x || y <= l) return 0;
  if (x <= l && r <= y)
    return a[k];
  else {
    mint vl = query(x, y, k * 2 + 1, l, (l + r) / 2);
    mint vr = query(x, y, k * 2 + 2, (l + r) / 2, r);
    return vl+vr;
  }
}