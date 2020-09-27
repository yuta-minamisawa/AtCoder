#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<string> s;
    rep(i, n){
        string x;
        cin >> x;
        s.push_back(x);
    }
    int res=0;
    vector<int> a, b;
    rep(i, n){
        int slen = s[i].size();
        if(s[i][slen-1]=='A'){
            a.push_back(i);
        }
        if(s[i][0]=='B'){
            b.push_back(i);
        }
        rep(j, slen-1){
            if(s[i][j]=='A'&&s[i][j+1]=='B'){
                res++;
            }
        }
    }

    bool flag=true;
    if(a.size()!=b.size()){
        flag = false;
    }else{
        int len = a.size();
        rep(i, len){
            if(a[i]!=b[i]){
                flag = false;
                break;
            }
        }
    }
    if(flag){
        int alen = a.size();
        cout << res + max(0, alen - 1) << endl;
    }else{
        cout << res + min(a.size(), b.size()) << endl;
    }
    return 0;
}