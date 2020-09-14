#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<int> a;
    queue<int> ok;
    rep(i, n){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    rep(i, n){
        ok.push(a[i]);
    }
    // ok.push(0);
    
    int cnt = 0;
    //vector<bool> check(n, true);

    // int a_len = a.size();
    while(!ok.empty()){
        // if(!check[i]){
        //     continue;
        // }
        cnt++;
        int boss = ok.front();
        ok.pop();
        // if(boss==0){
        //     break;
        // }
        bool flag=false;
        queue<int> tmp;
        //tmp.push(boss);
        while (!ok.empty()) {
          int test = ok.front();
          ok.pop();
          // if(test==0){
          //     tmp.push(0);
          //     break;
          // }
          if (test % boss == 0) {
            // check[j] = false;
            // a.erase(a.begin() + j);
            // a_len--;
            if (boss == test) {
              //cnt--;
              // check[i] = false;
              flag = true;
            }
            // j--;
          }else{
              tmp.push(test);
          }
        }

        while(!tmp.empty()){
            ok.push(tmp.front());
            tmp.pop();
        }
        if(flag){
            cnt--;
        //   a.erase(a.begin() + i);
        //   a_len--;
        //   i--;
        }
    }

    // rep(i, n){
    //     if(check[i]){
    //         cnt ++;
    //     }
    // }

    cout << cnt << endl;
    return 0;
}