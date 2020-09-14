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
    string s;
    cin >> s;
    int cnt=1;
    rep2(i, 1, n){
        if(s[i-1]!=s[i]){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}