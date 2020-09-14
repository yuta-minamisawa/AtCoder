#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    bool flag=false;
    rep2(i, 1, 10){
        rep2(j, 1, 10){
            if(i*j==n){
                cout << "Yes" << endl;
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    if(!flag){
        cout << "No" << endl;
    }
    return 0;
}