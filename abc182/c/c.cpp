#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    string n;
    cin >> n;
    int nlen = n.size(), res=-1;

    rep2(i, 1, 1<<nlen){
        int sum = 0;
        rep(j, nlen){
            if((i>>j) & 1){
                sum += n[j] - '0';
                // cout << sum << endl;
            }
        }
        if(sum%3==0){
            // cout << i << " " << sum << endl;
            res = max(res, __builtin_popcount(i));
        }
    }

    if(res == -1){
        cout << res << endl;
    }else{
        cout << nlen - res << endl;
    }
    return 0; 
}