#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int n, k;
    cin >> n >> k;
    vector<bool> check;
    rep(i, n){
        check.push_back(false);
    }
    rep(i, k){
        int d;
        cin >> d;
        rep(j, d){
            int a;
            cin >> a;
            check[a-1] = true;
        }
    }
    //cout << "OK";
    int cnt = 0;
    rep(i, n){
        if(!check[i]){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}