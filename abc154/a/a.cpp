#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    string s, t;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    string u;
    cin >> u;
    if(s==u){
        cout << a-1 << " " << b << endl;
    }else{
        if(t==u){
          cout << a << " " << b-1 << endl;
        }else{
          cout << a << " " << b << endl;
        }
    }
    return 0;
}