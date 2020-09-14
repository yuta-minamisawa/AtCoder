#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int n;
    long odd=0, eve=0;
    long ans;
    cin >> n;
    int *a = new int[n];
    rep(i, n){
        cin >> a[i];
        if(i%2==0){
            eve += a[i];
        }else{
            odd += a[i];
        }
    }
    if(n%2==0){
        ans = max(eve, odd);
        cout << ans << endl;
    }else{

    }
    return 0;
}