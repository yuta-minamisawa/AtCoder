#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll a, b;
    cin >> a >> b;
    map<ll, ll> ay;
    vector<ll> cd;
    for(ll i=1LL;i*i<=a;i++){
        if(a%i==0){
            if(i*i!=a){
              ay[i] = 1;
              ay[a/i] = 1;
            }else{
                ay[i] = 1;
            }
            
        }
    }
    for (ll i = 1LL; i * i <= b; i++) {
      if (b % i==0) {
        if (i * i != b) {
            if(ay[i]){
                cd.push_back(i);
            }
            if(ay[b/i]){
                cd.push_back(b/i);
            }
        } else {
          if (ay[i]) {
            cd.push_back(i);
          }
        }
      }
    }

    sort(cd.begin(), cd.end());
    int len=cd.size(), cnt=1;
    map<ll, int> com;
    rep2(i, 1, len){
        com[cd[i]] = 1;
    }
    rep2(i, 1, len){
        if(com[cd[i]]){
            cnt++;
        }
        rep2(j, i+1, len){
            if(cd[j]&&cd[j]%cd[i]==0){
                com[cd[j]] = 0;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}