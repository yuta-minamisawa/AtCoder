#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1000000007

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

ll head_tail_num[10][10] = {};

int main() {
  int n;
  cin >> n;
  int num = n;
  int d = 0;
  int maxbit;
  while (num != 0) {
    maxbit = num;
    num /= 10;
    d++;
  }
  ll cnt = 0LL;
  int ten=1, tmpmax, tmpmin;
  rep2(i, 1, d+1){
      int lim = min(ten*10, n+1);
      rep2(j, ten, lim){
          tmpmax = j / ten;
          tmpmin = j % 10;
          head_tail_num[tmpmax][tmpmin]++;
      }
      ten*=10;
  }
  rep2(i, 1, 10){
    rep2(j, 1, 10) { 
      cnt += head_tail_num[i][j] * head_tail_num[j][i]; 
    }
  }
  cout << cnt << endl;
}