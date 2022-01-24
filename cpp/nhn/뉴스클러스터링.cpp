#include <bits/stdc++.h>

using namespace std;
const int val=65536;

int solution(string str1, string str2){
	int answer=0;
	transform(str1.begin(), str1.end(),str1.begin() ,::tolower);
	transform(str2.begin() , str2.end(), str2.begin(), ::tolower);
	
	
	
	unordered_map<string, int> ma;
	unordered_map<string,int> mb;
	
	
	unordered_set<string> strset;
	
	
	string tmp;
	
	
	
	for(int i=0; i<str1.length()-1; i++){
		if(isalpha(str1[i]) && isalpha(str1[i+1])){
			tmp=str1.substr(i,2);
			ma[tmp]++;
			strset.insert(tmp);
		}
	}
	
	for(int i=0; i<str2.length()-1; i++){
		if(isalpha(str2[i]) && isalpha(str2[i+1])){
			tmp=str2.substr(i,2);
			mb[tmp]++;
			strset.insert(tmp);
		}
	}
	
	int intersect=0;
	int uni=0;
	
	
	for(auto e:strset){
		intersect+=min(ma[e],mb[e]);
		uni+=max(ma[e],mb[e]);
	}
	
	if(intersect==0&& uni==0) return val;
	
	answer=val*intersect/uni;
	return answer;
	
	

	
	
}



int main(){
	
	solution("abcdef","asdfvb");
	
	
	
	
	
	
	
	
	
	return 0;
}
