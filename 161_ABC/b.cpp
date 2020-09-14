#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int n, m, sum=0;
    cin >> n >> m;
    int *a = new int[n];
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+n);
    if(a[n-m]*4*m<sum){
        cout << "No" <<endl;
    }else{
        cout << "Yes" <<endl;
    }
    return 0;
}