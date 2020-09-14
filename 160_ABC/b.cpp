#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int x;
    cin >> x;
    cout << x / 500 * 1000 + (x%500) / 5 * 5 << endl;
    return 0;
}