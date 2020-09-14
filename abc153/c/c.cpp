#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> h;
    rep(i, n){
        ll x;
        cin >> x;
        h.push_back(x);
    }
    sort(h.begin(), h.end());
    ll sum=0;
    if(k<n){
        rep(i, n-k){
            sum += h[i];
        }
    }
    cout << sum << endl;
    return 0;
}