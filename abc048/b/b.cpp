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
    ll s, e;
    if(a%x){
        s = a / x + 1;
    }else{
        s = a / x;
    }
    e = b / x;
    cout << e - s + 1 << endl;
    return 0;
}