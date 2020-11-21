#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    ll n, w;
    cin >> n>> w;
    vector<ll> need(200002, 0);
    // vector<ll> s(n), t(n), p(n);
    rep(i, n){
        ll a, b, c;
        cin >> a >> b >> c;
        need[a] += c;
        need[b] -= c; 
        // s[i] = a;
        // t[i] = b;
        // p[i] = c;
    }
    ll now=0;
    string res = "Yes";
    rep(i, 200002){
        now+=need[i];
        if(now>w){
            res = "No";
            break;
        }
    }

    cout << res << endl;
    return 0; 
}