#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> left(a.size());
    vector<int> right(a.size());
    
    int MIN =a[0];
    for(int i=0; i<a.size(); i++){
        if(MIN > a[i]) MIN =a[i];
        left[i]= MIN;
    }
    
    MIN = a[a.size()-1];
    for(int i=a.size()-1; i>=0 ; i--){
        if(MIN > a[i]) MIN= a[i];
        right[i] = MIN;
    }
    
    for(int i=0 ; i<a.size(); i++){
        if(a[i] <=left[i] || a[i] <=right[i]) answer++;
    }
    
    return answer;
}
