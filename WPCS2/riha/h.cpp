#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main()
{
    int t;
    cin >> t;
    rep(i, t){
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> a;
        rep(j, n){
            int pop;
            cin >> pop;
            a.push_back(pop);
        }
        sort(a.begin(), a.end());
        vector<int> sub;
        rep(j, k){
            sub.push_back(n-1-j);
        }
        rep(j, x-1){
            int chind=k-1;
            int mindis=INT32_MAX;
            rep(l, k-1){
                if(sub[l]-1==sub[l+1]||sub[l]==0) continue;
                int tmp;
                tmp = min(mindis, a[sub[l]]-a[sub[l]-1]);
                if(tmp!=mindis){
                    chind = l;
                    mindis = tmp;
                }
            }
            int tmp;
            tmp = min(mindis, a[sub[k-1]] - a[sub[k-1] - 1]);
            if (tmp != mindis)
            {
                chind = k-1;
            }
            sub[chind]--;
        }
        int sum=0;
        rep(j, k){
            sum += a[sub[j]];
        }
        cout << sum << endl;
    }
    return 0;
}