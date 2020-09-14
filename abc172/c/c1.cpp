#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a, b;
    ll sum=0;
    bool flag=true;
    rep(i, n){
        ll x;
        cin >> x;
        sum += x;
        if(flag){
            if(sum<=k){
                a.push_back(sum);
            }else{
                flag=false;
            }
        }
    }
    if (a.empty()) {
      a.push_back(1e10);
    }
    sum=0;
    flag = true;
    rep(i, m) {
      ll x;
      cin >> x;
      sum += x;
      if (flag) {
        if (sum <= k) {
            b.push_back(sum);
        } else {
            flag = false;
        }
      }
    }
    if(b.empty()){
        b.push_back(1e10);
    }
    int len = a.size(), maxim=0;
    for(int i=len-1;i>=0;i--){
        ll rem = k - a[i];
        int x = 1;
        if(rem<0){
            rem = k;
            x = 0;
        }
        int l = 0, r = b.size(), mid;
        while(l<r){
            mid = (l + r) / 2;
            if(b[mid]>rem){
                r = mid;
            }else{
                if(b[mid]<rem){
                  l = mid + 1;
                }else{
                    break;
                }
            }
        }
        // cout << mid << endl;
        if(b[mid]>rem){
            mid--;
            // mid = max(mid, 0);
        }
        maxim = max(maxim, i + mid + x + 1);
        // cout << maxim << endl;
    }
    // a, 1個も取らない場合
    ll rem = k;
    int l = 0, r = b.size(), mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (b[mid] > rem) {
        r = mid;
      } else {
        if (b[mid] < rem) {
          l = mid + 1;
        } else {
          break;
        }
      }
    }
    // cout << mid << endl;
    if (b[mid] > rem) {
      mid--;
      // mid = max(mid, 0);
    }
    maxim = max(maxim, mid + 1);
    cout << maxim << endl;
    return 0;
}