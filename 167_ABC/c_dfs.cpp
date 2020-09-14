#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int n, m, x;
vector<int> c;
vector<vector<int>> a;

int dfs(int mincost, int book, vector<int> und);

int main()
{ 
    cin >> n >> m >> x;
    rep(i, n)
    {
        int cost;
        cin >> cost;
        c.push_back(cost);
        vector<int> tmp;
        rep(j, m)
        {
            int A;
            cin >> A;
            tmp.push_back(A);
        }
        a.push_back(tmp);
    }
    vector<int> und(m, 0);
    int ans = dfs(0, 0, und);
    if(ans!=INT32_MAX) cout << ans;
    else cout << -1;
    cout << endl;
    return 0;
}

int dfs(int mincost, int book, vector<int> und){
    if(book==n){
        bool flag = true;
        rep(i, m){
            if(und[i]<x){
                flag = false;
                break;
            }
        }
        if(flag) return mincost;
        return INT32_MAX;
    }
    int nocost = dfs(mincost, book+1, und);
    rep(i, m){
        und[i] += a[book][i];
    }
    int buycost = dfs(mincost+c[book], book+1, und);
    return min(nocost, buycost);
}