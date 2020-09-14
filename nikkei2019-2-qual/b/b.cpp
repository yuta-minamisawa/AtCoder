#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 998244353

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

ll binary_square(ll x, ll n);

int main() {
  ll n, maxim = 0, res = 1, m = MOD;
  cin >> n;
  vector<ll> d(n, 0);
  rep(i, n) {
    ll x;
    cin >> x;
    if ((i == 0 && x != 0) || (i != 0 && x == 0)) {
      cout << 0 << endl;
      return 0;
    }
    maxim = max(maxim, x);
    d[x]++;
  }
    rep2(i, 1, maxim + 1) { 
        res = (res * binary_square(d[i-1], d[i])) % m;
    }
    cout << res << endl;
  return 0;
}

ll binary_square(ll x, ll n) {
  ll m = MOD;
  ll ans = 1;
  while (n) {
    if (n & 1) {
      ans = ans * x % m;
    }
    x = x * x % m;
    n >>= 1;
  }
  return ans % m;
}