#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    string s, yaki = "YAKI";
    cin >> s;
    string res = "Yes";
    if(s.size()>3){
        rep(i, 4){
            if(s[i]!=yaki[i]){
                res = "No";
                break;
            }
        }
    }else{
        res = "No";
    }
    cout << res << endl;
    return 0;
}