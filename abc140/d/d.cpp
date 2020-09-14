#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int dif=0, res=0, len=1;
    rep(i, n-1){
        if(s[i]!=s[i+1]){
            dif++;
            res += len - 1;
            len=1;
        }else{
            len++;
        }
    }
    res += len - 1;
    if(dif%2){
        if(dif/2>=k){
            cout << res + 2 * k << endl;
        }else{
            cout << res + 2 * (dif / 2) + 1 << endl;
        }
    }else{
        cout << res + 2 * min(dif/2, k) << endl;
    }
    return 0;
}