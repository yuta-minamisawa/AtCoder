#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int x, n;
    cin >> x >> n;
    vector<bool> check(100, true);
    rep(i, n){
        int p;
        cin >> p;
        check[p-1] = false;
    }
    bool flag=true;
    int ans = 0;
    if(check[x-1]){
        ans = x;
        flag = false;
    }

    int dis=1;
    while(flag){
      if (x - 1 - dis>=0){
        if (check[x - 1 - dis]){
          ans = x - dis;
          flag = false;
        }
      }else{
        flag = false;
        break;
      }

      if (flag && x - 1 + dis < 100) {
        if (check[x - 1 + dis]){
          ans = x + dis;
          flag = false;
        } 
      }else{
          if(flag){
            ans = 101;
            flag = false;
          }
      }
        dis++;
        // if (x - 1 - dis < 0 && x - 1 + dis >= 100){
        //     flag = false;
        // }
    }

    cout << ans << endl;

    return 0;
}