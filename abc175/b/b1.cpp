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
    vector<ll> l;
    rep(i, n){
        ll x;
        cin >> x;
        l.push_back(x);
    }

    int cnt = 0;
    rep(i, n-2){
        rep2(j, i+1, n-1){
            if(l[i]==l[j]){
                continue;
            }
            rep2(k, j+1, n){
                if(l[i]==l[k]||l[j]==l[k]){
                    continue;
                }
                int sum = l[i] + l[j] + l[k], maxim = max(l[i], max(l[j], l[k]));
                if(maxim < sum - maxim){
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}