#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<int> h, dp(n);
    rep(i, n){
        int x;
        cin >> x;
        h.push_back(x);
    }
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    rep2(i, 2, n) { 
        dp[i] = min(dp[i-1] + abs(h[i] - h[i - 1]), dp[i-2] + abs(h[i] - h[i - 2])); 
    }
    cout << dp[n-1] << endl;
    return 0;
}