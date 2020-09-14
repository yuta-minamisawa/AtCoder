#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int n;
    cin >> n;
    vector<int> a;
    rep(i, n){
        int height;
        cin >> height;
        a.push_back(height);
    }
    long cnt=0;
    map<long, long> l, r;
    rep(i, n){
        l[a[i]+i+1]++;
        if(i+1-a[i]>=0){
            r[i+1-a[i]]++;
        }
    }
    map<long, long>::iterator L;
    for(L=l.begin(); L != l.end(); L++){
        long item = (*L).first;
        cnt +=  l[item] * r[item];
    }
    cout << cnt << endl;
    return 0;
}