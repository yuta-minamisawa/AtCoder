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
    vector<int> a, b(n);
    rep(i, n){
        int x;
        cin >> x;
        a.push_back(x);
    }
    int start = n/2;
    b[start] = a[0];
    if(n%2){
        rep2(i, 1, start+1){
            b[start+i] = a[i*2-1];
            b[start-i] = a[i*2];
        }
    }else{
        rep2(i, 1, start){
            b[start-i] = a[i*2-1];
            b[start+i] = a[i*2];
        }
        b[0] = a[n-1];
    }

    rep(i, n){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}