#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> c(m, 0), a(m);
    rep(i, m){
        int x, b;
        cin >> x >> b;
        a[i] = x;
        rep(j, b){
            int y;
            cin >> y;
            c[i] += 1<<(y-1);
        }
    }

    vector<int> dp(1<<n, INT32_MAX);
    rep(i, m){
        dp[c[i]] = min(dp[c[i]], a[i]);
        rep(j, 1<<n){
            if(dp[j]!=INT32_MAX&&j!=c[i]){
                dp[j | c[i]] = min(dp[j | c[i]], dp[j] + dp[c[i]]);
            }
        }
    }

    if(dp[(1<<n)-1]==INT32_MAX){
        cout << -1 << endl;
    }else{
        cout << dp[(1 << n) - 1] << endl;
    }
    
    return 0;
}