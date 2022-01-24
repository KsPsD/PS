#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int ,vector<int> , greater<int> > pq(scoville.begin(), scoville.end());
    while(pq.top() < K){
        int first= pq.top();
        pq.pop();
        int second= pq.top();
        pq.pop();
        int new_e= first+ (second*2);
        pq.push(new_e);
        if(pq.size() <2){
            int one_thing = pq.top();
            if(one_thing < K) {
                answer=-1;
                break;
            }
        }
        answer++;
    }
    
    return answer;
}
