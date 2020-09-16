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
    vector<int> c, s, f;
    rep(i, n-1){
        int x, y, z;
        cin >> x >> y >> z;
        c.push_back(x);
        s.push_back(y);
        f.push_back(z);
    }
    rep(i, n-1){
        int res=s[i];
        rep2(j, i, n-1){
            if(res<s[j]){
                res = s[j];
            }
            if(res%f[j]){
                res += f[j] - res%f[j];
            }
            res += c[j];
        }
        cout << res << endl;
    }
    cout << 0 << endl;
    return 0;
}