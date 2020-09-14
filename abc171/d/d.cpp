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
    ll sum = 0;
    map<ll, ll> mp;
    rep(i, n){
        ll num;
        cin >> num;
        sum += num;
        mp[num]++;
    }
    int q;
    cin >> q;
    rep(i, q){
        ll b, c;
        cin >> b >> c;
        mp[c] += mp[b];
        sum -= mp[b] * b;
        sum += mp[b] * c;
        mp.erase(b);
        cout << sum << endl;
    }
    return 0;
}