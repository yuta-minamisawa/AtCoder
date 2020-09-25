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
    vector<ll> tmp;
    vector<vector<ll>> ind(26, tmp);
    ll slen = s.size(), tlen = t.size();
    rep(i, slen){
        ind[s[i]-'a'].push_back(i+1);
    }
    ll res=0;
    rep(i, tlen){
        int now = res % slen;
        if(ind[t[i]-'a'].empty()){
            res = -1;
            break;
        }
        auto it = upper_bound(ind[t[i]-'a'].begin(), ind[t[i]-'a'].end(), now);
        if(it!=ind[t[i]-'a'].end()){
            res += *it - now;
        }else{
            res += slen - now;
            res += ind[t[i]-'a'][0];
        }
    }
    cout << res << endl;
    return 0;
}