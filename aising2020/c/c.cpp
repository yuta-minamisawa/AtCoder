#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<int> f(n+1, 0);
    for(int x=1;x*x<=n;x++){
      for (int y = 1; y * y <= n; y++){
          for(int z = 1; z*z<=n;z++){
              int res = x*x + y*y + z*z + x*y + y*z + z*x;
              if(res<=n){
                  f[res]++;
              }
          }
      }
    }
    rep2(i, 1, n+1){
        cout << f[i] << endl;
    }
    return 0;
}