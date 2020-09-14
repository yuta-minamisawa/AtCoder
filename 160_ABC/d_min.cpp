#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define INFTY 2001

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> cnt(n, 0);
    x--;
    y--;

    rep(i, n-1){
        rep2(j, i+1, n){
            int a, b;
            a = min(abs(j - i), abs(x - i) + 1 + abs(y - j));
            b = abs(x - j) + 1 + abs(y - i);
            cnt[min(a, b)]++;
        }
    }

    rep2(i, 1, n){
        cout << cnt[i] <<  endl;
    }
    return 0;
}