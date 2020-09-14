#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll k, a, b;
    cin >> k >> a >> b;
    if(b - a <= 1){
        cout << k + 1 << endl;
    }else{
        if(k<=a){
            cout << k + 1 << endl;
        }else{
            k -= (a - 1);
            if(k%2){
                cout << a + (b - a) * (k / 2) + 1 << endl;
            }else{
                cout << a + (b - a) * (k / 2) << endl;
            }
        }
    }
    return 0;
}