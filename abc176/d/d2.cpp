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

vector<vector<int>> minim;
int h, w;
int dh, dw;
bool finish=false;
set<P> p;

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

    point p;
    p.h = ch;
    p.w = cw;
    p.warp = 0;
    minim[p.h][p.w] = p.warp;

    priority_queue< point, vector<point>, greater<point> > pq;
    pq.push(p);

    while(!pq.empty()){
        point now = pq.top();
        pq.pop();
        if (now.w != w - 1 && minim[now.h][now.w + 1] != -1 &&
            now.warp < minim[now.h][now.w + 1]) {
          p.h = now.h;
          p.w = now.w + 1;
          p.warp = now.warp;
          minim[p.h][p.w] = p.warp;
          pq.push(p);
        }
        if (now.h != 0 && minim[now.h - 1][now.w] != -1 &&
            now.warp < minim[now.h - 1][now.w]) {
          p.h = now.h - 1;
          p.w = now.w;
          p.warp = now.warp;
          minim[p.h][p.w] = p.warp;
          pq.push(p);
        }
        if (now.w != 0 && minim[now.h][now.w - 1] != -1 &&
            now.warp < minim[now.h][now.w - 1]) {
          p.h = now.h;
          p.w = now.w - 1;
          p.warp = now.warp;
          minim[p.h][p.w] = p.warp;
          pq.push(p);
        }
        if (now.h != h - 1 && minim[now.h + 1][now.w] != -1 &&
            now.warp < minim[now.h + 1][now.w]) {
          p.h = now.h + 1;
          p.w = now.w;
          p.warp = now.warp;
          minim[p.h][p.w] = p.warp;
          pq.push(p);
        }

        rep2(i, max(0, now.h-2), min(h, now.h+3)){
            rep2(j, max(0, now.w-2), min(w, now.w+3)){
                if(minim[i][j]!=-1&&now.warp+1<minim[i][j]){
                    p.h = i;
                    p.w = j;
                    p.warp = now.warp + 1;
                    minim[p.h][p.w] = p.warp;
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