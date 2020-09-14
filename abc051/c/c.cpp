#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int disx = tx - sx, disy = ty - sy;
    rep(i, disy){
        cout << 'U';
    }
    rep(i, disx){
        cout << 'R';
    }
    rep(i, disy){
        cout << 'D';
    }
    rep(i, disx+1){
        cout << 'L';
    }
    rep(i, disy+1){
        cout << 'U';
    }
    rep(i, disx+1){
        cout << 'R';
    }
    cout << "DR";
    rep(i, disy+1) {
        cout << 'D'; 
    }
    rep(i, disx+1) {
        cout << 'L';
    }
    cout << 'U' << endl;
    return 0;
}