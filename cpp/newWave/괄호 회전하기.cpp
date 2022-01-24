#include<bits/stdc++.h>

using namespace std;

bool check(string  & s){
    stack<char> st;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == ']' or s[i] ==')' or s[i] =='}'){
            if(s[i] ==']'){
                if(st.top() != '['){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else if(s[i] ==')'){
                if(st.top() != '('){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else if(s[i]=='}'){
                 if(st.top() != '{'){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        else{
            st.push(s[i]);
        }
    }
    
    return true;
}


int solution(string s) {
    int answer = -1;
    int cnt=0;
    if(s.size()  %2 ==1) return 0;
    for(int i=0; i<s.size(); i++){
        rotate(s.begin(), s.begin() + 1, s.end());
        if(check(s)) cnt++;
    }
    answer= cnt;
    return answer;
}
