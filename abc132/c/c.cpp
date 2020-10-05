#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    int n;
    cin >> n;
    vector<int> d;
    d.resize(n);
    rep(i, n){
        int x; 
        cin >> x;
        d[i] = x;
    }
    sort(d.begin(), d.end());
    cout << d[n/2] - d[n/2-1] << endl;
    return 0; 
}