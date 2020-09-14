#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int k, limit=0, cnt=0, flag=1;
    stack<pair<int, int>> lunlun;
    list<int> answer;
    cin >> k;
    while(flag){
        rep2(i, 1, 10){
            lunlun.push(make_pair(i, limit));
            int answer_dig=limit+1;
            while(!lunlun.empty()){
                int num = lunlun.top().first;
                int depth = lunlun.top().second;
                lunlun.pop();
                if(depth==0){
                    cnt++;
                    //cout << cnt << endl;
                }

                rep(j, depth-answer_dig+1){
                    answer.pop_back();
                }
                answer.push_back(num);
                answer_dig = depth;

                if(cnt==k){
                    int size = answer.size();
                    rep(j, size){
                        cout << answer.front();
                        answer.pop_front();
                    }
                    cout <<  endl;
                    flag = 0;
                    break;
                }else{
                    if(depth!=0){
                        if(num==0){
                            lunlun.push(make_pair(1, depth-1));
                            lunlun.push(make_pair(0, depth-1));
                        }else{
                            if(num==9){
                                lunlun.push(make_pair(9, depth-1));
                                lunlun.push(make_pair(8, depth-1));
                            }else{
                                lunlun.push(make_pair(num+1, depth-1));
                                lunlun.push(make_pair(num, depth-1));
                                lunlun.push(make_pair(num-1, depth-1));
                            }
                        }
                    }
                }
            }
            answer.clear();
            if(flag==0){
                break;
            }
        }
        limit++;
    }
}