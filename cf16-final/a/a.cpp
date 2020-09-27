#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<string>> s;
    rep(i, h){
        vector<string> tmp;
        rep(j, w){
            string x;
            cin >> x;
            tmp.push_back(x);
        }
        s.push_back(tmp);
    }
    rep(i, h){
        rep(j, w){
            if(s[i][j].size()==5){
                if(s[i][j]=="snuke"){
                    cout << (char)('A'+j) << i+1 << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}