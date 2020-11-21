#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (ll i = (s); i < (ll)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll l, r;
    cin >> l >> r;
    ll res = INT64_MAX;
    rep2(i, l , min(l+2019, r+1)){
        rep2(j, i+1, min(i+2019, r+1)){
            res = min(res, (i*j)%2019);
        }
    }
    cout << res << endl;
    return 0;
}