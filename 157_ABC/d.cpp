#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> fr(n), bl(n), fllist(n);

    rep(i, m){
        int a, b;
        cin >> a >> b;
        fr[a-1].push_back(b-1);
        fr[b-1].push_back(a-1);
    }

    rep(i, k) {
      int a, b;
      cin >> a >> b;
      bl[a - 1].push_back(b - 1);
      bl[b - 1].push_back(a - 1);
    }

    vector<vector<int>> check(n);
    vector<int> tmp(n, 0);

    rep(i, n){
        check[i] = tmp;
    }

    rep(i, n){
        //vector<int> check(n, 0);
        check[i][i] = -1;
        int fr_size = fr[i].size();
        int bl_size = bl[i].size();
        queue<int> fr_list;
        rep(j, fr_size){
            check[i][fr[i][j]] = -1;
            fr_list.push(fr[i][j]);
        }
        //rep(j, bl_size) { check[bl[i][j]] = -1; }

        while(!fr_list.empty()){
            int now = fr_list.front();
            fr_list.pop();

            int now_fr_len = fr[now].size();
            rep(j, now_fr_len){
                if(check[i][fr[now][j]]==0){
                    check[i][fr[now][j]] = 1;
                    check[fr[now][j]][i] = 1;
                    fllist[i].push_back(fr[now][j]);
                    fllist[fr[now][j]].push_back(i);
                    fr_list.push(fr[now][j]);
                }
            }
        }

        rep(j, bl_size) { check[i][bl[i][j]] = -1; }
        // int cnt = 0;
        // rep(j, n){
        //     if(check[i][j]==1){
        //         cnt++;
        //     }
        // }
        cout << fllist[i].size() << " ";
    }
    cout << endl;
    return 0;
}