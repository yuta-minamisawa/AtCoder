#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int dfs(int last, int depth, vector<int>&nowa);

int n, m, q;
vector<int> a, b, c, d;

int main(){
    cin >> n >> m >> q;
    rep(i, q){
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        a.push_back(A);
        b.push_back(B);
        c.push_back(C);
        d.push_back(D);
    }

    int maxim=0;
    rep(i, n){
        vector<int> nowa;
        nowa.push_back(i+1);
        int score = dfs(i+1, 0, nowa);
        maxim = max(maxim, score);
    }
    cout << maxim << endl;
    return 0;
}

int dfs(int last, int depth, vector<int>&nowa){
    int maxim=0, score=0;
    if(depth==n){
        rep(i, q){
            if(nowa[b[i]-1]-nowa[a[i]-1]==c[i]){
                score += d[i];
            }
        }
        return score;
    }else{
        rep2(i, last, m+1){
            nowa.push_back(i);
            score = dfs(i, depth+1, nowa);
            nowa.pop_back();
            maxim = max(maxim, score);
        }
        return maxim;
    }
}