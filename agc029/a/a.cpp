#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    string s;
    cin >> s;
    int len = s.size();
    ll cnt = 0, bla = len-1;
    for(int i=len-1;i>=0;i--){
        if(s[i]=='B'){
            cnt += bla - i;
            bla--;
        }
    }
    cout << cnt << endl;
    return 0;
}