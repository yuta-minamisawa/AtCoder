#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

typedef tuple<int, int> mytuple;

// bool mycompare( const mytuple &lhs, const mytuple &rhs )
// {
//     if (std::get<0>(lhs) != std::get<0>(rhs)) return std::get<0>(lhs) < std::get<0>(rhs);
//     if (std::get<1>(lhs) != std::get<1>(rhs)) return std::get<1>(lhs) < std::get<1>(rhs);
//     return std::get<2>(lhs) < std::get<2>(rhs);
// }

int main(){
    int n;
    cin >> n;
    vector<int> a;
    vector<bool> check;
    vector<vector<mytuple>> all_happy;
    vector<mytuple> max_happy;
    rep(i, n){
        int act;
        cin >> act;
        a.push_back(act);
        check.push_back(0);
    }
    rep(i, n){
        int happy=0;
        int a_happy = a[i];
        for(int j=i;j>=0;j--){
            max_happy.push_back(make_tuple(happy, j));
            happy += a_happy;
        }
        //max_happy.push_back(make_tupple(0, i));
        happy = a_happy;
        rep2(j, i+1, n){
            max_happy.push_back(make_tuple(happy, j));
            happy += a_happy;
        }
        //sort(max_happy.begin(), max_happy.end());
        sort(begin(max_happy), end(max_happy));
        // rep(j, n){
        //     cout << get<0>(max_happy[j]) << "\t";
        // }
        // cout << endl;
        all_happy.push_back(max_happy);
        max_happy.clear();
    }

    long ans=0;

    rep(i, n){
        int maxim=-1, ind=-1;
        rep(j, n){
            int now=get<1>(*(all_happy[j].end()));
            if(check[now]==1){
                all_happy[j].pop_back();
                j--;
                continue;
            }else{
                cout << get<0>(*(all_happy[j].end())) << endl;
                int tmpmax = max(maxim, get<0>(*(all_happy[j].end())));
                cout << "tmpmax = " << tmpmax << endl;
                if(tmpmax!=maxim){
                    maxim = tmpmax;
                    ind = now;
                }
            }
        }
        //cout << ind << endl;
        ans += maxim;
        cout << ind << " : " << ans << endl;
        check[ind] = 1;
    }

    cout << ans << endl;
    return 0;
}