#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<ll> a;
    rep(i, n){
        ll x;
        cin >> x;
        a.push_back(x);
    }
    ll ans=0;
    rep(i, n){
        ans = 2*a[i] - ans;
    }
    ans /= 2;
    cout << ans << " ";
    rep(i, n-1){
        ans = 2*a[i] - ans;
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}