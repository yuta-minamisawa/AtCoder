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
    int slen = s.size(), tlen = t.size();
    vector<string> predp(tlen+1, ""), nowdp(tlen+1);
    
    rep(i, slen){
        nowdp[0] = "";
        rep2(j, 1, tlen+1){
            if(s[i]==t[j-1]){
                nowdp[j] = predp[j-1] + s[i];
            }else{
                if(nowdp[j-1].size()>=predp[j].size()){
                    nowdp[j] = nowdp[j-1];
                }else{
                    nowdp[j] = predp[j];
                }
            }
        }
        rep2(j, 1, tlen+1){
            predp[j] = nowdp[j];
        }
    }

    cout << nowdp[tlen] << endl;
    return 0;
}