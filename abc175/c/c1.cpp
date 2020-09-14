#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll x, k, d;
    cin >> x >> k >> d;
    if(abs(x) / d > k){
        if(x > 0){
            cout << abs(x - k * d) << endl; //3
        }else{
            cout << abs(x + k * d) << endl;
        }
    }else{
        ll step = abs(x) / d;
        if (x > 0) {
            if((k-step)%2){
                cout << abs(x - step * d - d) << endl;  //1
            }else{
                cout << abs(x - step * d) << endl;  //2
            }
        } else {
            if ((k - step) % 2) {
                cout << abs(x + step * d + d) << endl;
            } else {
                cout << abs(x + step * d) << endl;
            }
        }
    }
    return 0;
}