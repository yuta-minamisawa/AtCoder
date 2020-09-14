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
    vector<int> l;
    rep(i, n){
        int x;
        cin >> x;
        l.push_back(x);
    }
    sort(l.begin(), l.end());
    int cnt=0;
    rep(i, n-2){
        rep2(j, i+1, n-1){
            auto it = lower_bound(l.begin(), l.end(), l[i]+l[j]);
            auto pos = distance(l.begin(), it);
            cnt += max(0, (int)(pos) - j - 1);
        }
    }
    cout << cnt << endl;
    return 0;
}