#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll x;
    cin >> x;
    ll cnt=1, sum=0;
    while(1){
        sum += cnt;
        if(sum >= x){
            cout << cnt << endl;
            break;
        }
        cnt++;
    }
    return 0;
}