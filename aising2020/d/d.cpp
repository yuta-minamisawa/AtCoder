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
    vector<int> rem(2e5+1), digm(n+1), digp(n+1);
    rem[0] = 0;
    rep2(i, 1, n+1){
      int onecnt = 0;
      int tmp = i;
      while (tmp > 0) {
        onecnt += tmp & 1;
        tmp >>= 1;
      }
    //   cout << onecnt << endl;
      int x = i;
      int cnt = 0;
      while (x > 0) {
        tmp = x;
        onecnt = 0;
        while (tmp > 0) {
          onecnt += tmp & 1;
          tmp >>= 1;
        }
        x %= onecnt;
        cnt++;
      }
    //   cout << i << " : " << cnt << endl;
        rem[i] = cnt;
    }

    int summ = 0, sump = 0, twom = 1, twop = 1, y=0;
    string x;
    cin >> x;
    vector<bool> bit;
    bit.push_back(false);
    rep2(i, 1, n+1){
        if(x[n-i]=='1'){
            y++;
            bit.push_back(true);
        }else{
            bit.push_back(false);
        }
    }
    int m = y-1, p = y+1;
    rep2(i, 1, n+1){
      digm[i] = twom;
      digp[i] = twop;
      if (bit[i]) {
          if(m!=0){
            summ = (summ + twom) % m;
          }
        sump = (sump + twop) % p;
        }
        if(m!=0){
          twom = (twom * 2) % m;
        }
        twop = (twop * 2) % p;
    }

    rep2(i, 1, n+1){
        int res;
        if(bit[n+1-i]){
            if(m==0){
                cout << 0 << endl;
                continue;
            }
            // cout << summ << endl;
            res = (summ - digm[n+1-i]) % m;
            if(res<0){
                res += m;
            }
        }else{
            // cout << "sump : " <<  sump << endl;
            res = (sump + digp[n+1-i]) % p;
            // if (res < 0) {
            //   res += p;
            // }
        }
        cout << rem[res] + 1 << endl;
    }
    return 0;
}