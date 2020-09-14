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
    ll len = s.size();
    ll res = 2 * (len - 1);
    for(ll i=1;i<len-1;i++){
        if(s[i]=='U'){
            res += 2 * i + (len - i - 1);
        }else{
            res += i + 2 * (len - i - 1);
        }
    }
    cout << res << endl;
    return 0;
}