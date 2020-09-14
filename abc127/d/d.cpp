#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> a;
    rep(i, n){
        ll x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    vector<P> cb;
    rep(i, m){
        ll b, c;
        cin >> b >> c;
        cb.push_back(make_pair(c*(-1), b));
    }

    sort(cb.begin(), cb.end());

    ll now = 0;
    bool flag = true;

    rep(i, m){
        ll cnt=0;
        if(a[now] >= cb[i].first*(-1)){
            break;
        }
        while(cnt<cb[i].second){
          if (a[now] >= cb[i].first * (-1)) {
            break;
          } else {
            a[now++] = cb[i].first * (-1);
            cnt++;
          }
            if(now >= n){
                flag = false;
                break;
            }
        }
        if(!flag){
            break;
        }
    }

    ll sum=0;

    rep(i, n){
        sum += a[i];
    }

    cout << sum << endl;
    return 0;
}