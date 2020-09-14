#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int k, s, cnt=0;
    cin >> k >> s;
    rep(x, k+1){
        rep(y, k+1){
            if(s-x-y>=0&&s-x-y<=k){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}