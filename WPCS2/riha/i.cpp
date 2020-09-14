#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main()
{
    int t;
    cin >> t;
    rep(i, t){
        int n, m;
        cin >> n >> m;
        vector<string> g;
        rep(j, n){
            string G;
            cin >> G;
            g.push_back(G);
        } 
        vector<vector<int>> check;
        rep(j, n){
            vector<int> tmp;
            rep(k, m){
                tmp.push_back(0);
            }
        }
    }
    return 0;
}