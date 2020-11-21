#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using Pll = pair<ll, ll>;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n) {
    int a;
    cin >> a;
    mp[a - 1]++;
    mp[a]++;
    mp[a + 1]++;
  }

  int res = 0;
  for (const auto& [key, value] : mp) {
    res = max(res, value);
  }
  cout << res << endl;
  return 0;
}
