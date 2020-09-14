#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int x, y;
    cin >> x >> y;
    if(x==1&&y==1){
        cout << 1000000 << endl;
    }else{
        int ans=0;
        if(x<=3){
            ans += 1e5 * (4-x);
        }
        if(y<=3){
            ans += 1e5 * (4-y);
        }
        cout << ans << endl;
    }
    return 0;
}