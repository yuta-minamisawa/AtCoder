#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int h, w, m, colmax=0, rowmax=0;
    cin >> h >> w >> m;
    vector<int> col(h, 0), row(w, 0);
    set<int> tmph, tmpw;
    vector<set<int>> collist(h, tmph), rowlist(w, tmpw);
    rep(i, m){
        int x, y;
        cin >> x >> y;
        col[x-1]++;
        row[y-1]++;
        colmax = max(colmax, col[x-1]);
        rowmax = max(rowmax, row[y-1]);
        collist[x-1].insert(y-1);
        rowlist[y-1].insert(x-1);
    }
    vector<int> cind, rind;
    vector<set<int>> cmax, rmax;
    rep(i, h){
        if(col[i]==colmax){
            cind.push_back(i);
            cmax.push_back(collist[i]);    
        }
    }
    rep(i, w){
        if(row[i]==rowmax){
            rind.push_back(i);
            rmax.push_back(rowlist[i]);
        }
    }
    int dis=1;
    int clen=cmax.size(), rlen=rmax.size();
    rep(i, clen){
        rep(j, rlen){
            if(cmax[i].count(rind[j])==0){
                dis = 0;
                break;
            }
        }
        if(dis==0){
            break;
        }
    }
    cout << colmax + rowmax - dis << endl;
    return 0;
}