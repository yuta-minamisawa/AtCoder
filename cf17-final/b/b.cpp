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
    int slen = s.size();
    int a=0, b=0, c=0;
    rep(i, slen){
        if(s[i]=='a'){
            a++;
        }else{
            if(s[i]=='b'){
                b++;
            }else{
                c++;
            }
        }
    }
    if(max(abs(a-b), max(abs(b-c), abs(c-a)))>1){
        cout << "NO";
    }else{
        cout << "YES";
    }
    cout << endl;
    return 0;
}