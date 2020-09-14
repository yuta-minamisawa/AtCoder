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
    int pre=0, cnt=0, res=0;
    rep(i, n){
        int h;
        cin >> h;
        if(pre>=h){
            cnt++;
        }else{
            res = max(res, cnt);
            cnt = 0;
        }
        pre = h;
    }
    res = max(res, cnt);
    cout << res << endl;
    return 0;
}