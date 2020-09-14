#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
  int n, kind = 0, allman=0;
  bool all=false;
  cin >> n;
  vector<int> c(8, 0);
  rep(i, n) {
    int x;
    cin >> x;
    if (x >= 3200) {
      allman++;
      all = true;
    } else {
      c[x / 400]++;
    }
  }
  rep(i, 8) {
    if (c[i]) {
      kind++;
    }
  }
  if(all){
      cout << max(kind, 1) << " " << kind+allman << endl;
  }else{
      cout << kind << " " << kind << endl;
  }
  return 0;
}