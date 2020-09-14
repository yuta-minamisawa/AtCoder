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
  ll sum = 0, mincnt = 0, absmin = INT64_MAX;
  rep(i, n) {
    ll a;
    cin >> a;
    sum += abs(a);
    if (a < 0) {
      mincnt++;
    }
    absmin = min(absmin, abs(a));
  }
  if (mincnt % 2) {
    cout << sum - 2 * absmin << endl;
  } else {
    cout << sum << endl;
  }
  return 0;
}
