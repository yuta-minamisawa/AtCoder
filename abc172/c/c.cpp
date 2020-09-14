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
    a.push_back(sum);
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
    sum=0;
    flag = true;
    b.push_back(sum);
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
    int maxim=0;
    for(int i=a.size()-1;i>=0;i--){
      ll rem = k - a[i];
      vector<ll>::iterator pos = upper_bound(b.begin(), b.end(), rem);
      int dis = distance(b.begin(), pos)-1;
      maxim = max(maxim, i+dis);
    }
    cout << maxim << endl;
    return 0;
}