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
    vector<int> a, ans(n+1, 0);
    a.push_back(0);
    rep(i, n){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i=n;i>=1;i--){
        ans[i] ^= a[i];
        if(i!=1&&ans[i]){
          for (int j = 1; j * j <= i; j++) {
              if(i%j==0){
                if (j != 1 && j * j != i) {
                  ans[j] ^= 1;
                  ans[i / j] ^= 1;
                } else {
                  ans[j] ^= 1;
                }
              }
          }
        }
    }
    int m=0;
    vector<int> res;
    rep2(i, 1, n+1){
        if(ans[i]){
            m++;
            res.push_back(i);
        }
    }
    cout << m << endl;
    int len = res.size();
    rep(i, len){
        cout << res[i] << endl;
    }
    return 0;
}