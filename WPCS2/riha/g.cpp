#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main()
{
    int t;
    cin >> t;
    rep(i, t){
        int n;
        string s;
        cin >> n >> s;
        bool flag=true;
        rep(i, n-3){
            if(s[i]=='2'){
                if(s[i+1]=='5'){
                    if(s[i+2]=='2'){
                        if(s[i+3]=='0'){
                            flag = false;
                            cout << "Yes" << endl;
                            break;
                        }
                    }
                }
            }
        }
        if(flag) cout << "No" << endl;
    }
    return 0;
}