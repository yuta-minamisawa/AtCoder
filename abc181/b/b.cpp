#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    vector<ll> rui(1000001);
    ll sum = 0;
    rep(i, 1000001){
        rui[i] = sum;
        sum += (i+1); 
    }

    int n;
    cin >> n;

    ll res = 0;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        res += rui[b] - rui[a-1];
    }

    cout << res << endl;
    return 0; 
}