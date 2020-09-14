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
    vector<int> a, b, c;
    rep(i, n){
        int x;
        cin >> x;
        a.push_back(x);
    }
    rep(i, n) {
      int x;
      cin >> x;
      b.push_back(x);
    }
    rep(i, n-1) {
      int x;
      cin >> x;
      c.push_back(x);
    }
    int res=0;
    rep(i, n){
        res += b[a[i]-1];
        if(i!=0&&a[i]-a[i-1]==1){
            res += c[a[i-1]-1];
        }
    }
    cout << res << endl;
    return 0;
}