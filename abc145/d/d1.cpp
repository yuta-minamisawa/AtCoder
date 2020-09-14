#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1e9+7LL

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

ll binary_square(ll x, ll n);
void factorial(ll n);
void rfactorial(ll n);
vector<ll> fact(2e6), rfact(2e6);

int main() {
  ll x, y, ans=0LL;
  ll m = MOD;
  cin >> x >> y;
  factorial(2e6);
  rfactorial(2e6);
  rep(two, x/2+1){
      ll one = x - 2LL * two;
      if(y==one*2LL + two){
            ll total = one + two;
            ans = (ans + (fact[total] * ((rfact[one] * rfact[two]) % m)) % m) % m;
      }
  }
  cout << ans << endl;
  return 0;
}

void factorial(ll n) {
    ll m = MOD;
    fact[0] = 1;
    rep2(i, 1, n+1){
        fact[i] = fact[i-1] * i % m;
    }
}

void rfactorial(ll n) {
  ll m = MOD;
  rfact[n] = binary_square(fact[n], m - 2LL);
  rep2(i, 1, n + 1) { rfact[n - i] = rfact[n - i + 1] * (n - i + 1) % m; }
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