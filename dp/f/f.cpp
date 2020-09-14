#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    string s, t;
    cin >> s >> t;
    int slen = s.size(), tlen = t.size();
    vector<P> tmp(tlen + 1, make_pair(0, -1));
    vector<vector<P>> dp(slen+1, tmp);
    
    rep2(i, 1, slen+1){
        rep2(j, 1, tlen+1){
            if(s[i-1]==t[j-1]){
                dp[i][j] = make_pair(dp[i-1][j-1].first+1, 0);
            }else{
                if(dp[i][j-1]>=dp[i-1][j]){
                    dp[i][j] = make_pair(dp[i][j-1].first, 1);
                }else{
                    dp[i][j] = make_pair(dp[i-1][j].first, 2);
                }
            }
        }
    }

    int i=slen, j=tlen;
    stack<char> ans;
    while(1){
        int direct = dp[i][j].second;
        if(direct<1){
            if(direct==-1){
                break;
            }else{
                ans.push(s[i-1]);
                i--;
                j--;
            }
        }else{
            if(direct==1){
                j--;
            }else{
                i--;
            }
        }
    }

    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    cout << endl;
    return 0;
}