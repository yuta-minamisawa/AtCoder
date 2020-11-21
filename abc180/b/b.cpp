#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    int n;
    cin >> n;
    // vector<int> x;
    ll man=0, euc=0, tye=0;
    rep(i, n){
        ll x;
        cin >> x;
        ll absx = abs(x);
        man += absx;
        euc += absx * absx;
        tye = max(tye, absx);
    }
    cout << man << endl;
    cout << fixed << setprecision(15);
    cout << sqrt(euc) << endl;
    cout << tye << endl;
    return 0; 
}