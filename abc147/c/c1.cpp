#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> x(n), y(n);
    rep(i, n){
        int a;
        cin >> a;
        rep(j, a){
            int xx, yy;
            cin >> xx >> yy;
            x[i].push_back(xx);
            y[i].push_back(yy);
        }
    }
    int total = 1<<n, tmp=0, ans=0;
    bool flag=true;
    rep(i, total){
        rep(j, n){
            if((i>>j)&1){
                tmp++;
                int len = x[j].size();
                rep(k, len){
                    if(((i>>(x[j][k]-1))&1)!=y[j][k]){
                        flag = false;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
        }
        if(flag){
            // cout << i << endl;
            ans = max(ans, tmp);
        }
        flag = true;
        tmp = 0;
    }
    cout << ans << endl;
    return 0;
}