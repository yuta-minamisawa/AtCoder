#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int n, m;
    cin >> n >> m;
    //vector<vector<bool>> check;
    vector<vector<int>> root;
    vector<int> h;
    rep(i, n){
        vector<int> c;
        // rep(j, n){
        //     c.push_back(false);
        // }
        root.push_back(c);
    }
    rep(i, n){
        int height;
        cin >> height;
        h.push_back(height);
    }
    rep(i, m){
        int a, b;
        cin >> a >> b;
        root[a-1].push_back(b-1);
        root[b-1].push_back(a-1);
        // check[a-1][b-1] = true;
        // check[b-1][a-1] = true;
    }
    int ans=n;
    rep(i, n){
        rep(j, root[i].size()){
            int enemy = root[i][j];
            if(h[i]<=h[enemy]){
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}