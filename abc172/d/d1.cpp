#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll n, sum=0;
    cin >> n;
    vector<ll> cnt(n+1, 0);
    for(ll i=1;i<n+1;i++){
        ll x = i;
        while(x<n+1){
            cnt[x]++;
            x += i;
        }
        sum += i * cnt[i];
    }
    cout << sum << endl;
    return 0;
}