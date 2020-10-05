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
    vector<int> p;
    rep(i, n){
        int x;
        cin >> x;
        p.push_back(x);
    }
    int res = 0;
    rep(i, n-2){
        if(p[i+1]>min(p[i], p[i+2])&&p[i+1]<max(p[i], p[i+2])){
            res++;
        }
    }
    cout << res << endl;
    return 0; 
}