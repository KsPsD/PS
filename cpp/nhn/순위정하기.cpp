#include<bits/stdc++.h>


using namespace std;
using namespace std;

unordered_map<string, vector<int> > scores;
string s[4], num;

void getCombi(int num) {
    for(int i = 0; i < 16; i++) {
        string tmp = "";
        
        for(int j = 0; j < 4; j++) {
            if(i & (1 << j)) tmp.push_back('-');
            else tmp += s[j];
        }
    
        scores[tmp].push_back(num);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(auto &i : info) {
        stringstream ss(i);
        ss >> s[0] >> s[1] >> s[2] >> s[3] >> num;
        getCombi(stoi(num));
    }
    
    for(auto &s : scores) {
    	sort(s.second.begin(), s.second.end());
    }
    
    for(auto &q : query) {
        int score;
        stringstream ss(q);
        ss >> s[0] >> num >> s[1] >> num >> s[2] >> num >> s[3] >> num;
        score = stoi(num);
        
        vector<int> v = scores[s[0] + s[1] + s[2] + s[3]];
        if(v.size() != 0) {
            auto it = lower_bound(v.begin(), v.end(), score);
            answer.push_back(v.size() - (it - v.begin()));
        } else answer.push_back(0);
    }
    
    return answer;
}
