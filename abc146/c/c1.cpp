#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll a, b, x;
    cin >> a >> b >> x;
    ll l=0LL, r=1e9+1LL;
    while(l<r){
        ll mid = (l + r) / 2LL;
        ll d = log10(mid)+1LL;
        ll kane = a * mid + b * d;
        if(kane<x){
            l = mid+1LL;
        }else{
            r = mid;
        }
    }
    bool flag = true;
    rep(i, 3){
        ll n = l - 1LL + i;
        ll d = log10(n)+1LL;
        ll kane = a * n + b * d;
        if(kane>x){
            if(n-1LL<=1e9){
              cout << n - 1LL << endl;
            }else{
              cout << 1000000000 << endl;
            }
            flag = false;
            break;
        }
    }
    if(flag){
        if(l+1LL>=1e9){
            cout << 1000000000 << endl;
        }else{
            cout << l + 1LL << endl;
        }
    }
    return 0;
}