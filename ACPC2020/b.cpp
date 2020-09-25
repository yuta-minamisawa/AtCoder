#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    int n, q;
    cin >> n >> q;
    vector<ll> rui;
    ll total = 0;
    rui.push_back(0);
    rep(i, n){
        ll a;
        cin >> a;
        total += a;
        rui.push_back(total);
    }
    rep(i, q){
        ll l, r;
        cin >> l >> r;
        cout << rui[l] - rui[l-1] - (rui[r] - rui[l]) << endl;
    }
    return 0; 
}