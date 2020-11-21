#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using Pll = pair<ll, ll>;

int main() { 
    int n;
    cin >> n;
    vector<int> p;
    p.resize(n);
    for(auto& x : p) cin >> x;
    int cor = 0;
    rep(i, n){
        if(p[i]==i+1){
            cor++;
        }
    }
    if(cor==n||cor==n-2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0; 
}