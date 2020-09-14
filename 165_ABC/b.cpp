#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    long x;
    cin >> x;
    long now=100;
    long cnt=0;
    while(now<x){
        cnt++;
        now += (long)(now * 0.01);
    }
    cout << cnt << endl;
    return 0;
}