#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<string, int>;

int main(){
    int n, maxim=0;
    cin >> n;
    map<string, int> mp;
    rep(i, n){
        string s;
        cin >> s;
        if(mp.find(s)!=mp.end()){
            mp[s]++;
        }else{
            mp[s] = 1;
        }
        maxim = max(maxim, mp[s]);
    }
    for (map<string, int>::iterator it = mp.begin(); it != mp.end();it++){
        P item = *it;
        if(item.second==maxim){
            cout << item.first << endl;
        }
    }
    return 0;
}