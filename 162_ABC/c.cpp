#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int gcd(int a, int b);

int main(){
    int k, sum=0;
    cin >> k;
    rep2(i, 1, k+1){
        rep2(j, 1, k+1){
            rep2(l, 1, k+1){
                sum += gcd(i, gcd(j, l));
            }
        }
    }
    cout << sum << endl;
    return 0;
}

int gcd(int a, int b){
    if(a < b) gcd(b, a);
    int r;
    while (b>0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}