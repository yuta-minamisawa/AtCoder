#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 2019

int binary_square(int x, int n);

int main(){
    string s;
    cin >> s;
    int s_len = s.length();
    int *dp = new int[s_len+1];
    dp[s_len] = 0;
    rep2(i, 1, s_len+1){
        int a = s[s_len-i] - '0';   //a_i+1
        dp[s_len-i] = (dp[s_len-i+1] + binary_square(10, i-1) * a % MOD) % MOD;
    }
    int cnt=0;
    rep2(i, 0, 2019){
        int m = 0;
        rep(j, s_len+1){
            if(dp[j]==i){
                m++;
            }
        }
        cnt += m * (m-1) / 2;
    }
    cout << cnt << endl;
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