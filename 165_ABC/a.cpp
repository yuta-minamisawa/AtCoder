#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int k, a, b, flag=0;
    cin >> k;
    cin >> a >> b;
    //int start = a / k, end = b / k;
    rep2(i, a, b+1){
        if(i%k==0){
            cout << "OK" << endl;
            flag = 1;
            break;
        }
    }
    if(!flag){
        cout << "NG" << endl;
    }
    return 0;
}