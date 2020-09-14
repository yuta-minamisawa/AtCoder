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
    ll l = 0LL, r = 1e9+1LL;
    while(r-l>1){
        ll mid = (l + r) / 2;
        ll num = mid;
        ll d = 0;
        while(num>0){
            d++;
            num /= 10LL;
        }
        ll kane = a * mid + b * d;
        if(x>=kane){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}