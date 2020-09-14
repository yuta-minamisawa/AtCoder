#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, cnt=0;
    cin >> n;
    double d;
    cin >> d;
    rep(i, n){
        double x, y;
        cin >> x >> y;
        if(sqrt(x*x+y*y)<=d){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}