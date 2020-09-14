#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

void update(int i, int x);
int query(int x, int y, int k, int l, int r);

int n;
vector<int> GCD;

int main(){
    cin >> n;
    vector<int> a, num(1e6+1, 1), pri, P(1e6+1, 1);

    int cnt=0;
    
    rep(i, n){
        int x;
        cin >> x;
        if(x!=1){
          cnt++;
        }
        a.push_back(x);
    }
    num[0] = 0;
    num[1] = 0;

    rep2(i, 2, 1e6+1){
        if(num[i]){
            pri.push_back(i);
            rep3(j, i*2, 1e6+1, i){
                num[j] = 0;
            }
        }
    }

    bool flag = true;

    if(cnt<79000){
      rep(i, n) {
        int check = a[i];
        rep2(j, 2, sqrt(check)+1){
          if (check % j == 0) {
            if (P[j]) {
              P[j] = 0;
            } else {
              flag = false;
              break;
            }
            while (check % j == 0) {
              check /= j;
            }
          }
        }
        if(check!=1){
            if(P[check]){
                P[check] = 0;
            }else{
                flag = false;
            }
        }
        if (!flag) {
          break;
        }
      }
    }else{
        flag = false;
    }

    


    if(flag){
      cout << "pairwise coprime" << endl;
    }else{
      rep(i, 30) {
        if ((n - 1) < 1 << i) {
          n = 1 << i;
          break;
        }
      }

      rep(i, 2 * n - 1) { GCD.push_back(0); }

        int alen = a.size();
      rep(i, alen){
          update(i, a[i]);
      }

        if(query(0, n, 0, 0, n)==1){
          cout << "setwise coprime" << endl;
        }else{
            cout << "not coprime" << endl;
        }

    }
    return 0;
}

void update(int i, int x) {
  i += n - 1;
  GCD[i] = x;
  while (i > 0) {
    i = (i - 1) / 2;
    GCD[i] = gcd(GCD[i * 2 + 1], GCD[i * 2 + 2]);
  }
}

int query(int x, int y, int k, int l, int r) {
  if (r <= x || y <= l) return 0;
  if (x <= l && r <= y)
    return GCD[k];
  else {
    int vl = query(x, y, k * 2 + 1, l, (l + r) / 2);
    int vr = query(x, y, k * 2 + 2, (l + r) / 2, r);
    return gcd(vl, vr);
  }
}