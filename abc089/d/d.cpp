#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int h, w, d;
    cin >> h >> w >> d;
    vector<P> a(h*w+1);
    rep(i, h){
        rep(j, w){
            int x;
            cin >> x;
            a[x] = make_pair(i, j);
        }
    }
    vector<int> rui(h*w+1);
    rep(i, d){
        rui[i] = 0;
    }
    rep2(i, d, h*w+1){
        P pre = a[i - d], now = a[i];
        rui[i] += rui[i - d] + abs(pre.first - now.first) + abs(pre.second - now.second);
    }
    int q;
    cin >> q;
    rep(i, q){
        int res = 0;
        int l, r;
        cin >> l >> r;
        res = rui[r] - rui[l];
        cout << res << endl;
    }
    return 0;
}