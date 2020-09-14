#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1e9+7

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

ll factorial(ll n);
void rfactorial(ll n);
ll binary_square(ll x, ll n);

vector<ll> fact(2e5+1, -1), rfact;

int main() {
    ll n , a ,b;
    cin >> n>> a >> b;
    ll x = factorial(b+1);
    rfactorial(b+1);
    ll ans=lldiv(binary_square(2, n) - 1, MOD).rem;
    ll chi=1;
    rep2(i, 1, a+1){
        chi = lldiv(chi * (n - i + 1), MOD).rem;
    }
    ans = lldiv(ans - lldiv(chi * rfact[a], MOD).rem, MOD).rem;
    if(ans<0){
        ans += MOD;
    }
    rep2(i, a+1, b+1){
        chi = lldiv(chi * (n - i + 1), MOD).rem;
    }
    ans = lldiv(ans - lldiv(chi * rfact[b], MOD).rem, MOD).rem;
    if (ans < 0) {
      ans += MOD;
    }
    cout << ans << endl;
    return 0;
}

ll factorial(ll n) {
  if (n == 0) {
    return 1;
  } else {
    if (fact[n - 1] == -1) {
      fact[n - 1] = factorial(n - 1);
    }
    fact[n] = lldiv(n * fact[n - 1], MOD).rem;
    return fact[n];
  }
}

void rfactorial(ll n) {
  rep(i, n) { rfact.push_back(binary_square(fact[i], MOD - 2)); }
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