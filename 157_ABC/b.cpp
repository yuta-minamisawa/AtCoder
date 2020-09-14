#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    vector<vector<int>> a;
    vector<vector<bool>> check;

    vector<int> tmp(3);
    vector<bool> tmpc(3, false);
    rep(i, 3){
        rep(j, 3){
            int num;
            cin >> num;
            tmp[j] = num;
        }
        a.push_back(tmp);
        check.push_back(tmpc);
    }

    int n;
    cin >> n;

    rep(i, n){
        int b;
        cin >> b;
        rep(j, 3){
            rep(k, 3){
                if(!check[j][k]&&a[j][k]==b){
                    check[j][k] = true;
                }
            }
        }
    }

    string ans = "No";

    rep(i, 3){
        if(check[i][0]&&check[i][1]&&check[i][2]){
            ans = "Yes";
        }
    }

    rep(i, 3) {
      if (check[0][i] && check[1][i] && check[2][i]) {
        ans = "Yes";
      }
    }

    if (check[0][2] && check[1][1] && check[2][0]) {
      ans = "Yes";
    }

    if (check[0][0] && check[1][1] && check[2][2]) {
      ans = "Yes";
    }

    cout << ans << endl;
    return 0;
}