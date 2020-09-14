#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

typedef struct {
    int h;
    int w;
    int warp;
} point;

bool operator>(const point &student1, const point &student2) {
  return student1.warp > student2.warp;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> minim;
int h, w;
int dh, dw;

bool isvalid(int x, int y, int cost) {
  return x >= 0 && x < w && y >= 0 && y < h && minim[y][x] != -1 && cost < minim[y][x];
}

int main(){
    cin >> h >> w;
    int ch, cw;
    cin >> ch >> cw;
    ch--;
    cw--;
    cin >> dh >> dw;
    dh--;
    dw--;
    rep(i, h){
        string x;
        cin >> x;
        vector<int> tmpa(w, INT32_MAX);
        rep(j, w){
            if(x[j]=='#'){
                tmpa[j] = -1;
            }
        }
        minim.push_back(tmpa);
    }

    point p = {ch, cw, 0};
    minim[p.h][p.w] = p.warp;

    priority_queue< point, vector<point>, greater<point> > pq;
    pq.push(p);

    while(!pq.empty()){
        point now = pq.top();
        pq.pop();

        rep(i, 4){
            int x = now.w + dx[i], y = now.h + dy[i];
            if(isvalid(x, y, now.warp)){
                p = {y, x, now.warp};
                minim[y][x] = now.warp;
                pq.push(p);
            }
        }

        rep2(i, -2, 3){
            rep2(j, -2, 3){
                int x = now.w + j, y = now.h + i;
                if(isvalid(x, y, now.warp+1)){
                    p = {y, x, now.warp+1};
                    minim[y][x] = now.warp+1;
                    pq.push(p);
                }
            }
        }
    }

    if(minim[dh][dw]==INT32_MAX){
        minim[dh][dw] = -1;
    }
    cout << minim[dh][dw] << endl;
    return 0;
}