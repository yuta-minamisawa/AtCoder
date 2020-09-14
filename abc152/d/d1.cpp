#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1000000007

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

ll binary_square(ll x, ll n);

int main() {
  int n;
  cin >> n;
  int num = n;
  int d = 0;
  int maxbit, minbit=n%10;
  while (num != 0) {
    maxbit = num;
    num /= 10;
    d++;
  }
  ll cnt = 0LL;
  if (d == 1) {
    cnt = n;
  } else {
    cnt += 9LL;
    rep2(i, 2, d) { 
        cnt += 9 * binary_square(10LL, i-2) * 2; //1 vs 2~d-1
        rep2(j, 2, d) {
          cnt += 81 * binary_square(10LL, i - 2) * binary_square(10LL, j - 2); //2~d-1 vs 2~d-1
        }
    }
    cnt += (maxbit-1) * binary_square(10LL, d - 3) * 2; // 1 vs d(脳死)
    ll mid = (n - maxbit * binary_square(10LL, d - 1)) / 10LL + 1LL;
    cnt += mid;
    if(minbit<maxbit){
        cnt--;
    }
    rep2(i, 2, d){
        cnt += (n - binary_square(10LL, d-1) + 1) * binary_square(10LL, i-2) * 2; // 2~d-1 vs d
    }
    int x = min(maxbit, minbit);
    cnt += x * x * binary_square(10LL, d - 2) * binary_square(10LL, d - 2); // d vs d
  }
  cout << cnt << endl;
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