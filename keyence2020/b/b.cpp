#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll,ll>;

int main(){
    int n;
    cin >> n;
    vector<P> seg;
    rep(i, n){
        ll x, l;
        cin >> x >> l;
        seg.push_back(make_pair(x + l, x - l));
    }

    sort(seg.begin(), seg.end());
    ll wall = INT64_MIN, cnt=0LL;
    rep(i, n){
        if(wall <= seg[i].second){
            cnt++;
            wall = seg[i].first;
        }
    }

    cout << cnt << endl;
    return 0;
}