#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h){
        string x;
        cin >> x;
        s[i] = x;
    }
    int res=0;
    rep(i, h){
        rep(j, w-1){
            if(s[i][j]==s[i][j+1]&&s[i][j]=='.'){
                res++;
            }
        }
    }

    rep(i, w){
        rep(j, h-1){
            if(s[j][i]==s[j+1][i]&&s[j][i]=='.'){
                res++;
            }
        }
    }

    cout << res << endl;
    return 0; 
}