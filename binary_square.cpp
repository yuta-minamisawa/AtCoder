#define MOD 1000000007

int binary_square(int x, int n) {
  int m = MOD;
  int ans = 1;
  while (n) {
    if (n & 1) {
      ans = ans * x % m;
    }
    x = x * x % m;
    n >>= 1;
  }
  return ans % m;
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