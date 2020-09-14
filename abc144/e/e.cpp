#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll n, k, sum=0LL;
    cin >> n >> k;
    vector<ll> a, f;
    rep(i, n){
        ll x;
        cin >> x;
        a.push_back(x);
        sum += x;
    }
    rep(i, n) {
        ll x;
        cin >> x;
        f.push_back(x);
    }
    if(sum<=k){
        cout << 0 << endl;
    }else{
        sort(a.begin(), a.end());
        sort(f.begin(), f.end());
        ll maxim=0;
        rep(i, n){
            maxim = max(maxim, a[i]*f[n-i-1]);
        }
        ll l=0, r=maxim;
        while(r-l>1){
            ll mid = (l + r) / 2LL;
            ll times=0;
            bool flag=true;
            rep(i, n){
                ll cost = mid / f[n-1LL-i];
                // cout << cost << endl;
                times += max(0LL, a[i]-cost);
                if(times>k){
                    l = mid;
                    flag = false;
                    break;
                }
            }
            if(flag){
                r = mid;
            }
            // cout << l << " : " << r << endl;
        }
        cout << r << endl;
    }
    return 0;
}