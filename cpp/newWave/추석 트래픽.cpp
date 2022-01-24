#include<bits/stdc++.h>
#define MIN 60
#define SEC 60
#define MILLISEC 1000
using namespace std;

int solution(vector<string> lines) {
    int ans = 0;
    vector<int> startAt, finishAt;
    for(auto line : lines){
        int hour , minute, second , millisec, time;
        hour = stoi(line.substr(11,2))* MIN * SEC *MILLISEC;
        minute = stoi(line.substr(14,2)) * SEC*MILLISEC;
        second = stoi(line.substr(17,2))*MILLISEC;
        millisec = stoi(line.substr(20, 3));
        
        
        line.pop_back();
        time = stof(line.substr(24))* MILLISEC;
        
          
        startAt.push_back(hour + minute + second + millisec - time + 1);
        finishAt.push_back(hour + minute + second + millisec);
    }
    
    
    for(int i=0; i<finishAt.size(); i++){
        finishAt[i] +=1000;
        int cnt=0;
        
        
        for(int j=i; j<startAt.size(); j++) if(startAt[j] < finishAt[i]) cnt++;
        ans= max(ans,cnt);
    }
    
    
    return ans;
}
