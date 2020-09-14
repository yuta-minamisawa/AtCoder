#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    long a, b, c, k;
    cin >> a >> b >> c >> k;
    long A = min(k, a);
    long B = min(k-A, b);
    long C = k-A-B;
    cout << A - C << endl;
    // if(a>=k){
    //     cout << k << endl;
    // }else{
    //     k -= a;
    //     if(b>=k){
    //         cout << a << endl;
    //     }else{
    //         cout << a - k + b << endl;
    //     }
    // }
    return 0;
}