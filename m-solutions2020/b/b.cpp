#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
  int a, b, c;
  int k;
  cin >> a >> b >> c;
  cin >> k;
  string ans = "No";
  rep(i, k + 1) {
    if (a < b) {
      if (b < c) {
        ans = "Yes";
        break;
      } else {
        c *= 2;
      }
    } else {
      b *= 2;
    }
  }
  cout << ans << endl;
  return 0;
}
