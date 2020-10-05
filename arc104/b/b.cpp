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
    string s;
    cin >> s;
    vector<int> tmp(n+1, 0);
    vector<vector<int>> dp(4, tmp);
    string check = "ATCG";
    rep(i, n){
        rep(j, 4){
            if(s[i]==check[j]){
                dp[j][i+1] = 1;
            }
        }
    }
    int res = 0;
    rep(i, 4){
        rep2(j, 1, n+1){
            dp[i][j] += dp[i][j-1];
        }
    }
    rep2(i, 1, n+1){
        rep2(j, i, n+1){
            vector<int> num(4);
            rep(k, 4){
                num[k] = dp[k][j] - dp[k][i-1];
            }
            if((num[0]==num[1])&&(num[2]==num[3])){
                res++;
            }
        }
    }
    cout << res << endl;
    return 0; 
}