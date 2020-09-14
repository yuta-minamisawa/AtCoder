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
    vector<ll> a(100001, 0);
    rep(i, n){
        ll num;
        cin >> num;
        sum += num;
        a[num]++;
    }
    int q;
    cin >> q;
    rep(i, q){
        ll b, c;
        cin >> b >> c;
        a[c] += a[b];
        sum -= a[b] * b;
        sum += a[b] * c;
        a[b] = 0;
        cout << sum << endl;
    }
    return 0;
}