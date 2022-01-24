#include <bits/stdc++.h>

using namespace std;


bool ch[51];
int dfs(string &s ,int idx){
	
	int cnt=0;
	
	for(int i=idx; i<s.size(); i++){
		if(s[i] =='(' && !ch[i]){
			ch[i] =true;
			int num = s[i-1] - '0';
			cnt--;
			cnt+=num*dfs(s,i+1);
		}
		else if(s[i] ==')' && !ch[i]){
			ch[i]=true;
			return cnt;
		}
		else if(!ch[i]){
			ch[i] =true;
			cnt++;
		}
			
	}
	
	return cnt;
	
}



int main(){
	
	
	string s;cin>>s;
	
	cout<<dfs(s,0)<<endl;
	
	
	
	
	
	
	
	
	
	return 0;
} 
