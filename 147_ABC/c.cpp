#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1000000007

// typedef struct _xy{
//     int x;
//     int y;
// } XY;

int n;
vector<vector<int>> C;

int dfs(int check, int honest);
int binary_square(int x, int n);

int main(){
    cin >> n;
    rep(i, n){
        vector<int> tmp;
        rep(j, n){
            tmp.push_back(-1);
        }
        C.push_back(tmp);
    }
    rep(i, n){
        int a;
        cin >> a;
        rep(j, a){
            int x, y;
            cin >> x >> y;
            C[i][x-1] = y;
        }
    }

    stack<int> honest;
    rep(i, n){
        honest.push(i);
    }
    //int maxim = dfs(binary_square(2, n)-1, 0);
    return 0;
}

int dfs(int check, int honest){
    if(check<0){
        return honest;
    }

}

int binary_square(int x, int n){
    int m = MOD;
    int ans = 1;
    while(n){
        if(n%2==1){
            ans = ans * x % m;
        }
        x = x * x % m;
        n >>= 1;
    }
    return ans % m;
}