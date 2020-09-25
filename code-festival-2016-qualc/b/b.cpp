#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int k, t;
    cin >> k >> t;
    vector<int> a;
    rep(i, t){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int maxim = a[t-1];
    cout << max(0, 2*maxim-k-1) << endl;
    return 0;
}