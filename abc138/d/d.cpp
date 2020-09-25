#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

vector<int> res, tmp;
vector<vector<int>> bra;

void dfs(int par, int now);

int main(){
    int n, q;
    cin >> n >> q;
    rep(i, n){
        res.push_back(0);
        bra.push_back(tmp);
    }
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        bra[a-1].push_back(b-1);
        bra[b-1].push_back(a-1);
    }
    rep(i, q){
        int p, x;
        cin >> p >> x;
        res[p-1] += x;
    }

    dfs(-1, 0);

    rep(i, n){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

void dfs(int par, int now){
    int len = bra[now].size();
    if(par!=-1){
        res[now] += res[par];
    }
    rep(i, len) {
      if (bra[now][i] != par) {
        dfs(now, bra[now][i]);
      }
    }
    return;
}