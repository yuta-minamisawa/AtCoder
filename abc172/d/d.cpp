#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll n, sum=0;
    cin >> n;
    rep2(i, 1, n+1){
        sum += i * (n / i) * (n / i + 1) / 2;
    }
    cout << sum << endl;
    return 0;
}