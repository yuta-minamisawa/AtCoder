#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    long n, k, mod;
    cin >> n >> k;
    if(n>k){
        mod = n%k;
    }else{
        mod = n;
    }
    cout << min(mod, k-mod) << endl;
    return 0;
}