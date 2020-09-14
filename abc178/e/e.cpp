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
    vector<ll> plus, xy, yx;
    rep(i, n){
        ll x, y;
        cin >> x >> y;
        plus.push_back(x+y);
        xy.push_back(x-y);
    }
    sort(plus.begin(), plus.end());
    sort(xy.begin(), xy.end());
    ll res=plus[n-1]-plus[0];
    res = max(res, xy[n-1]-xy[0]);
    cout << res << endl;
    return 0;
}