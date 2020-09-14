#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, k;
    cin >> n >> k;
    rep(i, n){
        int x;
        cin >> x;
    }
    cout << (n - 2) / (k - 1) + 1 << endl;
    return 0;
}