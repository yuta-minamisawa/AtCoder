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
    vector<int> x, y;
    vector<int> start(n+1, 1), dp(n+1, 0), from(n+1, 0);
    vector<vector<int>> to(n+1);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
        from[b]++;
        to[a].push_back(b);
        if(start[b]){
            start[b] = 0;
        }
    }

    rep2(i, 1, n+1){
        if(start[i]){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int top = q.front();
                q.pop();
                if(from[top]>1){
                    from[top]--;
                }else{
                    int len = to[top].size();
                    rep(j, len) { 
                        dp[to[top][j]] = max(dp[top] + 1, dp[to[top][j]]);
                        q.push(to[top][j]); 
                    }
                }
            }
        }
    }

    int maxim = 0;
    rep2(i, 1, n+1){
        maxim = max(maxim, dp[i]);
    }

    cout << maxim << endl;
    return 0;
}