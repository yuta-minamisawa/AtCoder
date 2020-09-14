#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll h, w;
    cin >> h >> w;
    if(h*w%3==0){
        cout << 0 << endl;
    }else{
        ll total = h * w, ideal = total / 3L;
        ll hcut = ideal / w, wcut = ideal / h;
        ll sum[3], res=INT64_MAX, rem;
        if(hcut!=0){
            sum[0] = (hcut+1) * w;
            rem = total - sum[0];
            if (rem % 2) {
              ll remh = h - hcut - 1;
              sum[1] = max(rem / 2 / w * w, rem / 2 / remh * remh);
              sum[2] = rem - sum[1];
            } else {
              sum[1] = rem / 2;
              sum[2] = rem / 2;
            }
            sort(sum, sum + 3);
            res = sum[2] - sum[0];
        }else{
            hcut = 1;
        }
        sum[0] = hcut * w;
        rem = total - sum[0];
        if (rem % 2) {
          ll remh = h - hcut;
          sum[1] = max(rem / 2 / w * w, rem / 2 / remh * remh);
          sum[2] = rem - sum[1];
        } else {
          sum[1] = rem / 2;
          sum[2] = rem / 2;
        }
        sort(sum, sum + 3);
        res = min(res, sum[2] - sum[0]);

        if (wcut != 0) {
          sum[0] = (wcut + 1) * h;
          rem = total - sum[0];
          if (rem % 2) {
            ll remw = w - wcut - 1;
            sum[1] = max(rem / 2 / remw * remw, rem / 2 / h * h);
            sum[2] = rem - sum[1];
          } else {
            sum[1] = rem / 2;
            sum[2] = rem / 2;
          }
          sort(sum, sum + 3);
          res = min(res, sum[2] - sum[0]);
        } else {
          wcut = 1;
        }
        sum[0] = wcut * h;
        rem = total - sum[0];
        if (rem % 2) {
          ll remw = w - wcut;
          sum[1] = max(rem / 2 / remw * remw, rem / 2 / h * h);
          sum[2] = rem - sum[1];
        } else {
          sum[1] = rem / 2;
          sum[2] = rem / 2;
        }
        sort(sum, sum + 3);
        res = min(res, sum[2] - sum[0]);
        cout << res << endl;
    }
    return 0;
}