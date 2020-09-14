#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int MOD;

int main(){
    int n;
    cin >> n >> MOD;
    string s;
    cin >> s;
    rep(i)
    return 0;
}

int binary_square(int x, int n){
    int m = MOD;
    int ans = 1;
    while(n){
        if(n%2==1){
            ans = ans * x % m;
        }
        x = x * x % m;
        n >>= 1;
    }
    return ans % m;
}