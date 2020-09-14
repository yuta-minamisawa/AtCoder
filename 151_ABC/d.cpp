#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int solve(int now_h, int now_w, int** board, int step);

int h, w;

int main(){
    int answer=-1;
    cin >> h >> w;
    char **s = new char*[h];
    int **state = new int*[h];
    rep(i, h){
        s[i] = new char[w];
        state[i] = new int[w];
    }
    rep(i, h){
        rep(j, w){
            cin >> s[i][j];
            if(s[i][j]=='.'){
                state[i][j] = 0;
            }else{
                state[i][j] = -1;
            }
        }
    }

    rep(i, h){  //START指定
        rep(j, w){
            if(s[i][j]=='.'){
                answer = max(answer, solve(i, j, state, 1));
                rep(k, h){
                    rep(l, w){
                        // cout << state[k][l] << " ";
                        if(state[k][l]!=-1){
                            state[k][l] = 0;
                        }
                    }
                    // cout << endl;
                }
            }
            // cout << answer << endl;
        }
        // cout << endl;
    }

    cout << answer << endl;
    return 0;
}

//now_h, now_wからの最大移動回数 - 1
int solve(int now_h, int now_w, int** board, int step){    
    
    int max_step = step, flag=1;
    int cnt = 1;
    pair<int, int> place;
    queue<pair<int, int>> Q;
    queue<int> cnt_q;
    Q.push(make_pair(now_h, now_w));
    cnt_q.push(cnt+1);
    board[now_h][now_w] = step;

    //移動(右, 上, 左, 下の順)
    while(flag||!Q.empty()){
        cnt = cnt_q.front();
        cnt_q.pop();
        place = Q.front();
        Q.pop();

        now_h = place.first;
        now_w = place.second;

        // cout << now_h << " " << now_w << endl;

        flag = 0;
        //if(board[now_h][now_w]!=0&&!Q.empty()) continue;

        if(now_w!=w-1&&board[now_h][now_w+1]==0){
            //max_step = max(max_step, solve(now_h, now_w+1, board, step+1));
            board[now_h][now_w+1] = cnt;
            Q.push(make_pair(now_h, now_w+1));
            cnt_q.push(cnt+1);
            flag = 1;
        }
        if(now_h!=0&&board[now_h-1][now_w]==0){
            //max_step = max(max_step, solve(now_h-1, now_w, board, step+1));
            board[now_h-1][now_w] = cnt;
            Q.push(make_pair(now_h-1, now_w));
            cnt_q.push(cnt+1);
            flag = 1;
        }
        if(now_w!=0&&board[now_h][now_w-1]==0){
            //max_step = max(max_step, solve(now_h, now_w-1, board, step+1));
            board[now_h][now_w-1] = cnt;
            Q.push(make_pair(now_h, now_w-1));
            cnt_q.push(cnt+1);
            flag = 1;
        }
        if(now_h!=h-1&&board[now_h+1][now_w]==0){
            //max_step = max(max_step, solve(now_h+1, now_w, board, step+1));
            board[now_h+1][now_w] = cnt;
            Q.push(make_pair(now_h+1, now_w));
            cnt_q.push(cnt+1);
            flag = 1;
        }

        cnt++;
    }
    

    return cnt - 3;
}