#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int n;
    long sum=0;
    cin >> n;
    rep(i, n+1){
        if(i%3!=0&&i%5!=0){
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}