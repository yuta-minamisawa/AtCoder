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
    vector<int> h(n);
    h.assign(n, 0);
    for(auto &x : h) cin >> x;
    string res = "Yes";
    rep2(i, 1, n){
        if(h[i-1]>h[i]){
            res = "No";
            break;
        }else{
            if(h[i-1]!=h[i]){
                h[i]--;
            }
        }
    }
    cout << res << endl;
    return 0;
}