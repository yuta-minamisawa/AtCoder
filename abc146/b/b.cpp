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
    cin >> s;
    int len = s.size();
    rep(i, len){
        int alnum = s[i] - 'A';
        int newnum = (alnum + n) % 26;
        cout << (char)('A' + newnum);
    }
    cout << endl;
    return 0;
}