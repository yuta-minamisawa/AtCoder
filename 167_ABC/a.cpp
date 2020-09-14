#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    string s, t;
    cin >> s >> t;
    t.pop_back();
    // if(s+t[t.size()-1]==t){
    //     cout << "Yes";
    // }else{
    //     cout << "No";
    // }
    if(s==t) cout << "Yes";
    else cout << "No";
    cout << endl;
    return 0;
}