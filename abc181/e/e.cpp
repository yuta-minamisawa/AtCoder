#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    int n, m;
    cin >> n >> m;
    vector<ll> h, w, abox, bbox, arui, brui;
    h.resize(n);
    w.resize(m);
    for(auto &x : h) cin >> x;
    for(auto &x : w) cin >> x;
    sort(h.begin(), h.end());
    ll asum=0, bsum=0;
    arui.push_back(0);
    brui.push_back(0);
    rep(i, n-1){
        ll dis = h[i+1] - h[i];
        if(i%2){
            bsum += dis;
            bbox.push_back(dis);
            brui.push_back(bsum);
        }else{
            asum += dis;
            abox.push_back(dis);
            arui.push_back(asum);
        }
    }

    ll res = INT64_MAX;

    rep(i, m){
        auto it = lower_bound(h.begin(), h.end(), w[i]);
        int dis = it - h.begin();
        if(dis<n&&(dis==0||dis%2)){
            if(dis!=0){
              res = min(res, bsum - brui[dis/2] + abs(w[i] - h[dis - 1]) + arui[dis/2]); //ok
            }else{
              res = min(res, bsum+h[0]-w[i]); //ok
            }
        }else{
            if(dis>=n-1){
                if(dis==n){
                    res = min(res, asum + w[i] - h[n-1]); //ok
                }else{
                    res = min(res, asum + h[n - 1] - w[i]); //ok
                }
            }else{
                res = min(res, bsum - brui[dis/2] + (h[dis]-w[i]) + arui[dis/2]);
            }
        }
    }

    cout << res << endl;
    return 0; 
}