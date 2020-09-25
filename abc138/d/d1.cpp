#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> res(n, 0), tmp;
    vector<bool> check(n, true);
    vector<vector<int>> bra(n, tmp);
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
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int now = que.front();
        check[now] = false;
        que.pop();
        int len = bra[now].size();
        rep(i, len){
            if(check[bra[now][i]]){
                res[bra[now][i]] += res[now];
                que.push(bra[now][i]);
            }
        }
    }

    rep(i, n){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}