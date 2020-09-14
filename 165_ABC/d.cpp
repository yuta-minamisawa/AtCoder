#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    long a, b, n;
    cin >> a >> b >> n;
    long maxim=-999999, t=a/b;
    if(b-1<=n){
        long x = b-1;
        cout << a*x/b-a*(x/b) << endl;
    }else{
        long x = n;
        cout << a*x/b-a*(x/b) << endl;
    }
    // if(t*b-a>=0){
    //     long x = n / b * b - 1;
    //     long p = a*x/b-a*(x/b), q = a*n/b-a*(n/b);
    //     if(p>q){
    //         cout << p << endl;
    //     }else{
    //         cout << q << endl;
    //     }
    // }else{

    // }
    // rep3(x, b-1, n+1, b){
    //     maxim = max(maxim, t * x - a * (x / b));
    // }
    //cout << maxim << endl;
    return 0;
}