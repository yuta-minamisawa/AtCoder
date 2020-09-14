#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> h, dp(n);
    rep(i, n){
        int x;
        cin >> x;
        h.push_back(x);
    }

    dp[0] = 0;
    rep2(i, 1, n){
        int tmpmin = INT32_MAX;
        int tmpk = min(i, k);
        rep2(j, 1, tmpk+1){
            tmpmin = min(tmpmin, dp[i-j]+abs(h[i]-h[i-j]));
        }
        dp[i] = tmpmin;
    }
    cout << dp[n-1] << endl;
    return 0;
}