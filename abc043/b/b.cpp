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
    int len = s.size();
    vector<int> res;
    rep(i, len){
        if(s[i]=='0'){
            res.push_back(0);
        }else{
            if(s[i]=='1'){
                res.push_back(1);
            }else{
                if(!res.empty()){
                    res.pop_back();
                }
            }
        }
    }
    int rlen = res.size();
    rep(i, rlen){
        cout << res[i];
    }
    cout << endl;
    return 0;
}