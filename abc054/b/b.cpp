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
    cin >> n >> m;
    vector<string> a, b;
    rep(i, n){
        string s;
        cin >> s;
        a.push_back(s);
    }
    rep(i, m) {
      string s;
      cin >> s;
      b.push_back(s);
    }
    rep(i, n-m+1){
        rep(j, n-m+1){
            bool flag = true;
            rep2(k, i, i+m){
                if(a[k].substr(j, m) != b[k-i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}