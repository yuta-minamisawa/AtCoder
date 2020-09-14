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
    ll sum=0, lcnt=0, rcnt=0;
    bool lflag = true;
    int n = s.size();
    rep(i, n){
        if(lflag){
            if(s[i]=='<'){
                lcnt++;
            }else{
                lflag = false;
            }
        }
        if(!lflag){
            if(s[i]=='>'){
                rcnt++;
            }else{
                ll big = max(lcnt, rcnt);
                ll small = min(lcnt, rcnt);
                sum += (big * (big + 1) + small * (small - 1)) / 2;
                lcnt = 1;
                rcnt = 0;
                lflag = true;
            }
        }
    }
    ll big = max(lcnt, rcnt);
    ll small = min(lcnt, rcnt);
    sum += (big * (big + 1) + small * (small - 1)) / 2;
    cout << sum << endl;
    return 0;
}