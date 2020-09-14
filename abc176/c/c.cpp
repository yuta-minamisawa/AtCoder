#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll n, res=0, maxim=0;
    cin >> n;
    // vector<ll> a;
    rep(i, n){
        ll x;
        cin >> x;
        res += max(0LL, maxim - x);
        maxim = max(maxim, x);
        // a.push_back(x);
    }
    cout << res << endl;
    return 0;
}