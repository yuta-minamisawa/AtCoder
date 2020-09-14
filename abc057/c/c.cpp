#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll n;
    cin >> n;
    for(ll i=sqrt(n);i>=1;i--){
        if(n%i==0){
            ll big = n / i;
            int dig=0;
            while(big){
                dig++;
                big /= 10;
            }
            cout << dig << endl;
            break;
        }
    }
    return 0;
}