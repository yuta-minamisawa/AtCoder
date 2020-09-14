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
    vector<int> a, b;
    vector<int> tmp;
    map<int,  int> tmp3;
    vector<vector<int>> list(n+1, tmp);
    vector<map<int, int>> color(n+1, tmp3);
    rep(i, n - 1) {
      int x, y;
      cin >> x >> y;
      a.push_back(x);
      b.push_back(y);
      list[a[i]].push_back(b[i]);
      list[b[i]].push_back(a[i]);
    }
    int maximcolor=0;
    rep2(i, 1, n+1){
        int size = list[i].size();
        maximcolor = max(maximcolor, size);
    }
    cout << maximcolor << endl;
    queue<int> tyoten;
    int nowcolor = 0;
    int now = 1;
    while(1){
        int len = list[now].size();
        int dis = 0;
        rep(i, len){
            if(now<list[now][i]){
                tyoten.push(list[now][i]);
                if (i+1+dis == nowcolor) {
                    dis++;
                }
                color[now][list[now][i]] = i + 1 + dis;
                color[list[now][i]][list[now][i]] = i + 1 + dis;
            }else{
                dis--;
            }
        }
        if(tyoten.empty()){
            break;
        }
        now = tyoten.front();
        tyoten.pop();
        nowcolor = color[now][now];
    }
    rep(i, n-1){
        cout << color[a[i]][b[i]] << endl;
    }
    return 0;
}