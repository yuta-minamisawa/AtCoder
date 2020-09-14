#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    double a, b, x;
    cin >> a >> b >> x;
    double men = x / a;
    double ans;
    if(men<=a*b/2){
        ans = 90 - atan(2*men/(b*b)) * 180 / M_PI;
    }else{
        double tmp = 2 * men / a;
        ans = 90 - atan(a / (2 * b - tmp)) * 180 / M_PI;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}