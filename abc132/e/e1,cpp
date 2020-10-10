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
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, m, s, t;
vector<int> adj[MAX], inicos;

void dijkstra();

int main() { 
    cin >> n >> m;
    inicos.resize(n);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
    }
    cin >> s >> t;
    s--;
    t--;
    rep(i, 3){
        dijkstra();
        if(inicos[t]%3==0){
            cout << inicos[t] / 3 << endl;
            break;
        }
    }
    cout << -1 << endl;
    return 0; 
}

void dijkstra(){
    priority_queue<P> pq;
    int color[n];
    int d[n];
    rep(i, n){
        color[i] = WHITE;
        d[i] = INFTY;
    }

    d[s] = inicos[s];
    pq.push(make_pair(inicos[s], s));
    color[s] = GRAY;

    while(!pq.empty()){
        P f = pq.top();
        pq.pop();
        int u = f.second;
        color[u] = BLACK;

        if(d[u] + inicos[u] < f.first * (-1)) continue;

        int adjlen = adj[u].size();
        rep(j, adjlen){
            int v = adj[u][j];
            if(color[v]==BLACK){
                continue;
            }
            if(d[v] + inicos[v] > d[u] + 1){
                d[v] = d[u] + 1;
                pq.push(make_pair(d[v]*(-1), v));
                color[v] = GRAY;
            }
        }
    }

    rep(i, n){
        cout << i << " " << d[i] << endl;
        inicos[i] = d[i];
    }
}