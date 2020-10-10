#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

static const int MAX = 100000;
static const int INFTY = 1000000;

int n, m, s, t;
vector<int> adj[MAX], tmp;
vector<vector<int>> dp;

void dijkstra();

int main() { 
    cin >> n >> m;
    tmp.resize(n, INFTY);
    dp.resize(3, tmp);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
    }
    cin >> s >> t;
    s--;
    t--;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(make_pair(0, s));
    dp[0][s] = 0;

    while(!pq.empty()){
        P now = pq.top();
        pq.pop();

        if(now.first != dp[now.first % 3][now.second]) continue;

        for(auto v : adj[now.second]){
          if (now.first + 1 < dp[(now.first + 1) % 3][v]) {
            dp[(now.first + 1) % 3][v] = now.first + 1;
            pq.push(make_pair(now.first + 1, v));
          }
        }
    }

    if(dp[0][t]==INFTY){
        cout << -1 << endl;
    }else{
        cout << dp[0][t] / 3 << endl;
    }
    
    return 0; 
}