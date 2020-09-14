#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

ll n;

int solve();

int main()
{
    cin >> n;
    cout << solve() << endl;
    return 0;
}

int solve(){
    ll res=0;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            ll now=0;
            while(n%i==0){
                now++;
                n/=i;
            }
            ll cnt=1;
            while(cnt<=now){
                now -= cnt;
                cnt++;
                res++;
            }
        }
    }
    if(n!=1) res++;
    return res;
}