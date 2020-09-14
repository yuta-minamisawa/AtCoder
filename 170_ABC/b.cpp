#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int x, y;
    cin >> x >> y;
    if ((y - 2 * x >= 0 && (y - 2 * x) % 2 == 0) &&
        (4 * x - y >= 0 && (4 * x - y) % 2 == 0)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
      return 0;
}