#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, m;
    cin >> n >> m;
    priority_queue<P> ab;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        ab.push(make_pair(m-a, b));
    }

    int res = 0;
    priority_queue<int> rew;

    for(int i=m-1;i>=0;i--){
        while(!ab.empty()&&ab.top().first==i){
            rew.push(ab.top().second);
            ab.pop();
        }
        if(!rew.empty()){
            res += rew.top();
            rew.pop();
        }
    }
    
    cout << res << endl;
    return 0;
}