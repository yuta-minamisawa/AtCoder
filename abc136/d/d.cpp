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
    int slen = s.size();
    vector<int> res(slen, 0);
    bool r = true;
    int rlen = 0, llen = 0, ind;
    rep(i, slen){
        if(r){
            if(s[i]=='L'){
                res[i] += rlen / 2;
                res[i-1] += (rlen+1) / 2;
                ind = i;
                llen = 1;
                r = false;
            }else{
                rlen++;
            }
        }else{
            if(s[i]=='R'){
                res[ind] += (llen+1) / 2;
                res[ind-1] += llen/2;
                rlen = 1;
                r = true;
            }else{
                llen++;
            }
        }
    }

    res[ind] += (llen + 1) / 2;
    res[ind - 1] += llen / 2;

    rep(i, slen){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}