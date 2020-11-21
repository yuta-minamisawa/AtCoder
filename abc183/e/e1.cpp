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
    vector<string> S;
    vector<vector<mint>> dp(h, vector<mint>(w, 0));
    rep(i, h){
        string s;
        cin >> s;
        S.push_back(s);
        rep(j, w){
            if(s[j]=='.'){
                dp[i][j] = 0;
            }else{
                dp[i][j] = -1;
            }
        }
    }

    vector<mint> rowsum(w, 0), naname(w-1, 0);
    dp[0][0] = 1;

    rep(i, h){
        mint colsum=0;
        rep(j, w){
            if(S[i][j]!='#'){   // road
                // cout << colsum << " " << rowsum[j] << endl; 
                dp[i][j] += colsum + rowsum[j];
                if(j!=0){
                    dp[i][j] += naname[j-1];
                }
                colsum += dp[i][j];
                rowsum[j] += dp[i][j];
                // if(j!=w-1){
                //     naname[j] += dp[i][j];
                // }
            }else{  // wall
                colsum = 0;
                rowsum[j] = 0;
                // naname[j] = 0;
            }
        }

        for (int j = w - 2; j > 0; j--) {
          naname[j] = naname[j - 1];
        }
        naname[0] = 0;
        rep(j, w-1){
            if(S[i][j]=='#'){
                naname[j] = 0;
            }else{
                naname[j] += dp[i][j];
            }
        }
    }

    // rep(i, h){
    //     rep(j, w){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[h-1][w-1] << endl;
    return 0; 
}