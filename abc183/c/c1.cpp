#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    int n, k;
    cin >> n >> k;
    vector<vector<int>> t(n, vector<int>(n, 0));
    rep(i, n){
        rep(j, n){
            int x;
            cin >> x;
            t[i][j] = x;
        }
    } 
    vector<int> array(n-1);
    rep(i, n-1){
        array[i] = i+1;
    }
    int res=0;
    do{
        int now=0;
        int sum=0;
        rep(i, n-1){
            sum += t[now][array[i]];
            now = array[i];
        }
        sum += t[array[n-2]][0];
        if(sum == k){
            res++;
        }
    }while(next_permutation(array.begin(), array.end()));

    cout << res << endl;
    return 0; 
}