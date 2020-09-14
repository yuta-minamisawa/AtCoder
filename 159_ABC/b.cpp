#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    bool flag=true;
    rep(i, (n-1)/2){
        if(s[i]!=s[(n-1)/2-1-i]||s[n-1-i]!=s[(n+3)/2-1+i]||s[i]!=s[n-1-i]){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "Yes";
    }else{
        cout << "No";
    }
    cout << endl;
    return 0;
}