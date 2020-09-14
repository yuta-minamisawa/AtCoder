#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  //queue<int> ok;
  rep(i, n) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());

  int a_max = a[n-1];
  vector<bool> eratos(a_max+1, true);
  int cnt=0;

  rep(i, n){
    int x = a[i], check = x*2;
    while(check<a_max+1){
      eratos[check] = false;
      check += x;
    }
  }

  int seq=1;
  rep(i, n){
    if(eratos[a[i]]){
      cnt++;
    }
    if(i!=0&&a[i-1]==a[i]){
      seq++;
    }else{
      if(seq>1){
        if(eratos[a[i-1]]){
          cnt -= seq;
        }
        seq = 1;
      }
    }
  }

  if(eratos[a[n-1]]&&seq>1){
    cnt -= seq;
  }

  cout << cnt << endl;

  return 0; 
}