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
    vector<string> s;
    map<string, ll> sbox;
    s.resize(n);
    for(auto& x : s){
        cin >> x;
    }

    for(auto x : s){
        sort(x.begin(), x.end());
        sbox[x]++;
    }

    ll res=0;
    for(auto [_, ros] : sbox){
        res += ros * (ros - 1) / 2;
    }
    cout << res << endl;
    return 0;
}