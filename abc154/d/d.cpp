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
    int k;
    cin >> n >> k;
    vector<int> p;
    int maxint=0;
    rep(i, n){
        int x;
        cin >> x;
        maxint = max(maxint, x);
        p.push_back(x);
    }
    int sum=0;
    vector<int> total(maxint+1);
    rep2(i, 1, maxint+1){
        sum+=i;
        total[i] = sum;
    }
    cout << fixed << setprecision(12) << endl;
    double maxim=0.0;
    rep(i, k){
        maxim += (double)total[p[i]] / p[i];
    }
    double tmp = maxim;
    rep2(i, 1, n-k+1){
        tmp -= (double)total[p[i-1]] / p[i-1];
        tmp += (double)total[p[i+k-1]] / p[i+k-1];
        maxim = max(tmp, maxim);
    }
    cout << maxim << endl;
    return 0;
}