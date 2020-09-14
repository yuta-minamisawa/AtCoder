#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll num = n / (a + b);
  if (n - num * (a + b) <= a) {
    cout << num * a + (n - num * (a + b)) << endl;
  } else {
    cout << num * a + a << endl;
  }
  return 0;
}