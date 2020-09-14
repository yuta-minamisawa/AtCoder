#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

void dfs(int rest, string s);

int main(){
    int n;
    cin >> n;
    dfs(n, "");
    return 0;
}

void dfs(int rest, string s){
    if(rest==0){
        cout << s << endl;
    }else{
        for(char c = 'a';c<='c';c++){
            dfs(rest-1, s + c);
        }
    }
}