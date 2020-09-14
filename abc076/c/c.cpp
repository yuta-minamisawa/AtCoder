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
    int slen = s.size(), tlen = t.size(), check=-1;
    rep(i,slen-tlen+1){
        bool flag=true;
        rep2(j, i, i+tlen){
            if(s[j]!='?'&&s[j]!=t[j-i]){
                flag = false;
                break;
            }
        }
        if(flag){
            check=i;
        }
    }
    if(check==-1){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    rep(i, slen){
        if(s[i]!='?'){
            cout << s[i];
        }else{
            if(check<=i&&i<check+tlen){
                cout << t[i-check];
            }else{
                cout << 'a';
            }
        }
    }
    cout << endl;
    return 0;
}