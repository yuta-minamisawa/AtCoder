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
    vector<ll> l, tmp;
    rep(i, n){
        ll x;
        cin >> x;
        l.push_back(x);
    }

    int cnt = 0;
    rep(i, n-2){
        rep2(j, i+1, n-1){
            rep2(k, j+1, n){
                tmp.clear();
                tmp.push_back(l[i]);
                tmp.push_back(l[j]);
                tmp.push_back(l[k]);
                sort(tmp.begin(), tmp.end());
                tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
                if (tmp.size() != 3) {
                    continue;
                }
                if(tmp[0]+tmp[1]>tmp[2]){
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}