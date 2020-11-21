#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using Pll = pair<ll, ll>;

int main() { 
    int n;
    cin >> n;
    vector<ll> a;
    a.resize(n+1);
    for(auto& x : a) cin >> x;
    ll res = 0;
    rep(i, n){
        ll b;
        cin >> b;
        res += min(a[i], b);
        b -= min(a[i], b);
        res += min(a[i+1], b);
        a[i+1] -= min(a[i+1], b);
    }
    cout << res << endl;
    return 0; 
}