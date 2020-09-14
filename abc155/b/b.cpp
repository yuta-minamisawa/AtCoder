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
    bool flag=true;
    rep(i, n){
        int a;
        cin >> a;
        if(flag&&a%2==0){
            if(a%3!=0&&a%5!=0){
                flag = false;
            }
        }
    }
    if(flag){
        cout << "APPROVED" << endl;
    }else{
        cout << "DENIED" << endl;
    }
    return 0;
}