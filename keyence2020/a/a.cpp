#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    if(h<w){
        cout << (n-1) / w + 1 << endl;
    }else{
        cout << (n - 1) / h + 1 << endl;
    }
    return 0;
}