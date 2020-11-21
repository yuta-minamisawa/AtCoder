#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll res=0, times=a-1, X=x;
    while(times<=(b-1)/X){
        res++;
        x += times*X;
        times *= a;
        if(x>=y){
            res--;
            break;
        }
    }
    if(x<y){
        res += (y-x-1) / b;
    }
    cout << res << endl;
    return 0; 
}