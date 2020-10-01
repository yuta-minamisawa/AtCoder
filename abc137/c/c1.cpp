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
    vector<string> sbox;
    rep(i, n){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        sbox.push_back(s);
    }
    sort(sbox.begin(), sbox.end());

    ll res=0;
    int seq=1;
    rep(i, n-1){
        if(sbox[i]==sbox[i+1]){
            seq++;
        }else{
            if(seq>=2){
                res += seq * (seq - 1LL) / 2LL;
                seq = 1;
            }
        }
    }
    if(seq>=2){
      res += seq * (seq - 1LL) / 2LL;
    }
    cout << res << endl;
    return 0;
}