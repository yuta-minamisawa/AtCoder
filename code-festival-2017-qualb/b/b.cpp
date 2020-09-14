#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, m;
    cin >> n;
    map<int, int> d;
    rep(i, n){
        int x;
        cin >> x;
        d[x]++;
    }
    cin >> m;
    vector<int> t;
    rep(i, n) {
      int x;
      cin >> x;
      t.push_back(x);
    }
    string ans = "YES";
    rep(i, m){
        if(d[t[i]]==0){
            ans = "NO";
            break;
        }
        d[t[i]]--;
    }
    cout << ans << endl;
    return 0;
}