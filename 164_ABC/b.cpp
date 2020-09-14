#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while(1){
        c -= b;
        if(c<=0){
            cout << "Yes" << endl;
            break;
        }
        a -= d;
        if(a<=0){
            cout << "No" << endl;
            break;
        }
    }
    return 0;
}