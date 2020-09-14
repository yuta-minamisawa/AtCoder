#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    string n;
    cin >> n;
    if(n[0]=='7'||n[1]=='7'||n[2]=='7'){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}