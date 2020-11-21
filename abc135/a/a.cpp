#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using Pll = pair<ll, ll>;

int main() { 
    int a, b;
    cin >> a >> b;
    if(abs(a-b)&1){
        cout << "IMPOSSIBLE" << endl;
    }else{
        if(a>b){
            swap(a, b);
        }
        cout << a + (b-a)/2 << endl;
    }
    return 0; 
}