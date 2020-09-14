#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

bool dfs(int n_rest, int k, int XOR);

vector<vector<int>> T;
int n;

int main(){
    int k;
    cin >> n >> k;
    rep(i, n){
        vector<int> tmp;
        rep(j, k){
            int t;
            cin >> t;
            tmp.push_back(t);
        }
        T.push_back(tmp);
    }
    if(dfs(n, k, 0)){
        cout << "Found" << endl;
    }else{
        cout << "Nothing" << endl;
    }
    return 0;
}

bool dfs(int n_rest, int k, int XOR){
    if(n_rest==0){
        return XOR==0;
        // if(XOR==0){
        //     return true;
        // }else{
        //     return false;
        // }
    }else{
        bool flag=false;
        rep(i, k){
            // flag = dfs(n_rest-1, k, XOR ^ T[n-n_rest][i]);
            // if(flag){
            //     break;
            // }
            if(dfs(n_rest-1, k, XOR ^ T[n-n_rest][i])) return true;
        }
        return flag;
    }
}