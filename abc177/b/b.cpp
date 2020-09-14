#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    string s, t;
    cin >> s >> t;
    int slen = s.size(), tlen = t.size();

    int res = 0;

    rep(i, slen-tlen+1){
        int tmp=0;
        rep(j, tlen){
            if(s[i+j]==t[j]){
                tmp++;
            }
        }
        res = max(tmp, res);
    }

    cout << tlen - res << endl;
    return 0;
}