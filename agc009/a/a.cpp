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
    vector<ll> a, b;
    rep(i, n){
        ll x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    ll res=0;
    rep(i, n){
        if((res+a[n-1-i])%b[n-1-i]){
          res += b[n - 1 - i] - ((res + a[n - 1 - i]) % b[n - 1 - i]);
        }
    }
    cout << res << endl;
    return 0;
}