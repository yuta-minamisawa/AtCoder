#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int t;
    cin >> t;
    rep(i, t){
        string s;
        int k;
        cin >> s >> k;
        int slen = s.size();
        if(k-1<slen){
            cout << s[k-1];
        }else{
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}