#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int k;
    cin >> k;
    int ten=7, now=ten%k;
    bool flag=true;
    rep(i, k){
        // cout << now << endl;
        if(now==0){
            cout << i+1 << endl;
            flag=false;
            break;
        }else{
            ten = ten * 10 % k;
            now = (now + ten) % k;
        }
    }
    if(flag){
        cout << -1 << endl;
    }
    return 0;
}