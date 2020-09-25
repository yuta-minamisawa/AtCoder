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
    map<ll, ll> a;
    rep(i, n){
        int x;
        cin >> x;
        a[x]++;
    }
    vector<ll> maxim;
    for(const auto& [key, value] : a){
        if(value>=2){
            maxim.push_back(key);
        }
    }
    ll mlen = maxim.size();
    if(mlen<2){
        cout << 0 << endl;
    }else{
        sort(maxim.begin(), maxim.end());
        if(a[maxim[mlen-1]]>=4){
            cout << maxim[mlen - 1] * maxim[mlen - 1] << endl;
        }else{
            cout << maxim[mlen - 1] * maxim[mlen - 2] << endl;
        }
    }
    return 0;
}