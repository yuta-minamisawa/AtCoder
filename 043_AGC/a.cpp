#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s;
    vector<vector<int>> board, dp;
    vector<int> tmp(w, 0);
    rep(i, h){
        board.push_back(tmp);
        dp.push_back(tmp);
        string str;
        cin >> str;
        s.push_back(str);
    }
    
    rep(i, h){
        rep(j, w){
            if(s[i][j]=='.') board[i][j] = 0;
            else    board[i][j] = 1;
        }
    }

    if(board[h-1][w-1]==0) dp[h-1][w-1] = 0;
    else dp[h-1][w-1] = 1;

    for(int i=h-1;i>=0;i--){
        for(int j=w-1;j>=0;j--){
            if(i==h-1){
                if(j==w-1) continue;
                if(board[i][j]==board[i][j+1]){ //most down
                    dp[i][j] = dp[i][j+1];
                }else{
                    if(board[i][j]==0)  dp[i][j] = dp[i][j+1];
                    else dp[i][j] = dp[i][j+1] + 1;
                }
            }else{
                if(j==w-1){ //most right
                    if(board[i][j]==board[i+1][j]){
                        dp[i][j] = dp[i+1][j];
                    }else{
                        if(board[i][j]==0)  dp[i][j] = dp[i+1][j];
                        else dp[i][j] = dp[i+1][j] + 1;
                    }
                }else{
                    int dpplusx, dpplusy;
                    if(board[i][j]-board[i][j+1]==-1){
                        dpplusx = 0;
                    }else{
                        dpplusx = board[i][j]-board[i][j+1];
                    }
                    if(board[i][j]-board[i+1][j]==-1){
                        dpplusy = 0;
                    }else{
                        dpplusy = board[i][j]-board[i+1][j];
                    }
                    int x = dp[i][j+1] + dpplusx;
                    int y = dp[i+1][j] + dpplusy;
                    dp[i][j] = min(x, y);
                }
            }
        }
    }


    cout << dp[0][0] << endl;
    return 0;
}