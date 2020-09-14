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
    vector<ll> a, num(n+1, 0), sum(n+1, 0);
    ll x, total=0;
    rep(i, n){
        cin >> x;
        a.push_back(x);
        num[x]++;
    }
    rep2(i, 1, n+1){
        ll x = num[i];
        sum[i] = x * (x-1) / 2LL;
        total += sum[i];
    }
    rep2(i, 1, n+1){
        ll now = a[i-1];
        cout << total - sum[now] + (num[now]-1) * (num[now]-2) / 2LL << endl;
    }
    return 0;
}