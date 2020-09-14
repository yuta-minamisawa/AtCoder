#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int k;
    long answer;
    queue<long> lunlun;
    cin >> k;
    rep2(i, 1, 10){
        lunlun.push(i);
    }
    rep(i, k){
        answer = lunlun.front();
        lunlun.pop();
        if(answer%10==0){
            lunlun.push(answer*10);
            lunlun.push(answer*10+1);
        }else{
            if(answer%10==9){
                lunlun.push(answer*10+8);
                lunlun.push(answer*10+9);
            }else{
                lunlun.push(answer*10 + answer%10 - 1);
                lunlun.push(answer*10 + answer%10);
                lunlun.push(answer*10 + answer%10 + 1);
            }
        }
    }
    cout << answer << endl;
    return 0;
}