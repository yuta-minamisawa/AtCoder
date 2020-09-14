#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> win(n, 0);
    rep(i, q){
        int a;
        cin >> a;
        win[a-1]++;
    }
    rep(i, n){
        if(k>q-win[i]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}