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
    vector<int> two(3, 0);
    rep(i, n){
        int a, twonum=0;
        cin >> a;
        rep(j, 2){
            if(a%2==0){
                ++twonum;
            }else{
                break;
            }
            a /= 2;
        }
        ++two[twonum];
    }
    string ans = "Yes";
    if (two[2] < two[0]) {
      if (two[2] + two[0] != n || two[0] - two[2] != 1) {
        ans = "No";
      }
    }
    cout << ans << endl;
    return 0;
}