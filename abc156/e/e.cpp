#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD (long long)1e9+7

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

void factorial(ll n);
void rfactorial(ll n);
ll binary_square(ll x, ll n);

vector<ll> fact(1e6, -1), rfact(1e6, -1);

int main() {
  ll n, k, m = MOD;
  cin >> n >> k;
  factorial(2 * n);
  rfactorial(n + 1);
  ll ans = (fact[2 * n - 1] * rfact[n - 1] % m) * rfact[n] % m;
  if (k < n - 1) {
    ll x = fact[n];
    ans = 0;
    rep(i, k+1){
        ll zero = (((x * rfact[i]) % m) * rfact[n-i]) % m;
        ll rem = (((fact[n-1] * rfact[i]) % m) * rfact[n - 1 - i]) % m;
        ans = (ans + (zero * rem % m)) % m;
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
    rfact[n] = binary_square(fact[n], MOD-2);
    rep2(i, 1, n+1){
        rfact[n - i] = rfact[n - i + 1] * (n - i + 1) % m;
    }
}

ll binary_square(ll x, ll n) {
  ll m = MOD;
  ll ans = 1;
  while (n) {
    if (n % 2 == 1) {
      ans = ans * x % m;
    }
    x = x * x % m;
    n >>= 1;
  }
  return ans % m;
}