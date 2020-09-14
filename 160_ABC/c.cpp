#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int k, n;
    cin >> k >> n;
    int *a = new int[n];
    rep(i, n){
        cin >> a[i];
    }
    int maxim = 0;
    rep(i, n-1){
        maxim = max(maxim, a[i+1]-a[i]);
    }
    maxim = max(maxim, a[0] + k - a[n-1]);
    cout << k - maxim << endl;
    return 0;
}