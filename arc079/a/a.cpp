#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> path(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        path[a].push_back(b);
    }
    rep(i, n){
        sort(path[i].begin(), path[i].end());
    }

    int len = path[0].size();
    string res = "IMPOSSIBLE";
    rep(i, len){
        int mid = path[0][i];
        if((!path[mid].empty())&&path[mid][path[mid].size()-1]==n-1){
            res = "POSSIBLE";
            break;
        }
    }
    cout << res << endl;
    return 0; 
}