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
    vector<int> h;
    rep(i, n){
        int x;
        cin >> x;
        h.push_back(x);
    }
    h.push_back(0);
    int now, top, ans=0;
    vector<int> res;
    res.push_back(0);
    rep(i, n+1){
      now = res.back();
      while (now > h[i]) {
        res.pop_back();
        top = res.back();
        ans += now - max(top, h[i]);
        now = top;
      }
      if (now < h[i]) {
        res.push_back(h[i]);
      }
    }
    cout << ans << endl;
    return 0;
}