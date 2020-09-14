#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int memo[15][2];

int main(){
    int n;
    cin >> n;
    rep(i, n){
        int a;
        cin >> a;
        int tr=0, fal=0;
        rep(j, a){
            int x, y;
            cin >> x >> y;
            if(y){
                tr += 1<<(x-1);
            }else{
                fal += 1<<(x-1);
            }
        }
        memo[i][1] = tr;
        memo[i][0] = fal;
    }

    int total = 1<<n, ans=0;
    bool flag=true;
    rep(i, total){
        rep(j, n){
            if((i>>j)&1){
                if((i & memo[j][1]) != memo[j][1]){
                    flag = false;
                    break;
                }
                if((~i & memo[j][0]) != memo[j][0]){
                    flag = false;
                    break;
                }
                if(!flag){
                    break;
                }
            }
        }
        if(flag){
            // cout << i << endl;
            ans = max(ans, __builtin_popcount(i));
        }
        flag = true;
    }
    cout << ans << endl;
    return 0;
}