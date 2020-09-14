#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

// #define MOD 1000000007

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

// long factorial(long n);
// void rfactorial(ll n);

// vector<ll> fact(110), rfact(110);

int main() {
  string n;
  int k;
  cin >> n;
  cin >> k;
  ll ans = 0;
  int len = n.size();
  rep2(dig, 1, len){
        ll c=1;
        if(dig<k){
            continue;
        }
        rep2(j, 1, k) {
          c *= dig-j;
          c /= j;
        }
        // c *= 9;
        if(c==0||c==1){
            c = 1;
        }else{
            c *= 9;
        }
        ans += 9 * c;
  }
  ll other = n[0] - '1';
  ll c=1;
  if (len >= k) {
    rep2(j, 1, k) {
      c *= len - j;
      c /= j;
    }
  }
  ans += other * 9 * c;
  vector<ll> num(len+1);
  rep(i, len){
      num[i+1] = n[i] - '0';
  }
  ll sum=0;
  if(k==1){
      sum = num[1];
  }
  if(k==2){
      rep2(i, 2, len+1){
          sum += num[i];
      }
  }
  if(k==3){
      rep2(i, 2, len){
          sum += num[i] * (len - i - 1);
          rep2(j, i+1, len+1){
              sum += num[j];
          }
      }
  }

//   for(int dig=len-1;dig>=0;)
  cout << ans << endl;
  cout << ans + sum << endl;
  return 0;
}

// long factorial(long n) {
//   if (n == 0) {
//     return 1;
//   } else {
//     if (fact[n - 1] == -1) {
//       fact[n - 1] = factorial(n - 1);
//     }
//     fact[n] = n * fact[n - 1];
//     return fact[n];
//   }
// }

// void rfactorial(ll n) {
//   ll m = MOD;
//   rfact[n] = binary_square(fact[n], m - 2);
//   rep2(i, 1, n + 1) { rfact[n - i] = rfact[n - i + 1] * (n - i + 1) % m; }
// }

// int binary_square(int x, int n) {
//   int m = MOD;
//   int ans = 1;
//   while (n) {
//     if (n & 1) {
//       ans = ans * x % m;
//     }
//     x = x * x % m;
//     n >>= 1;
//   }
//   return ans % m;
// }