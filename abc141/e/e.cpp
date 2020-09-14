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
    string s;
    cin >> s;

    vector<int> tmp(n+1, 0);
    vector<vector<int>> dp(n+1, tmp);

    int res = 0;

    rep2(i, 1, n+1){
        rep2(j, 1, n+1){
            if(s[i-1]==s[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                res = max(res, min(dp[i][j], j-i));
            }
        }
    }

    cout << res << endl;
    return 0;
}