#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a;
  rep(i, n) {
    int A;
    cin >> A;
    a.push_back(A);
  }

  rep(i, k) {
    vector<int> b(n, 0);
    rep(j, n){
      int l = max(j - a[j], 0);
      int r = min(j + a[j], n - 1);
      // cout << l << " " << r << endl;
      b[l]++;
      if (r + 1 < n) {
        b[r + 1]--;
      }
    }
    bool n_flag = true;
    a[0] = b[0];
    if(a[0]!=n){
      n_flag = false;
    }
    rep2(j, 1, n) {
      //b[j + 1] += b[j];
      a[j] = a[j-1] + b[j];
      if(n_flag&&a[j]!=n){
        n_flag = false;
      }
    }

    if(n_flag){
      break;
    }
  }

  rep(i, n){
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}