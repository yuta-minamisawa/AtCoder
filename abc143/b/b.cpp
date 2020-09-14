#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<int> d;
    rep(i, n){
        int x;
        cin >> x;
        d.push_back(x);
    }
    int sum=0;
    rep(i, n-1){
        rep2(j, i+1, n){
            sum += d[i] * d[j];
        }
    }
    cout << sum << endl;
    return 0;
}