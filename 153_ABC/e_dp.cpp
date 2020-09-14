#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int h, n;
    cin >> h >> n;
    vector<int> a, b;
    rep(i, n){
        int A, B;
        cin >> A >> B;
        a.push_back(A);
        b.push_back(B);
    }

    vector<int> dp(h+1, 0);
    dp[0] = 0;

    rep2(i, 1, h+1){
        int mincos=INT32_MAX;
        rep(j, n){
            if(i<=a[j]){
                mincos = min(mincos, b[j]);
            }else{
                mincos = min(mincos, dp[i-a[j]] + b[j]);
            }
        }
        dp[i] = mincos;
    }

    cout << dp[h] << endl;
    return 0;
}