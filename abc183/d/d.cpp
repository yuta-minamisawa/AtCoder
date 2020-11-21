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
    ll n, w;
    cin >> n>> w;
    vector<Pll> v;
    rep(i, n){
        ll s, t, p;
        cin >> s >> t >> p;
        v.emplace_back(s, p);
        v.emplace_back(t, -p);
    }

    sort(v.begin(), v.end());
    ll now = 0;
    string res = "Yes";

    rep(i, 2*n){
        now += v[i].second;
        if(now > w){
            res = "No";
            break;
        }
    }

    cout << res << endl;
    return 0; 
}