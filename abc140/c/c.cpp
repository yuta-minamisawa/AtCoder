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
    vector<int> b;
    rep(i, n-1){
        int x;
        cin >> x;
        b.push_back(x);
    }
    int res=b[0]+b[n-2];
    rep(i, n-2){
        res += min(b[i], b[i+1]);
    }
    cout << res << endl;
    return 0;
}