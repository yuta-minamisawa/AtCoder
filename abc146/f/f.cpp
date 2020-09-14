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
    string youbi[7] = {"SAT", "FRI", "THU", "WED", "TUE", "MON", "SUN"};
    rep(i, 7){
        if(youbi[i]==s){
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}