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
  string res = "No";
  int seq = 0;
  rep(i, n) {
    int d[2];
    cin >> d[0] >> d[1];
    if (d[0] == d[1]) {
      seq++;
      if (seq >= 3) {
        res = "Yes";
      }
    } else {
      seq = 0;
    }
  }
  cout << res << endl;
  return 0;
}