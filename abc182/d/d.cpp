#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    ll n;
    cin >> n;
    vector<ll> a(n), rui(n), peak(n);
    a.resize(n);
    rui.resize(n);
    for(auto &x : a) cin >> x;
    ll sum=0, p=0;
    rep(i, n){
        sum += a[i];
        p = max(p, sum);
        peak[i] = p;
        rui[i] = sum;
    }
    ll res = 0, now = 0;
    rep(i, n){
        res = max(res, now+peak[i]);
        now += rui[i];
    }
    cout << res << endl;
    return 0; 
}