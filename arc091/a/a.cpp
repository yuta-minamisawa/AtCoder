#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll n, m;
    cin >> n >> m;
    if(n==1 || m==1){
      if (n == 1 && m == 1) {
        cout << 1 << endl;
        return 0;
      } else {
        ll maxim = max(n, m);
        cout << maxim - 2 << endl;
        return 0;
      }
    }
    cout << (n-2) * (m-2) << endl;
    return 0;
}