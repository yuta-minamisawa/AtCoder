#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1e9+7

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<ll> cnt(n+1, 1);
    rep2(i, 2, n+1){
        int num = i;
        for (int j = 2; j * j <= i; j++) {
            while(num%j==0){
				cnt[j]++;
				num /= j;
			}
			if(num==1){
				break;
			}
        }
		if(num!=1){
			cnt[num]++;
		}
    }

	ll sum=1ll;
	rep2(i, 2, n+1){
        sum = lldiv(sum * cnt[i], MOD).rem;
	}

	cout << sum << endl;
    return 0;
}