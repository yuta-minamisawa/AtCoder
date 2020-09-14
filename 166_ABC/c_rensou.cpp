#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> h, tmp;
    vector<vector<int>> route;
    rep(i, n){
        int H;
        cin >> H;
        h.push_back(H);
        route.push_back(tmp);
    }

    rep(i, m){
        int A, B;
        cin >> A >> B;
        route[A-1].push_back(B-1);
        route[B-1].push_back(A-1);
    }

    int ans=0;
    rep(i, n){
        int route_size = route[i].size();
        int height = h[i];
        bool flag=true;
        rep(j, route_size){
            if(height<=h[route[i][j]]){
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }

    cout << ans << endl;
    return 0;
}