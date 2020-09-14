#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1000000007

unsigned long repeat_square(unsigned long x, unsigned long n);

int main(){
    unsigned long n, k;
    unsigned long ans=0;
    cin >> n >> k;
    vector<unsigned long> box;
    rep(i, k){
        box.push_back(0);
    }
    for(unsigned long x=k;x>0;x--){
        unsigned long ans_num;
        ans_num = repeat_square(k/x, n) % MOD;
        rep3(tmp, x<<1, k+1, x){
            if(ans_num - box[tmp-1] > 9223372036854775807)  ans_num += MOD;
            ans_num = (ans_num - box[tmp-1]) % MOD;
        }
        box[x-1] = ans_num;
        ans = (ans + ans_num * x) % MOD; 
    }
    cout << ans << endl;
    return 0;
}

unsigned long repeat_square(unsigned long x, unsigned long n){
    unsigned long ret = 1;
    while(n>0){
        if(n & 1){
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}