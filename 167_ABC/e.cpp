#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 998244353

long binary_square(long x, long n);
long factorial(long n);
void rfactorial(long n);

vector<long> fact;
vector<long> rfact;

int main(){
    long n, m, k;
    cin >> n >> m >> k;
    rep(i, n){
        fact.push_back(-1);
    }
    factorial(n);
    rfactorial(n);
    long ans=0;
    rep(i, k+1){
        long x;
        long c = (fact[n-1] * rfact[i] % MOD) * rfact[n-1-i] % MOD;
        x = (m * (c * binary_square(m-1, n-i-1) % MOD)) % MOD;
        ans = (ans + x) % MOD;
    }
    cout << ans << endl;
    return 0;
}

long binary_square(long x, long n){
    long m = MOD;
    long ans = 1;
    while(n){
        if(n%2==1){
            ans = ans * x % m;
        }
        x = x * x % m;
        n >>= 1;
    }
    return ans % m;
}

long factorial(long n){
    if(n==0){
        return 1;
    }else{
        if(fact[n-1]==-1){
            fact[n-1] = factorial(n-1);
        }
        fact[n] = n * fact[n-1] % MOD;
        return fact[n];
    }
}

void rfactorial(long n){
    rep(i, n){
        rfact.push_back(binary_square(fact[i], MOD-2));
    }
}