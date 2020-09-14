#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int k;
    string s;
    cin >> k >> s;
    int slen = s.size();
    if(slen<=k){
        cout << s << endl;
    }else{
        rep(i, k){
            cout << s[i];
        }
        cout << "..." <<endl;
    }
    return 0;
}