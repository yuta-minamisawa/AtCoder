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
    vector<int> a;
    a.resize(n);
    for(auto &x : a) cin >> x;
    int res = 0, maxim=0;
    rep2(k, 2, 1001){
        int now = 0;
        rep(i, n){
            if(a[i]%k==0){
                now++;
            }
        }
        if(now > maxim){
            res = k;
            maxim = now;
        }
    }
    cout << res << endl;
    return 0; 
}