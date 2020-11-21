#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    ll n, k;
    cin >> n >> k;
    ll res = 0;
    for(ll x=2; x<=2*n;x++){
        if((x-k < 2) || (2*n < x - k)) continue;
        res += (x-1 - 2LL*max((x-n-1), 0LL)) * ((x-k-1) - 2LL*max(x-k-1-n, 0LL));
    }
    cout << res << endl;
    return 0; 
}