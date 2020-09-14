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
    string s;
    vector<int> num(4, 0);
    rep(i, n){
        cin >> s;
        if(s[0]=='A'){
            num[0]++;
        }
        if (s[0] == 'W') {
          num[1]++;
        }
        if (s[0] == 'T') {
          num[2]++;
        }
        if (s[0] == 'R') {
          num[3]++;
        }
    }

    cout << "AC x " << num[0] << endl;
    cout << "WA x " << num[1] << endl;
    cout << "TLE x " << num[2] << endl;
    cout << "RE x " << num[3] << endl;
    return 0;
}