#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int dw_box[4] = {1, 0, -1, 0};
int dh_box[4] = {0, -1, 0, 1};

vector<vector<int>> minim;
int h, w;
int dh, dw;

bool isvalid(int H, int W, int cost) {
  return H >= 0 && H < h && W >= 0 && W < w && minim[H][W] != -1 && cost < minim[H][W];
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

    minim[ch][cw] = 0;
    deque<P> dq;
    dq.push_front(make_pair(ch, cw));


    while(!dq.empty()){
        P now = dq.front();
        dq.pop_front();

        rep(i, 4){
            int H = now.first + dh_box[i], W = now.second + dw_box[i];
            if(isvalid(H, W, minim[now.first][now.second])){
                P p = make_pair(H, W);
                minim[H][W] = minim[now.first][now.second];
                dq.push_front(p);
            }
        }

        rep2(i, -2, 3){
            rep2(j, -2, 3){
                int H = now.first + i, W = now.second + j;
                if (isvalid(H, W, minim[now.first][now.second] + 1)) {
                    P p = make_pair(H, W);
                    minim[H][W] = minim[now.first][now.second] + 1;
                    dq.push_back(p);
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