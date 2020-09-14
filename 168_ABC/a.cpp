#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    int MOD = 10;
    if(n%MOD==3){
        cout << "bon";
    }else{
        if(n%MOD!=0&&((n%2==0&&n%MOD<5)||(n%2==1&&n%MOD>4))){
            cout << "hon";
        }else{
            cout << "pon";
        }
    }
    cout << endl;
    return 0;
}