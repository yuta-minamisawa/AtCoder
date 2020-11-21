#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using Pll = pair<ll, ll>;

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

using mint2 = ModInt<MOD>;
using mint1 = ModInt<13>;

int main() { 
    string s;
    cin >> s;
    int slen = s.size();

    int t = 1;
    vector<int> ten;
    rep(i, slen){
        ten.push_back(t);
        t *= 10;
        t %= 13;
    }

    vector<vector<mint2>> dp(slen, vector<mint2>(13, 0));
    if(s[slen-1]=='?'){
        rep(i, 10){
            dp[0][i] = 1;
        }
    }else{
        int x = s[slen-1] - '0';
        dp[0][x] = 1;
    }

    rep2(i, 1, slen){
        if(s[slen-i-1]=='?'){
            rep(j, 13){
              rep(x, 10) { dp[i][(j + x * ten[i])%13] += dp[i-1][j]; }
            }
        }else{
            int x = s[slen-i-1] - '0';
            rep(j, 13){
                dp[i][(j+x*ten[i])%13] += dp[i-1][j];
            }
        }
    }

    cout << dp[slen-1][5] << endl;
    return 0; 
}