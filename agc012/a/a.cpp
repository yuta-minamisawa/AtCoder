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
    rep(i, n*3){
        ll x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    ll sum=0;
    rep(i, n){
        sum += a[n*3-2-i*2];
    }
    cout << sum << endl;
    return 0;
}