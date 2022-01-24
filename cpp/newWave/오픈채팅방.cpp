#include <string>
#include <vector>
#include<sstream>
#include<map>
using namespace std;

vector<string> solution(vector<string> record) {
   vector<string> answer;
    vector<string> userId;
    map<string,string> nick;
    stringstream ss; string cmd; string id; string nick_name;
    for(string e: record){
        ss.str(e);
        ss>>cmd;
        if(cmd=="Enter"){
            ss>>id;
            ss>>nick_name;
            userId.push_back(id);
            answer.push_back("´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
            nick[id] =nick_name;
        }
        else if(cmd=="Leave"){
            ss>>id;
            userId.push_back(id);
            answer.push_back("´ÔÀÌ ³ª°¬½À´Ï´Ù.");
        }
        else{
            ss>>id;
            ss>>nick_name;
            nick[id] =nick_name;
        }
        ss.clear();
        
    }
    
    for(int i=0; i<answer.size(); i++){
        answer[i] =nick[userId[i]]+answer[i];
    }
    
    return answer;
}
