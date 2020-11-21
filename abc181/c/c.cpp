#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;

int main() { 
    int n;
    cin >> n;

    vector<P> p;

    rep(i, n){
        ll x, y;
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }

    string res = "No";

    rep(i, n-2){
        rep2(j, i+1, n-1){
            rep2(k, j+1, n){
                if((p[i].second - p[j].second) * (p[j].first - p[k].first) == (p[i].first - p[j].first) * (p[j].second - p[k].second)){
                    res = "Yes";
                }
            }
        }
    }

    cout << res << endl;
    return 0; 
}