#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    ll n;
    cin >> n;
    ll three = 3LL, five = 5LL;
    rep(i, 38){
        rep(j, 26){
            if(three+five == n){
                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
            five *= 5LL;
        }
        five = 5LL;
        three *= 3LL;
    }
    cout << -1 << endl;
    return 0; 
}