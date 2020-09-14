#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int n;
    cin >> n;
    vector<int> a;
    vector<long> sum;
    rep(i, n){
        int num;
        cin >> num;
        a.push_back(num);
    }
    sum.push_back(0);
    long total=0;
    long minim=0, maxim=0;
    rep(i, n){
        total += a[i];
        sum.push_back(total);
        minim = min(minim, total);
        maxim = max(maxim, total);
    }
    sort(sum.begin(), sum.end());
    long cnt=0, set=sum[0], seq=1;
    rep2(i, 1, n+1){
        if(set==sum[i]){
            seq++;
        }else{
            cnt += seq * (seq - 1) / 2;
            set = sum[i];
            seq = 1;
        }
    }
    cnt += seq * (seq - 1) / 2;
    cout << cnt << endl;
    return 0;
}