#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll n, k, digit=1;
    cin >> n >> k;
    ll lim = k;
    while(lim<=n){
        digit++;
        lim *= k;
    }
    cout << digit << endl;
    return 0;
}