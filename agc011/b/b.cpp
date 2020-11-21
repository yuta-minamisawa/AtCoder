#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using Pll = pair<ll, ll>;

int main() { 
    int n;
    cin >> n;
    vector<ll> a(n), rui(n+1, 0);
    a.resize(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    rep2(i, 1, n+1){
        rui[i] = rui[i-1] + a[i-1];
    }

    int res = 1;
    for(int i=n-1;i>0;i--){
        if(rui[i] * 2 >= a[i]){
            res++;
        }else{
            break;
        }
    }

    cout << res << endl;
    return 0; 
}