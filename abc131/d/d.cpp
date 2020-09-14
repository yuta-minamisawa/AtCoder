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
    vector<P> ab(n);
    rep(i, n){
        int a, b;
        cin >> a >> b;
        ab[i] = make_pair(b, a);
    }
    sort(ab.begin(), ab.end());
    ll time=0;
    string ans="Yes";
    rep(i, n){
        time += ab[i].second;
        if(time>ab[i].first){
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}