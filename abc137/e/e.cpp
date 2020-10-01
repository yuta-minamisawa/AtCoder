#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using Pll = pair<ll, ll>;

int main(){
    int n, m, p;
    cin >> n >> m >> p;
    vector<ll> tmp(n, INT64_MAX), dist(n, INT64_MAX), over(n);
    vector<Pll> path;
    vector<vector<ll>> d(n, tmp);
    dist[0] = 0;
    rep(i, m){
        ll a, b, c;
        cin >> a >> b >> c;
        path.push_back(make_pair(--a, --b));
        d[a][b] = min(d[a][b], p - c);
    }
    rep(i, n-1){
        for(auto [f, t] : path){
            if(dist[f]!=INT64_MAX && dist[f] + d[f][t] < dist[t]){
                dist[t] = dist[f] + d[f][t];
            }
        }
    }

    ll pre = dist[n-1];

    rep(i, n-1) {
      for (auto [f, t] : path) {
        if (dist[f] != INT64_MAX && dist[f] + d[f][t] < dist[t]) {
          dist[t] = INT32_MIN;
        }
      }
    }

    if(pre!=dist[n-1]){
        cout << -1 << endl;
        return 0;
    }

    cout << max(0LL, -dist[n-1]) << endl;
    return 0;
}