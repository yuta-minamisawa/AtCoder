#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int a[3];
    rep(i, 3){
        int x;
        cin >> x;
        a[i] = x;
    }
    string ans = "No";
    if(a[0]==a[1]&&a[0]!=a[2]){
        ans = "Yes";
    }
    if (a[2] == a[1] && a[0] != a[2]) {
      ans = "Yes";
    }
    if (a[0] == a[2] && a[0] != a[1]) {
      ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}