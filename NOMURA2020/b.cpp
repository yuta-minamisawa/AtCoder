#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int s_len = s.size();
    for(int i=s_len-1;i>=0;i--){
        if(s[i]=='?'){
            if(i!=s_len-1){
                if(s[i+1]=='D') s.replace(i, 1, "D");
                else s.replace(i, 1, "D");
            }else{
                s.replace(i, 1, "D");
            }
        }
    }

    cout << s << endl;
    return 0;
}