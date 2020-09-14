#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)
#define MOD INT64_MAX

    int main(){
    int t;
    cin >> t;
    rep(i, t){
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> a;
        rep(j, n){
            int num;
            cin >> num;
            a.push_back(num);
        }
        int minim=0;
        long check = 1 << n;
        vector<int> SUM;
        rep(j, check){
            int cnt=0, sum=0;
            rep(l, n){
                if(j&(1<<l)){
                    cnt++;
                    sum += a[l];
                }
            }
            if(cnt==k){
                SUM.push_back(sum);
            }
        }
        sort(SUM.begin(), SUM.end());
        int sumlen = SUM.size();
        cout << SUM[sumlen-x] << endl;
    }
    return 0;
}
