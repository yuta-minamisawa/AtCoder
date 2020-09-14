#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1000000007

int main(){
    int n, k;
    cin >> n >> k;
    vector<long> rui;
    long sum = 0;
    rep(i, n+1){
        sum += i;
        //sum %= MOD;
        rui.push_back(sum);
    }
    long ans=0;
    rep2(i, k, n+1){
        long big, little;
        big = rui[n] - rui[n-i];
        little = rui[i-1];
        ans = ans + big - little + 1 % MOD; 
    }
    ans++;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}