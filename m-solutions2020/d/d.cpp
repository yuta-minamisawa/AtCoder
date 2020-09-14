#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a;
  rep(i, n) {
    ll x;
    cin >> x;
    a.push_back(x);
  }
  ll money = 1000, kabu = 0;
  rep(i, n - 1) {
    // buy phase
    if (kabu == 0) {
      if (a[i] < a[i + 1]) {
        kabu += money / a[i];
        money -= kabu * a[i];
      }
    } else {  // sell phase
      if (a[i] > a[i + 1]) {
        money += kabu * a[i];
        kabu = 0;
      }
    }
  }
  if (kabu != 0) {
    money += kabu * a[n - 1];
    kabu = 0;
  }
  cout << money << endl;
  return 0;
}
