#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define INFTY 2001

int n, x, y;
vector<vector<int>> route, mindis;

void bfs();

int main(){
    cin >> n >> x >> y;
    vector<int> tmp(n, INFTY), tmp2;
    rep(i, n){
        mindis.push_back(tmp);
        route.push_back(tmp2);
        mindis[i][i] = 0;
    }

    rep(i, n-1){
        route[i].push_back(i+1);
        route[i+1].push_back(i);
    }
    route[x-1].push_back(y-1);
    route[y-1].push_back(x-1);

    bfs();

    vector<int> count(n, 0);

    rep(i, n-1){
        rep2(j, i+1, n){
            count[mindis[i][j]]++;
        }
    }

    rep2(i, 1, n){
        cout << count[i] << endl;
    }

    return 0;
}

void bfs(){
    queue<int> q;
    rep(i, n){
        rep(j, route[i].size()){
            q.push(route[i][j]);
        }
        int cnt=1;
        while(!q.empty()){
            int s_size = q.size();
            int c;
            rep(j, s_size){
                c = q.front();
                q.pop();
                if(mindis[i][c]==INFTY){
                    mindis[i][c] = cnt;
                    int r_size = route[c].size();
                    rep(k, r_size)
                    {
                        if (mindis[i][route[c][k]] == INFTY){
                            q.push(route[c][k]);
                        }
                    }
                }
                
            }
            cnt++;
        }
    }
}