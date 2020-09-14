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
    vector<int> a;
    rep(i, n){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    string ans = "YES";
    rep(i, n-1){
        if(a[i]==a[i+1]){
            ans = "NO";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}