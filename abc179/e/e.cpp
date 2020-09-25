#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> tmp(m, 0);
    ll tmpn = n;
    int digit=0;
    while(tmpn>0){
        digit++;
        tmpn>>=1;
    }
    vector<vector<ll>> memo(digit+1, tmp), sum(digit+1, tmp);
    ll res = 0;
    for(ll i=0;i<m;i++){
        memo[0][i] = (i * i) % m;
        sum[0][i] = i;
    }
    rep2(i, 1, digit+1){
        rep(j, m){
            memo[i][j] = memo[i-1][memo[i-1][j]];
            sum[i][j] = sum[i-1][j] + sum[i-1][memo[i-1][j]];
        }
    }
    int nowdig = 0;
    while(n){
        if(n%2LL){
            res += sum[nowdig][x];
            x = memo[nowdig][x];
        }
        n >>= 1;
        nowdig++;
    }
    cout << res << endl;
    return 0;
}