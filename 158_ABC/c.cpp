#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    double a, b;
    cin >> a >> b;
    int amin, amax, bmin, bmax;
    if((int)a%2==0){
        amin = (int)(a * 12.5);
        amax = amin + 13;
    }
    else{
        amin = (int)(a * 12.5) + 1;
        amax = amin+ 12;
    }
    bmin = b * 10;
    bmax = bmin + 10;
    int ans = max(amin, bmin);
    if(ans>=amax||ans>=bmax){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}