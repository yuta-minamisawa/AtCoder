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
        vector<ll> dis;
        dis.push_back(a[0]);
        rep(i, n-1){
            dis.push_back(a[i+1]-a[i]);
        }
        for(ll i=n-1LL;i>=0LL;i--){
            if(dis[i]){
                if(dis[i] * (n - i) < k){
                    k -= dis[i] * (n - i);
                }else{
                    ll d = k / (n-i) + 1;
                    ll A = a[i] - d;
                    // cout << k << endl;
                    // cout << d << endl;
                    rep(j, k%(n-i)){
                        a[i+j] = A;
                        // cout << j << " " << a[i+j] << endl;
                    }
                    rep2(j, k%(n - i), n-i){
                      a[i + j] = A + 1LL;
                    //   cout << j << " " << a[i + j] << endl;
                    }
                    break;
                }
            }
        }
        rep(i, n){
            cout << a[i] << " ";
        }
        cout << endl;
        ll maxim=0;
        rep(i, n){
            maxim = max(maxim, a[i]*f[n-i-1]);
        }
        cout << maxim << endl;
    }
    return 0;
}